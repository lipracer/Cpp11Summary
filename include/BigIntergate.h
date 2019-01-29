//BigIntergate

#ifndef BIGINTERGATE_H_
#define BIGINTERGATE_H_
#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> Mul2BigIntergate(const vector<T>& lNum, const vector<T>& rNum)
{
    vector<T> result(lNum.size() + rNum.size());
    for (size_t i = 0; i < lNum.size(); ++i)
    {
        for (size_t j = 0; j < rNum.size(); ++j)
        {
            result[i + j] += lNum[i] * rNum[j];
        }
    }
    for (size_t i=0; i < result.size()-1; i++)
    {
        if(result[i] >= 10)
        {
            result[i+1] += result[i]/10;
            result[i] = result[i]%10;
        }
    }
    return result;
}

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
