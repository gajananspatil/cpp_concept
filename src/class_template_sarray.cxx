#include <iostream> 

namespace tmp
{
    template <typename type,size_t size>
    class Array
    {
        type m_arr[size];
    public:

        /*
        Array( const Array &arr)
        {
            for(size_t i=0;i < size; i++)
                m_arr[i] = arr.m_arr[i];
        }
        */
        
        ~Array()
        {
            std::cout<< "Destructor"<<std::endl; 
        }

        type& operator[](int index)
        {
            return m_arr[index]; 
        }

        type at(int index)
        {
            return m_arr[index]; 
        }

    };

}

using namespace tmp;
int main()
{
    Array<int,10> arr;

    for(int i=0;i<10;i++)
        arr[i]=i;

    for(size_t i=0;i < 10; i++)
        std::cout<< arr[i]<<",";

    Array<char,10> arr1;

    for(int i=0;i<10;i++)
        arr1[i]=i+97;

    for(size_t i=0;i < 10; i++)
        std::cout<< arr1[i]<<",";
    return 0;
}
