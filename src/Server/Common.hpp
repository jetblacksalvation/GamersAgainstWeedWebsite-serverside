//WEBPLUSPLUS_COMMONFUNCIONS
#ifndef WEBPLUSPLUS_COMMONFUNCIONS
#define WEBPLUSPLUS_COMMONFUNCIONS
#include <boost/asio.hpp>
#include <string>

namespace GAWWebFramework
{
    using IoContext = boost::asio::io_context;
    static inline boost::asio::io_context context;

    using IpAddr = boost::asio::ip::address;
    using TcpType = boost::asio::ip::tcp;
    using TcpAcceptor = boost::asio::ip::tcp::acceptor;
        
    using TcpEndpoint = boost::asio::ip::tcp::endpoint;
    using TcpResolver = boost::asio::ip::tcp::resolver;

    namespace CommonFunctions
    {
        std::string GetLocalIp(IoContext& io_context);
        
        
    }


}

#endif // !1