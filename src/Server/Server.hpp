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
		IpAddr GetAddr();
		ServerSettings(int port, std::string addr);
	private:
		void _ConstructAddr(int port, std::string addr);
		int    _port;
		IpAddr _addr;

	};
	class ServerContentSettings
	{

	};
	class ServerContent 
	{
	public:
		/*
		ACTS as constructor
		*/
		virtual void Load();
		virtual const std::string GetServiceString() 
		{
			return  std::string("");
		};
		/*
			By Convention Deploy should spawn a new thread but doesn't need to... ovveride is EXPECTED to eventually return
		*/
		virtual void Deploy(GAWWebFramework::IoContext&, ServerSettings const&) {};
	private:

	};
	class Server 
	{
	public:
		Server(ServerSettings settings);
		Server(ServerSettings settings, ServerContent content);

		void LoadContent(ServerContent content);
		void HandleService(std::string service);
		void ServeContent();
	private:
		ServerSettings _settings;
		std::vector<ServerContent>  _content; 
	};

}
#endif // GAMERSAGAINSTWEEDSERVER
