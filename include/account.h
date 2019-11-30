#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<string>
#include<fstream>
#include<iostream>
#include "check_class.h"
using namespace std;
class account
{
public:
    friend istream& operator>>(istream& op_ov,account &a);
    friend ostream& operator<<(ostream& fout,account &a);
    string username,mail,password,phone,address,full;
    account();
    virtual ~account();
protected:
private:
};

#endif
