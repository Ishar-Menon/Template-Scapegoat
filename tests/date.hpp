#include <iostream>
using namespace std;

struct MyDate
{
public:
    explicit MyDate(int dd = 1, int mm = 1, int yy = 1970)
        : dd_(dd), mm_(mm), yy_(yy) {}
    friend ostream &operator<<(ostream &, const MyDate &);
    friend bool operator<(const MyDate &lhs, const MyDate &rhs);
    friend bool operator>(const MyDate &lhs, const MyDate &rhs);
    friend bool operator==(const MyDate &lhs, const MyDate &rhs);

private:
    int dd_;
    int mm_;
    int yy_;
};

ostream &operator<<(ostream &o, const MyDate &d)
{
    return o << d.dd_ << "-" << d.mm_ << "-" << d.yy_;
}

bool operator<(const MyDate &lhs, const MyDate &rhs)
{
    if (lhs.yy_ < rhs.yy_)
        return true;
    else if (lhs.yy_ == rhs.yy_ && lhs.mm_ < rhs.mm_)
        return true;
    else if (lhs.yy_ == rhs.yy_ && lhs.mm_ == rhs.mm_ &&
             lhs.dd_ < rhs.dd_)
        return true;
    else
        return false;
}
bool operator>(const MyDate &lhs, const MyDate &rhs)
{
    if (lhs.yy_ > rhs.yy_)
        return true;
    else if (lhs.yy_ == rhs.yy_ && lhs.mm_ > rhs.mm_)
        return true;
    else if (lhs.yy_ == rhs.yy_ && lhs.mm_ == rhs.mm_ &&
             lhs.dd_ > rhs.dd_)
        return true;
    else
        return false;
}

bool operator==(const MyDate &lhs, const MyDate &rhs)
{

    if (lhs.yy_ == rhs.yy_ && lhs.mm_ == rhs.mm_ &&
        lhs.dd_ == rhs.dd_)
        return true;

    return false;
}