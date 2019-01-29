//BigIntergate
#include<assert.h>
#include "BigIntergate.h"


inline void ReverseStr(string& str) 
{
	string tmp = str;
	str.clear();
	for (auto it = tmp.rbegin(); it != tmp.rend(); it++)
	{
		str.push_back(*it);
	}
}

BigIntergate BigIntergate::operator+(const BigIntergate& other)
{
    assert(this->m_number_str.size() && other.m_number_str.size());
    BigIntergate ret("");
    int carry = 0;
    int one_ret = 0;
    auto it1 = this->m_number_str.rbegin();
    auto it2 = other.m_number_str.rbegin();
    while (carry || this->m_number_str.rend()!=it1 || other.m_number_str.rend() != it2)
    {
		int n1 = 0, n2 = 0;
		if (it1 != this->m_number_str.rend()) 
		{
			n1 = *it1 - '0';
		}
		if (it2 != other.m_number_str.rend())
		{
			n2 = *it2 - '0';
		}
        one_ret = n1 + n2 + carry;
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
	ReverseStr(ret.m_number_str);
    return ret;
}

inline static string MultStrChar(string& str1, char ch, int local)
{
	string ret("");
	int carry = 0;
	int one_ret = 0;
	for (auto it = str1.rbegin(); it != str1.rend(); it++)
	{
		one_ret = (*it - '0') * (ch - '0') + carry;
		if (one_ret >= 10)
		{
			carry = one_ret / 10;
		}
		else 
		{
			carry = 0;
		}
		ret.push_back(one_ret%10 + '0');
	}
	if (carry) 
	{
		ret.push_back(carry + '0');
	}	
	ReverseStr(ret);
	while (local--) ret.push_back('0');
	return ret;
}

BigIntergate BigIntergate::operator*(const BigIntergate& other)
{
	assert(this->m_number_str.size() && other.m_number_str.size());
	BigIntergate ret("0");
	int size = (int)other.m_number_str.size();
	for (int i = size-1; i >= 0; i--)
	{
		string result = MultStrChar(this->m_number_str, other.m_number_str[i], size-1-i);
		//BigIntergate result_(result);
		ret = ret.operator+(BigIntergate(result));
	}
    return ret;
}

ostream& operator<<(ostream& outs, BigIntergate& big_int)
{
    outs << big_int.m_number_str;
    return outs;
}

ostream& operator<<(ostream& outs, BigIntergate&& big_int)
{
    outs << big_int.m_number_str;
    return outs;
}


