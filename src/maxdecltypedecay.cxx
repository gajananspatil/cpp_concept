#include <iostream>
#include <type_traits>

template<typename T1, typename T2>
auto max (T1 a, T2 b) -> typename std::decay<decltype(true?a:b)>::type
{ 
    return b < a ? a : b;
}

int main()
{
    std::cout<<max(5,6.7)<<std::endl;
}
