#include <iostream>
#include <type_traits>

template <typename T>
int check_size(T var)
{
    static_assert(sizeof(T)>8,"Size is to small");
    return 0;

}

struct sm {

    double a;
    double b;
};
int main()
{
    int i=0;
    sm a;
    check_size(a);
}
