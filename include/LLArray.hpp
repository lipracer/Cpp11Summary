#ifndef LLARRAY_H_
#define LLARRAY_H_

#include <initializer_list>

using namespace std;

template <typename TYPE, int DISM>
class LLArray
{
public:
    LLArray(TYPE *data, initializer_list<int> list) : __data(data)
    {
        __aSize = new int[DISM];
        for (int i = 0; i < DISM; i++)
        {
            __aSize[i] = *(list.begin() + i);
        }
    }
    LLArray(TYPE *data, int *size) : __data(data), __aSize(size)
    {
    }
    LLArray<TYPE, DISM - 1> operator[](int index)
    {
        int offset = 1;
        for (int i = 1; i < DISM; i++)
        {
            offset *= __aSize[i];
        }
        return LLArray<TYPE, DISM - 1>(__data + index * offset, __aSize + 1);
    }
    int size()
    {
        return __aSize[0];
    }
	void Release() 
	{
		delete __aSize;
	}
private:
    TYPE* __data;
    int *__aSize;
};

template <typename TYPE>
class LLArray<TYPE, 1>
{
public:
    LLArray(TYPE *data, int *size) : __data(data), __aSize(size)
    {
    }
    TYPE operator[](int index)
    {
        return __data[index];
    }
    int size()
    {
        return __aSize[0];
    }
private:
    TYPE* __data;
    int *__aSize;
};

//template <typename TYPE, int LastC, int ...argvs>
//class LLArray
//{
//public:
//    LLArray(TYPE *data) : __data(data)
//    {
//    }
//    LLArray<TYPE, argvs...> operator[](int index)
//    {
//        int offset = 1;
//        int tmp[] = {argvs...};
//        for (int i = 0; i < sizeof(tmp)/sizeof(int); i++)
//        {
//            offset *= tmp[i];
//        }
//        return LLArray<TYPE, argvs...>(__data + index * offset);
//    }
//    int size()
//    {
//        return LastC;
//    }
//private:
//    TYPE* __data;
//};
//
//template <typename TYPE, int LastC>
//class LLArray<TYPE, LastC>
//{
//public:
//    LLArray(TYPE *data) : __data(data)
//    {
//    }
//    TYPE operator[](int index)
//    {
//        return __data[index];
//    }
//    int size()
//    {
//        return LastC;
//    }
//private:
//    TYPE* __data;
//};


#endif // LLARRAY_H_
