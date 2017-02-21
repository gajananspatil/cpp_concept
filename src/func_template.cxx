#include <iostream> 

template <typename type1>
type1 getmax(type1 var1, type1 var2)
{
    return var1>var2?var1:var2;
}

int main() 
{
    std::cout<<getmax(6,9)<<std::endl; 
    std::cout<<getmax(6.7f,9.1f)<<std::endl; 
    std::cout<<getmax(91.9d,44.5d)<<std::endl; 
    std::cout<<getmax('a','B')<<std::endl; 
    std::cout<<getmax("Gajanan","Gbajanan")<<std::endl; 
}
