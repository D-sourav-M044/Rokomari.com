#include "info.h"
using namespace check;
info::info()
{

}

info::~info()
{

}
int info::find_(account a)
{
    for(int i=0; i<(int)array.size(); i++)
    {
        if(a.username==array[i].username and a.mail==array[i].mail and a.password==array[i].password)
            return i;
    }
    return -1;
}
int info::find_(string user,string pass)
{
    for(int i=0; i<(int)array.size(); i++)
    {
        if((user==array[i].username or user==array[i].mail) and pass==array[i].password)
        {
            return i;
        }
    }
    return -1;
}
bool info::register_(account a)
{
    for(int i=0; i<(int)array.size(); i++)
    {
        if(array[i].username==a.username)
        {
            return 0;
        }
    }
    array.push_back(a);
    return 1;
}
void info::read_()
{
    ifstream op_ov("info.txt");
    account s;
    while(op_ov>>s.username)
    {
        op_ov>>s.full>>s.password>>s.phone>>s.mail>>s.address;
        array.push_back(s);
    }
    op_ov.close();
}
void info::write_()
{
    ofstream fout("info.txt");
    for(int i=0;i<array.size();i++)
    {
        fout<<array[i].username<<" "<<array[i].full<<" "<<array[i].password<<" "<<array[i].phone<<" "<<array[i].mail<<" "<<array[i].address<<endl;
    }
    fout.close();
}
void info::update_(int id)
{
    system("cls");
    check_class c;
    int x;
    string s;
    cout<<"\t\t\tUpdate Panel"<<endl;
    while(1)
    {
        cout<<"\t\t\t1.Update Name\n";
        cout<<"\t\t\t2.Update Password\n";
        cout<<"\t\t\t3.Update Mail\n";
        cout<<"\t\t\t4.Update Number\n";
        cout<<"\t\t\t5.Update Address\n";
        cout<<"\t\t\t6.Exit\n";
        cout<<"\t\t\tYour Choice :: ";
        cin>>x;
        if(x==1)
        {
            cout<<"\t\t\tNew Name :: ";
            cin>>s;
            array[id].full=s;
        }
        else if(x==2)
        {
            cout<<"\t\t\tNew Password :: ";
            cin>>s;
            array[id].password=s;
        }
        else if(x==3)
        {
mail:
            cout<<"\t\t\tNew mail :: ";
            cin>>s;
            if(1 )
                array[id].mail=s;
            else
            {
                cout<<"\t\t\tInvalid Email\t Try Again";
                goto mail;
            }
        }
        if(x==4)
        {
phone:
            cout<<"\t\t\tNew Number :: ";
            cin>>s;
            if(c.check_phone_number(s))
            {
                array[id].phone=s;
            }
            else
            {
                cout<<"\t\t\tInvalid Number\t Try Again";
                goto phone;
            }
        }
        if(x==5)
        {
            cout<<"\t\t\tNew Address :: ";
            getchar();
            getline(cin,s);
            array[id].address=s;
        }
        if(x==6)
            break;
    }
}
