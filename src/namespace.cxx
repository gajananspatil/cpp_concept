#include <iostream> 
namespace {

    void print( int n )
    {
        std::cout<<"No: "<<n<<std::endl;;
    }

}

namespace {

    void show( int n )
    {
        std::cout<< "Number: "<<n<<std::endl; 
    }
}


int main()
{

    print(6);
    show(7);
}
