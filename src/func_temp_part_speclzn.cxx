
#include <iostream> 

template<typename type, typename type2>

class Storage
{
    type m_value;
    type2 t_value;
public:

    Storage(type val, type2 val2)
    {
        m_value = val;
        t_value = val2;
    }

    void print()
    {
        std::cout<< m_value<<std::endl; 
        std::cout<< t_value<<std::endl; 

    }

};

template<typename type>
void Storage<type,double>::print()
{
    std::cout<< "double specification"<<std::endl; 
    std::cout<< t_value <<std::endl; 
    std::cout<< std::scientific<<m_value <<std::endl; 
}
int main() 
{
    Storage<int,char> ivalue(8u,'A');
    Storage<int,double> dvalue(9,6.7);
    ivalue.print();
    //dvalue.print();
}

