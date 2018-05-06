
#include <iostream> 

class Person
{
    static int count ;
public:

    Person()
    {
        count++;
    }

    static int getCount() { return count;}
    
};


int Person::count = 0;

int main()
{
    Person p1,p2,p3,p4;

    std::cout<< p4.getCount()<<std::endl; 
    std::cout<< Person::getCount()<<std::endl; 
}


