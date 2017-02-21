#include <iostream>

class Base
{
public:
	void identify()
	{
		std::cout<<"I am base"<<std::endl;
	}

	void identify1()
	{
		std::cout<<"base identify1"<<std::endl;
	}
};

class Derived: public Base
{
public:
	void identify()
	{
		std::cout<<"I am Derived"<<std::endl;
	}

	void identify1(int n)
	{
		std::cout<<"base identify1 :"<<n<<std::endl;
	}
};

int main()
{

	Derived d ;
	d.identify();

	Base b;
	b.identify();

	d.identify1(1);
	b.identify1();
	
	d.identify1();
}
