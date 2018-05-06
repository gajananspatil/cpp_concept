#include <iostream>
#include <memory>

class Investment 
{
private:
    std::string name;

public:
    std::string getClassName(){return name;}

    Investment(std::string nm):name(nm)
    {}
};

class Stock:public Investment 
{
public:
    Stock(std::string nm):
    Investment(nm),
    ticker(nm){ }
    std::string getTicker(){return ticker;}

private:
    std::string ticker;
};

class Bond:public Investment
{
public: 
    Bond(std::string nm):
    Investment(nm){ }
};

class RealEstate:public Investment
{
public: 
    RealEstate(std::string nm):
    Investment(nm){ }
};

auto InvestmentDeleter = [] (Investment *pInvestment){
        std::cout<<"Delete Investment:"<<pInvestment->getClassName()<<std::endl;
        delete pInvestment;
};

template <typename T>
std::unique_ptr<Investment,decltype(InvestmentDeleter)>
makeInvestment(T&& name)
{
    std::unique_ptr<Investment,decltype(InvestmentDeleter)> pInv(nullptr,InvestmentDeleter);

    if( !name.compare("Stock") )
        pInv.reset( new Stock(std::forward<T>(name) ));
    else if( ! name.compare("Bond") )
        pInv.reset( new Bond(std::forward<T>(name) ));
    else if( ! name.compare("RealEstate") )
        pInv.reset( new RealEstate(std::forward<T>(name) ));
    else
        std::cout<<"Invalid Investment"<<std::endl;

    return pInv;
}

int main()
{
   auto pStk=::makeInvestment(static_cast<std::string>("Stock"));//->getName()<<std::endl; 
   //std::cout<<pStk->getTicker()<<std::endl;
   ::makeInvestment(static_cast<std::string>("Bond"));//.getName(); 
   ::makeInvestment(static_cast<std::string>("RealEstate"));//.getName(); 
}
