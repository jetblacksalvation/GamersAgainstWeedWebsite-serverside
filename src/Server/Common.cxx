#include "Common.hpp"

std::string GAWWebFramework::CommonFunctions::GetLocalIp(IoContext& io_context)
{
    TcpResolver resolver(io_context);
    TcpResolver::query query(boost::asio::ip::host_name(), "");
    TcpResolver::iterator iter = resolver.resolve(query);
    TcpResolver::iterator end;

    while (iter != end) {
        TcpEndpoint ep = *iter++;
        boost::asio::ip::address addr = ep.address();
        if (addr.is_v4() && !addr.is_loopback()) { // We only want non-loopback IPv4 addresses
            return addr.to_string();
        }
    }

    return "127.0.0.1"; // Default to localhost if no suitable address is found
}
 bool GAWWebFramework::CommonFunctions::isDebug() 
{
#ifndef DEBUG

    const bool isDefinedDebug = false;
#endif
#ifdef DEBUG
    const bool isDefinedDebug = true;
#endif // DEBUG
    return isDefinedDebug;
}