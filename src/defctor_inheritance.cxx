#include <iostream>

class Base
{
   int val;
public:
    Base(int num):
        val(num)
    {
        
    }

    Base(const Base& base)
    {
        std::cout<<"Base Copy Ctor"<<std::endl;
        val = base.val;
    }
    
};

class Derived:public Base
{
public:
    Derived(int num):
    Base(num)
    {}
    Derived(const Derived& d):
        Base(d)
    {
        std::cout<<"Derived Copy Ctor"<<std::endl;
    }

};

int main()
{
    Derived *d = new Derived(1);
    Derived d1 = *d;
}
