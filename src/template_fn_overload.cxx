#include <iostream> 

template <typename T>
const T& max( const T& a, const T& b)
{
    std::cout<< "max 2"<<std::endl; 
    return (a>b ? a: b);
}


template <typename T>
const T& max( const T& a, const T& b, const T& c)
{
    std::cout<< "max 3"<<std::endl; 
    return  max(max(a,b),c);
}


int main()
{

    int a = 9, b =7, c= 99;

    std::cout<< "max (a,b):"<<max(a,b)<<std::endl; 
    std::cout<< "max (a,b,c):"<<max(a,b,c)<<std::endl;

}
