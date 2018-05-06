#include <iostream>
#include <string>

template <typename T>
void foo(T t=""){
    std::cout<<t<<std::endl;
}

template <typename T=std::string>
void bar(T t=""){

}
int main(){
    
    foo(1);
    foo("Gajanan");
    //foo(); ERROR Couldn't deduce template parameter ‘T’
    bar();
}
