#ifndef FACTORY_H
#define FACTORY_H

#include<iostream>
#include<map>
#include<string>

using namespace std;

template<typename BaseClass>
class Factory
{
private:
    map<string, BaseClass*> constructorTablePtr_;
public:
    Factory(){}

    template<typename subClass>
    BaseClass* Create()
    {
        
    }
    


};



#endif FACTORY_H

