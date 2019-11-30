#include "account.h"

account::account()
{

}

account::~account()
{

}
istream& operator>>(istream& op_ov,account &a)
{
    check::check_class c;
    cout<<"\t\t\tUsername :: ";
    op_ov>>a.username;
    cout<<"\t\t\tName :: ";
    op_ov>>a.full;
mail:
    cout<<"\t\t\tMail :: ";
    op_ov>>a.mail;
    cout<<"\t\t\tPassword :: ";
    op_ov>>a.password;
phone:
    cout<<"\t\t\tPhone Number :: ";
    op_ov>>a.phone;
    if(!c.check_phone_number(a.phone))
    {
        cout<<"\t\t\tInvalid Phone Number | Try Again |\n";
        goto phone;
    }
    cout<<"\t\t\tAddress :: ";
    op_ov>>a.address;
    return op_ov;
}
ostream& operator<<(ostream& fout,account &a)
{
    fout<<"\t\t\tName :: "<<a.full<<endl;
    fout<<"\t\t\tUser Name :: "<<a.username<<"\n\t\t\tMail :: "<<a.mail<<"\n\t\t\tPhone Number :: "<<a.phone<<endl;
    fout<<"\t\t\tAddress :: "<<a.address<<endl;
    return fout;
}
