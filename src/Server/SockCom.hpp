//WEBPLUSPLUS_SOCKCOM
#ifndef WEBPLUSPLUS_SOCKCOM
#include "Common.hpp"
#include "Server.hpp"

/*
	SockComFactory is used to wrap ISockStream with SocketModel
*/
namespace GAWWebFramework 
{
	class SockComFactory : public ServerContent
	{
	public:
		void Load() override
		{
			
		}
		const std::string GetServiceString() override 
		{
			return ("Https");
		};
		void Deploy(GAWWebFramework::IoContext& io_context, ServerSettings const& server_settings) override
		{
			/*
				TODO add code that binds to socket and sends html content 
			*/
		}
	private:

	};
}



#define WEBPLUSPLUS_SOCKCOM
#endif