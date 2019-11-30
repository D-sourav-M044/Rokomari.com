#include <iostream>
#include "shop.h"
using namespace std;
int main()
{
    system("COLOR 2F");
    grocery *t;
    shop s;
    t=&s;
    t->intro();
    return 0;
}
