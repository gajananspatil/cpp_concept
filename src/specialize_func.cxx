#include <iostream>
#include <cstdio>
using namespace std;

template <typename T>
T add(T x, T y)
{
    cout << "Normal template\n";
    return x+y;
}

// specialized function
template<>
char add<char>(char x, char y)
{
    cout << "Specialized template\n";
    int i = x-'0';
    int j = y-'0';
    return i+j;
}

int main()
{
    int a = 1, b = 2;
    cout << add(a, b) << endl;

    double c = 3.0, d = 5.5;
    cout << add(c,d) << endl;

    char e='e', f='f';
    cout << add(e,f);

    std::cout<< std::endl;
    return 0;
}
