#include <map>
#include <iostream>

using namespace std;
int main()
{
    map<int,char> intToChar;

    intToChar.insert(intToChar.begin(),make_pair(2,'B'));
    intToChar.insert(intToChar.begin(),make_pair(1,'A'));
    intToChar.insert(intToChar.begin(),make_pair(10,'J'));

    map<int,char>::iterator iter=intToChar.begin();
    for( ;iter != intToChar.end();++iter)
        std::cout<< iter->first<<":"<<iter->second<<std::endl; 

    iter=intToChar.lower_bound(0);
    if(iter != intToChar.end())
        std::cout<< "lb0-"<<iter->first<<":"<<iter->second<<std::endl; 
    else
        std::cout<< "(lb0)End of Map"<<std::endl; 


    iter=intToChar.upper_bound(0);
    if(iter != intToChar.end())
        std::cout<< "ub0-"<<iter->first<<":"<<iter->second<<std::endl; 
    else
        std::cout<< "ub(0)End of Map"<<std::endl; 


    iter=intToChar.lower_bound(1);
    if(iter != intToChar.end())
        std::cout<< "lb1-"<<iter->first<<":"<<iter->second<<std::endl; 
    else
        std::cout<< "lb(1)End of Map"<<std::endl; 


    iter=intToChar.upper_bound(1);
    if(iter != intToChar.end())
        std::cout<< "ub1-"<<iter->first<<":"<<iter->second<<std::endl; 
    else
        std::cout<< "ub(1)End of Map"<<std::endl; 


    iter=intToChar.lower_bound(11);
    if(iter != intToChar.end())
        std::cout<< "lb11-"<<iter->first<<":"<<iter->second<<std::endl; 
    else
        std::cout<< "lower_bound(11)End of Map"<<std::endl; 
        std::cout<<"before end:"<<(--iter)->first<<std::endl;


    iter=intToChar.upper_bound(2);
    if(iter != intToChar.end())
        std::cout<< "ub2-"<<iter->first<<":"<<iter->second<<std::endl; 
    else
        std::cout<< "upper_bound(2)End of Map"<<std::endl;                  // End Of Map


    iter=intToChar.lower_bound(2);
    if(iter != intToChar.end())
        std::cout<< "lb2-"<<iter->first<<":"<<iter->second<<std::endl; 
    else
        std::cout<< "lower_bound(2)End of Map"<<std::endl; 
}
