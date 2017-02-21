#include <iostream>


class Base
{
	int m_val;
public:
	Base(int val = 5):
		m_val(val)
	{

	}
	int getvalue() {return m_val; }
};

class Derived:public Base
{
	using Base::getvalue;
public:

	void show() { std::cout<<"Value "<<getvalue()<<std::endl;}
};

int main()
{
	Derived d ;
	d.show();

	Base b;
	std::cout<<"using getvalue "<<b.getvalue()<<std::endl;

	d.getvalue();

}
