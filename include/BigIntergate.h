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
    BigIntergate operator+(const BigIntergate& other);
    BigIntergate operator*(const BigIntergate& other);
    friend ostream& operator<<(ostream& outs, BigIntergate& big_int);
    friend ostream& operator<<(ostream& outs, BigIntergate&& big_int);
private:
    std::string m_number_str;
};

#endif
