#include <iostream>
#include <map>
#include <limits>

template <class K,class V>
class interval_map
{
    friend void IntervalMapTest();

private:
    std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (k_min,val)
    // into the map
    interval_map(V const &val)
    {
        m_map.insert(m_map.begin(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    void assign(K const &keyBegin, K const &keyEnd, V const&val) {
        auto keyEnd_lb=m_map.lower_bound(keyEnd);
        auto keyBegin_ub=m_map.upper_bound(keyBegin);

        if(keyBegin_ub ==m_map.end()) 
        {
            --keyBegin_ub;
            if(keyBegin_ub->second != val )
            {
                m_map[keyEnd]=keyBegin_ub->second;
                m_map[keyBegin]=val;
            }
        }
        else
        {
            prevPair=keyBegin_ub-1;
            if( keyBegin_ub->first > keyEnd && prevPair->first == )
            {
                
            }
                

            if( keyEnd_lb->first == keyEnd) 
                ;

        } 

    }
    V const& operator[](K const &key) const {
        return (--m_map.upper_bound(key))->second;
    }

    void print() {
        auto iter=m_map.begin();
        for(;iter != m_map.end(); ++iter)
            std::cout<<"("<<iter->first<<":"<<iter->second<<"),";
    }
};

int main()
{
    std::cout<<"Interval Map"<<std::endl;
    interval_map<unsigned,char> i_map('A');
    i_map.assign(4,9,'B');
    i_map.print();

    return 0;
}
