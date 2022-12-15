#ifndef PRODUCTS_H
#define PRODUCTS_H

#include<iostream>
#include<map>
#include<string>

using namespace std;

class ProductBase;

typedef ProductBase* (*strConstrPtr)(const string& tname);


class ProductBase
{
public:
    static string typeName_;

public:
    static map<string, strConstrPtr> ptrTables;

    template<typename T>
    static ProductBase* New0()
    {
        return (ProductBase*) (new T);
    }

    template<typename T>
    static void addToConstructTable()
    {
        auto iter = ptrTables.find(T::typeName_);
        if (iter != ptrTables.end())
        {
            cout << "insert duplicately!" << endl
            << "type name: " << T::typeName_ << endl;
            exit(1);
        }
        ptrTables.insert(pair<string, strConstrPtr>(T::typeName_, New0));
    }
    // static void removeFromConstructTable();


public:
    ProductBase()
    {
        typeName_ = "base";
        cout << "ProductBase constructor" << endl;
    }

    // input type name, return a base class pointer,
    // pointing to a object of the derived class
    static ProductBase* New(const string& typeName)
    {
        auto iter = ptrTables.find(typeName);
 
        if(iter == ptrTables.end())
        {
            cout << "not find typeName (" << typeName << ") in Table!" 
                    << endl
                    << "accessible type :" << endl;
            for(auto& x:ptrTables)
            {
                cout << x.first << endl;
            }
            cout << endl;

            exit(1);
        }

        strConstrPtr fp = iter->second;
        return (*fp)(typeName);
    }

    void show()
    {
        cout << "show type: " << typeName_ << endl;
    }

};

ProductBase::addToConstructTable<ProductBase>();

class ProductNew1: public ProductBase
{
    public:
    static string typeName_;
public:
    ProductNew1()
    {
        typeName_ = "new1";
        cout << "ProductNew1 constructor" << endl;
        ProductBase::addToConstructTable<ProductNew1>();
    }

    void show()
    {
        cout << "show type: " << typeName_ << endl;
    }

};

class ProductNew2: public ProductBase
{
public:
    static string typeName_;

    ProductNew2()
    {
        typeName_ = "new2";
        cout << "ProductNew2 constructor" << endl;
        ProductBase::addToConstructTable<ProductNew2>();
    }

    void show()
    {
        cout << "show type: " << typeName_ << endl;
    }
};

class SubProductNew1: public ProductNew1
{
public:
    static string typeName_;

    SubProductNew1()
    {
        typeName_ = "subNew1";
        cout << "subProductNew1 constructor" << endl;
        ProductBase::addToConstructTable<SubProductNew1>();
    }

    void show()
    {
        cout << "show type: " << typeName_ << endl;
    }
};




#endif // RPODUCTS_H