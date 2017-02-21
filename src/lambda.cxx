#include <iostream> 

int main()
{
    int x = 15;

    auto y = [=] (int n){ return n*x; } ;

    std::cout<< y(9);
}
