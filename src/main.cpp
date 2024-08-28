// GamersAgainstWeedWebsiteCPlusPlus.cpp : Defines the entry point for the application.
//

#include "Server/Server.hpp"
#include "Server/SockCom.hpp"
#include <functional>
int main()
{
	GAWWebFramework::IoContext io_context;

	GAWWebFramework::ServerSettings server_settings = {
		8080, GAWWebFramework::CommonFunctions::GetLocalIp(io_context)
	};
	GAWWebFramework::Server server(server_settings);
	GAWWebFramework::SockComFactory factory{GAWWebFramework::SockComFactory::SocketEnum::IPC};
	server.LoadContent(factory);
	server.ServeContent();
	//server.HandleService("http");
	return 0;
}
