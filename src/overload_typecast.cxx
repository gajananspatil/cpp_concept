// Example program
#include <iostream>
#include <string>

class Rupees
{
    unsigned m_rs;
    
public:
    Rupees( unsigned rs )
    {
        m_rs = rs;
    }
    
    operator unsigned() { return m_rs; }
    
   friend std::ostream& operator<<( std::ostream& out, const Rupees& rs )
    {        out<<"Rs:"<<rs.m_rs;
        return out;
    }
    
    unsigned getRs(){return m_rs;}
};

using namespace std;
int main()
{
    Rupees rs( 100);
   // cout<<rs.getRs();
    cout<<rs;
}
