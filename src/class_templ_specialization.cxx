#include <iostream> 

template<typename type,unsigned size>
class Storage
{
    type m_value[size];
    unsigned m_size;
public:

    Storage()
    {
        m_size = size;
        for(int i=0;i<m_size;i++)
            m_value[i] = 0;
    }
    
    void set(type val, int index)
    {
        m_value[index] = val;
    }
    void print()
    {
        for(int i=0;i<size;i++)
            std::cout<< m_value[i]<<std::endl; 
    }

};

const unsigned BITS_PER_BYTE=8;
template<unsigned size>
class Storage<bool,size>
{
    unsigned char m_value[size/BITS_PER_BYTE+1];
    unsigned m_size; 
public:
    Storage()
    {
        m_size = size/BITS_PER_BYTE +1;
        for(int i=0;i<m_size;i++)
            m_value[0] = 0;
            
    }

    void set(bool value , int index)
    {
        int slot = index/BITS_PER_BYTE;
        int bit = index % BITS_PER_BYTE;
        if(slot > m_size || bit > (size % BITS_PER_BYTE))
        {
            std::cout<< "!! Index out of range!!"<<std::endl; 
            return;
        }
        unsigned char mask = 1<< bit;
        if( value )
            m_value[slot] |= mask;
        else

            m_value[slot] &= ~mask;

    }
    
    void print()
    {
        int bitcount = 0;
        for(int i=0; i< m_size; i++)
            for(int j=0; j< BITS_PER_BYTE && bitcount < size; j++,bitcount++)
                std::cout<< (((m_value[i]) & (1<<j)) == 0?0:1);

        std::cout<< std::endl; 
    }

};

/*
template<unsigned size>
void Storage<double,unsigned>::print()
{
    std::cout<< "double specification"<<std::endl; 
    std::cout<< std::scientific<<m_value <<std::endl; 
}
*/

int main() 
{
    Storage<int,2> ivalue;
    Storage<double,2> dvalue;
    ivalue.print();
//    dvalue.print();
    Storage<bool,5> bvalue;
    std::cout<< std::endl; 

    bvalue.print();
    bvalue.set(1,4);
    bvalue.set(1,3);
    bvalue.print();
    bvalue.set(0,3);
    bvalue.print();
}
