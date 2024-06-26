// GAMERSAGAINSTWEED_SERVER
#ifndef GAMERSAGAINSTWEED_SERVER
#define GAMERSAGAINSTWEED_SERVER 

#include "Common.hpp"
// TODO: Reference additional headers your program requires here.
namespace GAWWebFramework 
{
	
	class ServerSettings 
	{
		//server defaults to tcp connection.

	public:
		void SetPort(int x);
		int  GetPort();
		ServerSettings(int port , std::string addr);
	private:
		void _ConstructAddr(int port, std::string addr);
		int    _port;
		IpAddr _addr;

	};
	class ServerContent 
	{
	public:
		virtual void Load();

	private:

	};
	class Server 
	{
	public:
		Server(ServerSettings settings);
		Server(ServerSettings settings, ServerContent content);

		void LoadContent(ServerContent content);
	private:
		ServerSettings _settings;
		ServerContent  _content; 
	};

}
#endif // GAMERSAGAINSTWEEDSERVER
