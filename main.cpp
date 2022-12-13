#include<iostream>
#include<map>

using namespace std;


class ProductBase
{
public:
    ProductBase()
    {
        cout << "ProductBase constructor" << endl;
    }
    ~ProductBase();

    void operator()()
    {
        cout << "ProductBase()" << endl;
    }
};

map<string, (*ProductBase)> ptrTables;

class ProductNew1: public ProductBase
{
public:
    ProductNew1()
    {
        cout << "ProductNew1 constructor" << endl;
    }

    void operator()()
    {
        cout << "ProductNew1()" << endl;
    }

};

class ProductNew2: public ProductBase
{
public:
    ProductNew2()
    {
        cout << "ProductNew2 constructor" << endl;
    }
    ~ProductNew2();

    void operator()()
    {
        cout << "ProductNew2()" << endl;
    }
};

class SubProductNew1: public ProductNew1
{
public:
    SubProductNew1()
    {
        cout << "subProductNew1 constructor" << endl;
    }
    ~SubProductNew1();

    void operator()()
    {
        cout << "subProductNew1()" << endl;
    }
};




