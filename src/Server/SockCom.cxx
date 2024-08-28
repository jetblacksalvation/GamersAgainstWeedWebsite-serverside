#include "SockCom.hpp"

GAWWebFramework::SockComFactory::SockComFactory(SocketEnum)
{
	base_socket = boost::asio::generic::stream_protocol::socket(GAWWebFramework::context, boost::asio::generic::stream_protocol(AF_UNIX, 0));
};