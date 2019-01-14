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
        for (int i = 0; i < DISM-1; i++)
        {
            offset *= __aSize[i];
        }
        return LLArray<TYPE, DISM - 1>(__data + index * offset, __aSize + 1);
    }
    int size()
    {
        return __aSize[0];
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


#endif // LLARRAY_H_
