#include "shop.h"

shop::shop()
{
    read();
    read_();
}

shop::~shop()
{
    write();
    write_();
}
void shop::show()
{
    cout<<"";
    for(int i=0; i<40; i++)
        cout<<"_*_";
    cout<<endl;
}
//functor
bool comp(grocery &a,grocery &b)
{
    return a.ID<b.ID;
}
void shop::intro()
{
    show();
    cout<<"\t\t\t                    Welcome to "<<endl;
    cout<<"\t\t\t                   Rokomari.com"<<endl;
    show();
    int x,y;
    string s1,s2;
    while(1)
    {
        cout<<"\t\t\t1.Sign In"<<endl;
        cout<<"\t\t\t2.Sign Up"<<endl;
        cout<<"\t\t\t3.Exit"<<endl;
        cout<<"\t\t\tYour Choice :: ";
        cin>>x;
        if(x==1)
        {
            cout<<"\t\t\tUser Name/Email :: ";
            cin>>s1;
            cout<<"\t\t\tPassword :: ";
            cin>>s2;
            y=sign_in(s1,s2);
            if(y!=-1)
            {
                cout<<"\t\t\tLogged In Successfully\n";
                break;
            }
            else
            {
                cout<<"\t\t\tPassword or User ID doesn't match"<<endl<<"\t\t\tTry Again"<<endl;
            }
        }
        else if(x==2)
        {
            y=sign_up();
        }
        else if(x==3)
            return;
        else
        {
            cout<<"\t\t\tInvalid Input"<<endl<<"\t\t\tTry again"<<endl;
        }
    }
    show();
    cout<<endl;
    while(1)
    {
        show();
        cout<<"\t\t\t1.Search for Grocery"<<endl;
        cout<<"\t\t\t2.Show Your Cart"<<endl;
        cout<<"\t\t\t3.Add an Item To Cart"<<endl;
        cout<<"\t\t\t4.Order Your Cart"<<endl;
        cout<<"\t\t\t5.View Your Account"<<endl;
        cout<<"\t\t\t6.Edit Your Account"<<endl;
        cout<<"\t\t\t7.Show ALL products"<<endl;
        cout<<"\t\t\t8.At new Item To Grocery"<<endl;
        cout<<"\t\t\t9.Exit"<<endl;
        show();
        cout<<"\t\t\tYour Choice :: ";
        cin>>x;
        if(x==1)
        {
            search_();
        }
        else if(x==2)
        {
            show_cart();
        }
        else if(x==3)
        {
            add_to_cart();
        }
        else if(x==4)
        {
            order();
        }
        else if(x==5)
        {
            cout<<array[y]<<endl;
        }
        else if(x==6)
        {
            update_(y);
        }
        else if(x==7)
        {
            show_all();
        }
        else if(x==8)
        {
            grocery g;
            cin>>g;
            g.ID=data.size();
            data.push_back(g);
            //functor
            sort(data.begin(),data.end(),comp);
        }
        else
        {
            write();
            write_();
            break;
        }
    }
}
void shop::add_to_cart()
{
    system("cls");
    int s;
    int ss;
    while(1)
    {
        cout<<"\t\t\t1.I know Product ID,Proceed To Cart"<<endl;
        cout<<"\t\t\t2.Search For Product"<<endl;
        cout<<"\t\t\t3.Exit"<<endl;
        cout<<"Your Choice :: ";
        cin>>s;
        if(s==1)
        {
            cout<<"Product ID :: ";
            cin>>ss;
            if(ss<0 or ss>data.size())
                throw 1;
            cart.push_back(ss);
        }
        else if(s==2)
        {
            search_();
        }
        else
            break;
    }
}
void shop::show_match(vector<int>vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        cout<<data[vec[i]]<<endl;
    }

}
vector<int> shop::find_by_cat(string s)
{
    vector<int>t;
    for(int i=0; i<data.size(); i++)
    {
        if(data[i].catagory==s)
            t.push_back(i);
    }
    return t;
}
vector<int> shop::find_by_name(string s)
{
    vector<int>t;
    for(int i=0; i<data.size(); i++)
    {
        if(data[i].itm_nam==s)
            t.push_back(i);
    }
    return t;
}
vector<int> shop::find_under_price(int s)
{
    vector<int>t;
    for(int i=0; i<data.size(); i++)
    {
        if(data[i].price<=s)
            t.push_back(i);
    }
    return t;
}
vector<int> shop::find_bigger_price(int s)
{
    vector<int>t;
    for(int i=0; i<data.size(); i++)
    {
        if(data[i].price>=s)
            t.push_back(i);
    }
    return t;
}
void shop::show_all()
{
    system("cls");
    for(int i=0; i<(int)data.size(); i++)
    {
        cout<<data[i]<<endl;
    }
}
void shop::search_()
{
    system("cls");
    show();
    cout<<"\t\t\tSearch Panel"<<endl;
    show();
    int x,y;
    string s;
    vector<int>vec;
    while(1)
    {
        cout<<"\t\t\t1.Search By Catagory"<<endl;
        cout<<"\t\t\t2.Search By Name"<<endl;
        cout<<"\t\t\t3.Search By less then Price"<<endl;
        cout<<"\t\t\t4.Search By More then Price"<<endl;
        cout<<"\t\t\t5.Exit\n";
        cout<<"\t\t\tYour Choice :: ";
        cin>>x;
        if(x==1)
        {
            cout<<"\t\t\tCatagory name :: ";
            cin>>s;
            vec=find_by_cat(s);
            show_match(vec);
        }
        else if(x==2)
        {
            cout<<"\t\t\tProduct Name :: ";
            cin>>s;
            vec=find_by_name(s);
            show_match(vec);
        }
        else if(x==3)
        {
            cout<<"\t\t\tPrice :: ";
            cin>>y;
            vec=find_under_price(y);
            show_match(vec);
        }
        else if(x==4)
        {
            cout<<"\t\t\tPrice :: ";
            cin>>y;
            vec=find_bigger_price(y);
            show_match(vec);
        }
        else
            break;
    }
}
void shop::show_cart()
{
    system("cls");
    for(int i=0; i<(int)cart.size(); i++)
        cout<<data[cart[i]]<<endl;
}
void shop::order()
{
    int sum=0;
    for(int i=0; i<cart.size(); i++)
    {
        sum+=data[cart[i]].price;
    }
    cout<<"\t\t\tThis will cost you"<<sum<<"taka"<<endl;
    cin.get();
}
int shop::sign_in(string user,string pass)
{
    for(int i=0; i<array.size(); i++)
    {
        if((array[i].mail==user or array[i].username==user) and array[i].password==pass)
            return i;
    }
    return -1;
}
int shop::sign_up()
{
    account s;
    cin>>s;
    while(!register_(s))
    {
        cout<<"\t\t\tUser Name Al ready In Use"<<endl<<"\t\t\tTry Another"<<endl;
        cin>>s.username;
    }
    return array.size()-1;
}
void shop::read()
{
    ifstream op_ov("grocery.txt");
    grocery s;
    while(op_ov>>s.catagory)
    {
        op_ov>>s.itm_nam>>s.price>>s.ID;
        data.push_back(s);
    }
   op_ov.close();
}
void shop::write()
{
    ofstream fout("grocery.txt");
    for(int i=0; i<data.size(); i++)
    {
        fout<<data[i].catagory<<" "<<data[i].itm_nam<<" "<<data[i].price<<" "<<data[i].ID<<endl;
    }
    fout.close();
}
