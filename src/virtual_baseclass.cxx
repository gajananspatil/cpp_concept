#include <iostream>

class PoweredDevice
{
    public:
        PoweredDevice(int power)
        {
            std::cout<< "Powered Device:"<<power<<std::endl; 
        }
};

class Scanner:virtual public PoweredDevice
{
    public:
        Scanner(int scanner,int power):
            PoweredDevice(power)
        {
            std::cout<< "Scanner "<<scanner<<std::endl; 
        }
};

class Copier:public Scanner
{
    public:
        Copier(int copier, int scanner, int power):Scanner(scanner, power),
                                                   PoweredDevice(power)
        {
            std::cout<<"Copier"<<copier<<std::endl; 
        }
};

int main() 
{
    Copier c(1,2,3);
}
