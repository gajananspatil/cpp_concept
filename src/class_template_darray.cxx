#include <iostream> 

namespace tmp
{
    template <typename type>
    class Array
    {
        type *m_arr;
        size_t length;
    public:
        Array(size_t len)
        {
            m_arr = new type[len];
            length = len;
        }

        Array( const Array &arr)
        {
            length = arr.length;
            m_arr = new type[length];
            for(size_t i=0;i < length; i++)
                m_arr[i] = arr.m_arr[i];
        }
        
        ~Array()
        {
            delete[] m_arr;
        }

        type& operator[](int index)
        {
            if(index<0||index>=length)
                throw 2;
            return m_arr[index]; 
        }

        type at(int index) const
        {
            if(index<0||index>=length)
                throw 2;
            return m_arr[index]; 
        }

        friend std::ostream& operator << (std::ostream &out, const Array &arr)
        {
            for(int i=0;i<arr.length;i++)
                out<<arr.at(i)<<",";
            out<< std::endl; 
            return out;
        }
    };

}

using namespace tmp;
int main()
{
    Array<int> arr(10);

    for(int i=0;i<10;i++)
        arr[i]=i;
    std::cout<< arr;
    Array<char> arr1(10);

    for(int i=0;i<10;i++)
    {
        arr1[i]=i+97;
    }
    std::cout<< arr1;
}
