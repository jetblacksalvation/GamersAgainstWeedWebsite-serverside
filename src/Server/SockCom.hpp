//WEBPLUSPLUS_SOCKCOM
#ifndef WEBPLUSPLUS_SOCKCOM
#include "Common.hpp"
#include "Server.hpp"
#include <boost/asio.hpp>
/*
	SockComFactory is used to wrap ISockStream with SocketModel
*/
namespace GAWWebFramework 
{
	class SockComFactory : public ServerContent
	{
	public:
		enum class SocketEnum
		{
			IPC,
			TCP
		};
		SockComFactory(SocketEnum);
		void PopulateSocket(SocketEnum);
		void Load() override
		{
			
		}
		const std::string GetServiceString() override 
		{
			return ("http");
		};
		void Deploy(GAWWebFramework::IoContext& io_context, ServerSettings const& server_settings) override
		{
			/*
				TODO add code that binds to socket and sends html content 
			*/
		}
	private:
		boost::asio::generic::stream_protocol::socket base_socket{ GAWWebFramework::context };

	};
}



#define WEBPLUSPLUS_SOCKCOM
#endif