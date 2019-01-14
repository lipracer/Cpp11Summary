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
    friend ostream& operator<<(ostream& cout_, BigIntergate& big_int)
    {
        cout << big_int.m_number_str;
        return cout;
    }
private:
    std::string m_number_str;
};

#endif
