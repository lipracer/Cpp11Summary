//BigIntergate

#ifndef BIGINTERGATE_H_
#define BIGINTERGATE_H_
#include <string>
#include <iostream>

using namespace std;

class BigIntergate
{
public:
    //template<typename T>
    BigIntergate(string str) : m_number_str(str) { }
    BigIntergate operator+(BigIntergate& other);
    BigIntergate operator*(BigIntergate& other);
    friend ostream& operator<<(ostream& outs, BigIntergate& big_int)
    {
        outs << big_int.m_number_str;
        return outs;
    }
    friend ostream& operator<<(ostream& outs, BigIntergate&& big_int)
    {
        outs << big_int.m_number_str;
        return outs;
    }
private:
    std::string m_number_str;
};

#endif
