#include "grocery.h"

grocery::grocery()
{

}
grocery::grocery(string cat_,string itm_,int tk){
    catagory=cat_;
    itm_nam=itm_;
    price=tk;
}
grocery::~grocery()
{

}
istream& operator >> (istream& op_ov,grocery &A){
    cout<<"\t\t\tItem Catagory  Name :: ";
    op_ov>>A.catagory;
    cout<<"\t\t\tItem Name :: ";
    op_ov>>A.itm_nam;
    cout<<"\t\t\tItem Price :: ";
    op_ov>>A.price;
    return op_ov;
}
ostream& operator << (ostream& fout,grocery &A){
    fout<<"\t\t\tItem Catagory :: "<<A.catagory<<endl;
    fout<<"\t\t\tItem Name :: "<<A.itm_nam<<endl;
    fout<<"\t\t\tItem Price :: "<<A.price<<endl;
    fout<<"\t\t\tItem ID :: "<<A.ID<<endl;
    return fout;
}
