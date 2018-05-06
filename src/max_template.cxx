#include <iostream>


template<typename T>
T max(T a,T b){

    std::cout<<"My max:";
    return a < b?b:a;
}

int main()
{
    std::cout<<::max(5,6)<<std::endl;
    std::cout<<::max(9,6)<<std::endl;
    std::cout<<::max(14.2,16.5)<<std::endl;
    std::cout<<::max("Gajanan","Patil")<<std::endl;
}
