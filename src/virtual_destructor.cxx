#include <iostream>

class Base
{
    public:
    Base()
    {
        std::cout<<"Base Default Ctor"<<std::endl;
    }

    virtual void print()
    {
        std::cout<< "base print"<<std::endl;
    }

    virtual ~Base()
    {
        std::cout<<"Base Destructor"<<std::endl;
    }
};

class D: public Base
{
    char * m_arr;
    int size;
public:
    explicit D( int length)
    {
        std::cout<< "Derived Default Ctor"<<std::endl;   
        m_arr = new char[length];
        size = length;
    }

    char& operator[](int index)
    {
        std::cout<< "index operator"<<std::endl; 
        if( index < 0 || index >= size)  
            throw 2;
        return m_arr[index];
    }

    void print() override
    {
        std::cout<< "Derived Print"<<std::endl; 
        for(int i=0;i<size;i++)
           std::cout<< m_arr[i];
        std::cout<< std::endl;  
    }
    
    ~D()
    {
        std::cout<< "Derived Destructor"<<std::endl; 
        delete[] m_arr;
    }

};



int main()
{
    D *d = new D(10);
    std::cout<< "Derived object created on head"<<std::endl; 
    d->operator[](0)='G';

    Base *b = static_cast<Base*>(d);
    b->print();

    delete b;

}
