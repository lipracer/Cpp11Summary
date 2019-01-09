1.新增关键字、新增语法
1.1 新增宏__func__定义。
对应函数名字的宏定义。

1.2 类型推导auto、decltype




1.3 long long类型
标准有符号整形包括：signed char、short int、int、long int、long long int，其他类型均为编译器定义（非标准，隐式转换时非标准等级小于标准类型等级，有符号小于无符号）

long long int ln = 100LL;
unsigned long long int uln = 100ULL;
printf("%lld %llu\n", ln, uln);

1.4 静态断言
static_assert(bool, "cstr");相对于assert，assert的功能是运行时期条件为false将调用terminate函数，终止程序运行，静态断言发生在编译时期。

1.5 nullptr
NULL实际上是#define NULL 0宏定义，在nullptr出现之前，函数发生重载时传入NULL时调用实际上是int类型函数，避免了如下代码的尴尬（实际想传入空指针）。

void func(int n) 
{
        cout << "int\n";
}


void func(char* sz) 
{
       cout << "ptr\n";
}

int main()
{
        func(NULL);
        system("pause"); 
}

1.6 using与typedef
using INT = int;这种定义在元编程会有很大用处。

1.7 noexcept修饰符与noexcept操作符。
void except_func() noexcept;函数抛出异常调用std::terminate直接结束程序。（1）

void except_func() noexcept(常量表达式);常量表达为true禁止异常抛出。（2）

作用：禁止异常扩散，（2）元编程中模板函数根据模板参数会有不同行为。

1.8 非静态成员sizeof：
 以下语法在c++11编译通过sizeof(类名::成员变量名)，c++11之前往往通过这种方法，sizeof(((class*)0)→变量)可读性比较差。

friend关键字，在c++11中声明友元类不需要再加class关键字。

final/override:final关键字禁止派生类重写父类虚函数，override如果派生类虚函数声明override，该类必须重写父类虚函数。

委托构造



note：委托构造不能与初始化参数列表并用

右值引用、移动构造、完美转发

c++中没有名字的变量称为右值。



如上，将getA返回A类型临时对象（函数返回int类型值时，将值放入eax寄存器，当返回对象时，返回的其实是构造在main函数栈空间的一个临时对象）拷贝给a时发生深拷贝，影响效率。

&&右值引用声明、move关键字会将一个左值强制转换为右值。

完美转发：

引用折叠:

1.所有右值引用折叠到右值引用上仍然是一个右值引用。（A&& && 变成 A&&）
2.所有的其他引用类型之间的折叠都将变成左值引用。 （A& & 变成 A&; A& && 变成 A&; A&& & 变成 A&）

四种类型转换

static_cast
const_cast
dynamic_cast
reinterpret_cast

常量表达式constexpr

2.stl新增容器
可变长数组

std::array 示例：auto nArray = std::array<int, 4> = {1, 2, 3, 4};

单向链表　　

　　std::forward_list（list双向链表）

哈希表

　　std::unordered_map(底层实现采用哈希表，相对于红黑树来说，查找更快，但是更浪费空间)

　　std::unordered_set

3.多线程支持
3.1 线程std::thread
c++11提供了对thread的支持，构造函数如下：

default (1)	
thread() noexcept;
initialization (2)	
template <class Fn, class... Args>
explicit thread (Fn&& fn, Args&&... args);
copy [deleted] (3)	
thread (const thread&) = delete;
move (4)	
thread (thread&& x) noexcept;
note：1）线程传参都是赋值操作，需要传引用时参数必须用std::ref()包裹

2）线程支持类非静态且非私有成员函数，传入成员函数时，第一个参数必须是该类对象的地址

线程启动可以调用join（阻塞当前线程直到子线程退出）、datch（不阻塞当前线程）成员函数。note：调用以上两个函数，线程并不一定立即执行，执行时机依据操作系统线程调度。

3.2 原子类型
atomic<T> 原子类型可实现无锁编程。可以实现mutex，原子类型要求内存模型顺序一致，某些系统上限制代码执行效率。

3.3 锁


recursive_mutex	递归锁
timed_mutex	时间锁
recursive_timed_mutex	递归时间锁
3.4 条件变量
condition_variable

3.5 future
future promise

3.6 线程常用操作
线程休眠：std::this_thread::sleep_for(std::chrono::milliseconds(10000));（具体时间间隔参考标准时间库，可支持单位： 分钟、秒、毫秒、微秒）

线程挂起唤醒操作：

c++并不直接支持线程挂起操作，可结合future、promise或者条件变量实现线程挂起唤醒。

4.内存管理
共享智能指针
shared_ptr 尽量避免智能指针与原生指针混用。当类成员函数中存在线程时（类内访问this指针并不会让共享指针引用计数自增），该类需要继承enable_shared_from_this，线程传入self（auto self(shared_from_this());）boost::asio server client示例中有很多这样操作。





独占智能指针
unique_ptr

循环引用与weak_ptr
weak_ptr

5.仿函数、bind语句、lambda表达式
bind 示例

lambda [捕获列表](参数列表)→返回值类型{函数体}  捕获列表声明传参方式，=为赋值、&为传引用

6.tuple类型、以及可变参数模板
c++11开始支持可变长参数模板，这对于tuple实现变的很简单。

sample 一个简单的tuple实现:



可变参数解包模板

递归与逗号表达式

以上tuple采用了递归的方式展开变长模板参数，这在元编程中是非常常见的，递归方式实现循环。

变量 = (表达式1， 表达式2)  变量的值等于 表达式2 的值。

sample 逗号表达式解包:



7. 列表初始化
8.数据对齐、unicode支持
utf-8支持

9.其他
标准时间库

POD类型及定义、运行时期类型识别

POD满足一下条件：

（1）平凡的类：

1）拥有平凡的默认的构造函数、析构函数。

2）拥有平凡的默认的拷贝构造函数、移动构造函数。

3）拥有平凡的赋值构造、移动赋值构造。

4）不能包含虚函数、以及虚基类。

（2）标准内存布局：

1）所有的非静态成员拥有相同的访问权限。

2）派生类中有静态成员，且只有一个包含静态成员的基类。

3）基类有非静态成员，派生类没有非静态成员。

4）类中第一个非静态成员的类型与基类不同。

非受限联合体

自定义字面量

内联命名空间

以上链接参考http://www.cplusplus.com 其中会有一些例子，与函数声明。 
