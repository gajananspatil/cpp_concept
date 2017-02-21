#include <iostream>
 
class USBDevice
{
private:
    long m_id;
 
public:
    USBDevice(long id)
        : m_id(id)
    {
    }
 
    long getID() { return m_id; }
};
 
class NetworkDevice
{
private:
    long m_id;
 
public:
    NetworkDevice(long id)
        : m_id(id)
    {
    }
 
    long getID() { return m_id; }
};
 
class WirelessAdaptor: public USBDevice, public NetworkDevice
{
public:
    WirelessAdaptor(long usbId, long networkId)
        : USBDevice(usbId), NetworkDevice(networkId)
    {
    }
};
 
int main()
{
    WirelessAdaptor c54G(5442, 181742);
    std::cout << c54G.getID(); // Which getID() do we call?
 
    return 0;
}
