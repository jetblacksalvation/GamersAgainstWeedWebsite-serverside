// GAMERSAGAINSTWEEDSERVER
#ifndef GAMERSAGAINSTWEEDSERVER
#define GAMERSAGAINSTWEEDSERVER 

#include "Common.hpp"
// TODO: Reference additional headers your program requires here.
namespace GAWWebFramework 
{
	
	class ServerSettings 
	{
		//server defaults to tcp connection.

	public:
		void setPort(int x);
		int  getPort();
		ServerSettings(int port , std::string addr);
	private:
		void _ConstructAddr(int port, std::string addr);
		int    _port;
		IpAddr _addr;

	};
	class Server 
	{
	public:
		Server(ServerSettings settings);
	private:

	};

}
#endif // GAMERSAGAINSTWEEDSERVER
