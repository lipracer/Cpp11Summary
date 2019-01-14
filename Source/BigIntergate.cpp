//BigIntergate

#include "BigIntergate.h"

BigIntergate& BigIntergate::operator+(BigIntergate& other)
{
    assert(this->m_number_str.size() && other.m_number_str.size());
    return BigIntergate("");
}

BigIntergate& BigIntergate::operator*(BigIntergate& other)
{
    
}
