#include <iostream> 

template<typename type>

class Storage
{
    type m_value;
public:

    Storage(type val)
    {
        m_value = val;
    }

    void print()
    {
        std::cout<< m_value<<std::endl; 
    }

};

template<>
void Storage<double>::print()
{
    std::cout<< "double specification"<<std::endl; 
    std::cout<< std::scientific<<m_value <<std::endl; 
}

int main() 
{
    Storage<int> ivalue(8u);
    Storage<double> dvalue(6.7);
    ivalue.print();
    dvalue.print();
}
