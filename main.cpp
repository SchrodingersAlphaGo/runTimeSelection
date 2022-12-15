#include "products.h"
// #include "factory.h"


int main()
{
    string p1{"new1"};
    string p2{"new2"};
    string sp1{"subNew1"};

    ProductBase* pb = new ProductBase;
    
    // construct new1
    ProductBase* pbn1 = ProductBase::New(p1);

    // construct new2
    ProductBase* pbn2 = ProductBase::New(p2);
    // construct sub-new1

    return 0;
}