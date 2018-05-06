// return const primitive data type, it does not make difference
#include <iostream> 

const int getNum( )
{
    static int num;
    return num++;
}

int main()
{

    std::cout<< getNum() <<std::endl; 
    int n = getNum();
    std::cout<< n <<std::endl; 
    std::cout<< ++n << std::endl; 
}
