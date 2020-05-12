#include <iostream>
using namespace std;
class Complex
{
public:
    Complex(double rp = 0.0, double ip = 0.0) : rp_(rp), ip_(ip) {}
    bool operator==(const Complex &rhs);
    bool operator!=(const Complex &rhs);
    bool operator<(const Complex &rhs);
    bool operator>(const Complex &rhs);
    friend ostream &operator<<(ostream &o, const Complex &);

private:
    double rp_;
    double ip_;
};

bool Complex::operator==(const Complex &rhs)
{
    return (rp_ == rhs.rp_ && ip_ == rhs.ip_);
}
bool Complex::operator!=(const Complex &rhs)
{
    return !(*this == rhs);
}
bool Complex::operator<(const Complex &rhs)
{
    return (rp_ < rhs.rp_) ? true : (rp_ > rhs.rp_) ? false : (ip_ < rhs.ip_) ? true : false;
}
bool Complex::operator>(const Complex &rhs)
{
    return (rp_ > rhs.rp_) ? true : (rp_ < rhs.rp_) ? false : (ip_ > rhs.ip_) ? true : false;
}
ostream &operator<<(ostream &o, const Complex &c)
{
    return o << c.rp_ << ":" << c.ip_ << "i";
}