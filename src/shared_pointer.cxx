#include <iostream> 

namespace Feb_14
{
    template <typename ptrtype>
        class shared_ptr
    {
        ptrtype *sharedptr;
        unsigned *refcount;
    
    public:
        explicit shared_ptr(ptrtype *t):
            sharedptr(t),
            refcount(new unsigned(0))
        {
            ++(*refcount);
        }
    
        shared_ptr( const shared_ptr &ptr ):
            sharedptr(ptr.sharedptr),
            refcount(ptr.refcount)
        {
            (*refcount)++;
        }
    
        shared_ptr& operator = (const shared_ptr & ptr)
        {
            if(this != &ptr )
            {
                // Handler current holding pointer
                --(*refcount);
                if( !(*refcount) )
                {
                    std::cout<< "Release Current Memory"<< std::endl  ;
                    delete sharedptr;
                    delete refcount;
                }

                sharedptr = ptr.sharedptr;
                refcount = ptr.refcount;
                ++(*refcount);
            }
            return *this;
        }
    
        ptrtype operator*()
        {
            return *sharedptr;
        }

        ptrtype* operator ->()
        {
            return sharedptr;
        }

        unsigned getrefcount() { return *refcount; }
    
        ~shared_ptr()
        {
            --(*refcount);
            std::cout<< "Destructor- refcount: "<<*refcount<<std::endl; 
            if( *refcount == 0)
            {
                std::cout<< "Destructor- Release memory"<<std::endl; 
                delete sharedptr;
                delete refcount;
                sharedptr = nullptr;
                refcount = nullptr;
            }
        }


    };

} 

int main()
{
    using namespace Feb_14;

    shared_ptr<int> ptrobj(new int(5));
    shared_ptr<int> ptrobj2(ptrobj);
    std::cout<< "refcount: "<<ptrobj.getrefcount()<<std::endl; 

    shared_ptr<int> ptrobj3(new int(6));
    std::cout<< "Get Value:" << *ptrobj3;
    ptrobj3 = ptrobj2;
    std::cout<< "refcount: "<<ptrobj.getrefcount()<<std::endl; 

}
