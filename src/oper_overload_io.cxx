#include <iostream>

class Point
{
    int x_co;
    int y_co;
    int z_co;

public:
    Point():
        x_co(0), y_co(0), z_co(0)
    {
        std::cout<<"Default Point Initialized"<<std::endl;  
    }

    Point(int x, int y, int z):
        x_co(x), y_co(y), z_co(z)
    {
        std::cout<<"Point Initialized"<<std::endl;  
    }

    Point( const Point & ref )
    {
        x_co = ref.x_co;
        y_co = ref.y_co;
        z_co = ref.z_co;
    }

    friend std::ostream& operator << ( std::ostream & out, const Point &point )
    {
        out<< "Point ["<<point.x_co<<","<<point.y_co<<","<<point.z_co<<"]";
        return out;
    }

    friend std::istream& operator >> ( std::istream & in, Point &point )
    {
        std::cout<< "Enter X,Y,Z values for Point"<<std::endl; 
        in>> point.x_co;
        in>> point.y_co;
        in>> point.z_co;
        return in;
    }

};


int main()
{
    Point p(4,4,4);
    std::cout<< p << std::endl; 

    std::cout<<"Get Point From Terminal"<<std::endl; 
    Point p2;
    std::cin>>p2;
    std::cout<< "Print P2"<<p2 << std::endl; 
}
