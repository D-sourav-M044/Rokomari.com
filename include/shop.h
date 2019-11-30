#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include "grocery.h"
#include "info.h"
using namespace std;

class shop:public grocery,info
{
public:
    shop();
    virtual ~shop();
    void intro();
    void show_all();
    void add_to_cart();
    void show_match(vector<int>vec);
    vector<int> find_by_cat(string s);
    vector<int> find_by_name(string s);
    vector<int> find_under_price(int s);
    vector<int> find_bigger_price(int s);
    void search_();
    void show_cart();
    void order();
    int  sign_in(string user,string pass);
    int sign_up();
    void read();
    void write();
    void show();
    friend sort();
protected:
private:
    vector<grocery>data;
    vector<int>cart;
};

#endif
