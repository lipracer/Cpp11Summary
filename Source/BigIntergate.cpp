//BigIntergate

#include "BigIntergate.h"

BigIntergate BigIntergate::operator+(BigIntergate& other)
{
    assert(this->m_number_str.size() && other.m_number_str.size());
    BigIntergate ret("");
    int carry = 0;
    int one_ret = 0;
    auto it1 = this->m_number_str.rbegin();
    auto it2 = other.m_number_str.rbegin();
    while (carry || this->m_number_str.rend()!=it1 || other.m_number_str.rend() != it2)
    {
        one_ret = *it1 - '0' + *it2 - '0' + carry;
        if(one_ret >= 10)
        {
            carry = one_ret / 10;
        }
        else
        {
            carry = 0;
        }
        ret.m_number_str.push_back(one_ret%10 + '0');
        if(it1!=this->m_number_str.rend())
        {
            it1++;
        }
        if(it2!=other.m_number_str.rend())
        {
            it2++;
        }
    }
    string tmp = ret.m_number_str;//反转字符
    ret.m_number_str.clear();
    for (auto it=tmp.rbegin(); it != tmp.rend(); it++)
    {
        ret.m_number_str.push_back(*it);
    }
    return ret;
}

BigIntergate BigIntergate::operator*(BigIntergate& other)
{
    return BigIntergate("");
}
