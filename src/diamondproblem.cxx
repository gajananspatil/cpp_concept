#include <iostream>

using namespace std;

class PoweredDevice
{
public:
	void show(){ cout<<"PowerDevice"<<endl;};
};
 
class Scanner: public PoweredDevice
{
public:
	void show(){ cout<<"Scanner"<<endl;};
};
 
class Printer: public PoweredDevice
{
public:
	void show(){ cout<<"Printer"<<endl;};
};
 
class Copier: public Scanner, public Printer
{
public:
	void show(){ 
		PoweredDevice::show();
		cout<<"Copier"<<endl;
	};
};

int main()
{
	Copier c ;
	c.show();
}
