#include "Server.hpp"
#include "Common.hpp"
#include <stacktrace>
GAWWebFramework::Server::Server(GAWWebFramework::ServerSettings settings)
{

}
void GAWWebFramework::ServerSettings::setPort(int x) 
{
	this->_port = x;
}
int GAWWebFramework::ServerSettings::getPort()
{
	return this->_port;
}
void GAWWebFramework::ServerSettings::_ConstructAddr(int port, std::string addr) 
{
	using boost::asio::ip::make_address;

	if (addr == "")
	{
		
		this->_addr = make_address(GAWWebFramework::CommonFunctions::GetLocalIp(GAWWebFramework::context));
		
	}
	else 
	{
		this->_addr = make_address(addr);
		
	}
}
GAWWebFramework::ServerSettings::ServerSettings(int port , std::string addr)
{
	this->_ConstructAddr(port, addr);
}
void GAWWebFramework::ServerContent::Load() 
{
#ifdef DEBUG

#endif // DEBUG
	DEBUG_LOG(4, "Load was not defined!");

	throw std::runtime_error("GAWWebFramework::ServerContent::Load");
}