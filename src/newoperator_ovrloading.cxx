#include <iostream> 
#include <string>
#include <cstdlib>

class Object
{
    std::string name;

public:

    Object( std::string nm )
        :name(nm)
    {

    }

    void* operator new( size_t size );

    void operator delete( void * );

};

void* Object::operator new( size_t size )
{
    std::cout<<"My New"<<std::endl; 

    void *ptr = malloc(size);
    return ptr;
}

void Object::operator delete( void *ptr )
{
    std::cout<< "My Delete"<<std::endl; 
    free(ptr);
}


int main()
{

    Object obj("Gajanan");

    Object *pobj = new Object("Patil:");
    delete pobj;

}
