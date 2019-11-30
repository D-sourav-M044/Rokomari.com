#ifndef INFO_H
#define INFO_H
#include "account.h"
#include<vector>
using namespace std;
class info:public account
{
    public:
        vector<account>array;
        info();
        virtual ~info();
        int find_(account a);
        int find_(string user,string pass);
        bool register_(account a);
        void update_(int id);
        void read_();
        void write_();
    protected:
    private:
};

#endif // info_H
