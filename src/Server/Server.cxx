#include "Server.hpp"
#include "Common.hpp"
#include <stacktrace>
GAWWebFramework::Server::Server(GAWWebFramework::ServerSettings settings) 
	:_settings(settings)
{

}
GAWWebFramework::Server::Server(ServerSettings settings, ServerContent content) 
	:_settings(settings),
	_content({ content })
{

}
void GAWWebFramework::Server::LoadContent(GAWWebFramework::ServerContent content)
{
	this->_content.push_back( content);
}
void GAWWebFramework::Server::ServeContent()
{

}
void GAWWebFramework::ServerSettings::SetPort(int x) 
{
	this->_port = x;
}
int GAWWebFramework::ServerSettings::GetPort()
{
	return this->_port;
}
GAWWebFramework::IpAddr GAWWebFramework::ServerSettings::GetAddr()
{
	return this->_addr;
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
	Logger::LogSeverity level(Logger::_LogSeverity::SEVERE);

	DEBUG_LOG(level, "Load was not defined!");
}


//server stuff

void GAWWebFramework::Server::HandleService(std::string str)
{
	for (auto st : this->_content)
	{
		if (st.GetServiceString() == str)
		{
			st.Load();

		}
	}
}