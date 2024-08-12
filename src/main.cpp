// GamersAgainstWeedWebsiteCPlusPlus.cpp : Defines the entry point for the application.
//

#include "Server/Server.hpp"

#include <functional>
int main()
{
	GAWWebFramework::IoContext io_context;

	GAWWebFramework::ServerSettings server_settings = {
		8080, GAWWebFramework::CommonFunctions::GetLocalIp(io_context)
	};
	GAWWebFramework::Server server(server_settings);
	server.LoadContent();
	server.
	return 0;
}
