#include <iostream>
#include <vector>

// Implement Observer design pattern for some simple mathematical operations
//

class Observer
{

public:
        virtual void calculate(double val)= 0;
};


class Subject
{
    double rs_value;
    std::vector<Observer*> events;
public:
    Subject():
        rs_value(0)
    {
    }

    void attach(Observer *event)
    {
        events.push_back(event);

    }

    void update(double val)
    {
        rs_value = val;
        for(auto &it:events)
            it->calculate(rs_value);
    }
};

class DollerObserver:public Observer
{
    double dollar_value;
public:

    DollerObserver(Subject *sub, double val)
    {
        sub->attach(this);
        dollar_value = val;
    }

    void calculate(double val)
    {
        std::cout<< val <<" Rs = "<< dollar_value * val <<" dollars"<<std::endl; 
    }
};

class EuroObserver: public Observer
{
    double euro_value;
public:
    EuroObserver( Subject*sub, double val )
    {
        sub->attach(this);
        euro_value = val;
    }
    void calculate(double val)
    {
        std::cout<< val <<" Rs = "<< euro_value * val <<" Euros"<<std::endl; 
    }
};

// 0.1457 0.1371
//
// f
int main()
{
    Subject s;
    EuroObserver e1(&s,0.01457);
    DollerObserver d1(&s,0.01371);

    s.update( 68);
    s.update( 100 );
    s.update(136 );

}
