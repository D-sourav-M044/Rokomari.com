#ifndef GROCERY_H
#define GROCERY_H
#include<windows.h>
#include<time.h>
#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
class grocery
{
public:
    virtual void intro(){}
    virtual void show_all(){}
    virtual void add_to_cart(){}
    virtual void show_match(vector<int>v){}
    virtual vector<int> find_by_cat(string s){}
    virtual vector<int> find_by_name(string s){}
    virtual vector<int> find_under_price(int s){}
    virtual vector<int> find_bigger_price(int s){}
    virtual void search_(){}
    virtual void show_cart(){}
    virtual void order(){}
    virtual int  sign_in(string user,string pass){}
    virtual int sign_up(){}
    virtual void read(){}
    virtual void write(){}
    virtual void show(){}
    grocery();
    grocery(string cat_,string itm_,int tk);
    virtual ~grocery();
    string catagory,itm_nam;
    int price;
    int ID;
    friend istream& operator >> (istream& fin,grocery &A);
    friend ostream& operator << (ostream& fout,grocery &A);
protected:
private:
};

#endif
