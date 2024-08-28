//WEBPLUSPLUS_COMMONFUNCIONS
#ifndef WEBPLUSPLUS_COMMONFUNCIONS
#define WEBPLUSPLUS_COMMONFUNCIONS
#include <boost/asio.hpp>
#include <string>
#include <stacktrace>
#include <iostream>
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
        bool isDebug();

        std::string GetLocalIp(IoContext& io_context);
        
        template<typename... Args>
        std::string formatString(Args... args) {
            std::ostringstream oss;
            (oss << ... << args); // Fold expression to append all arguments to the stream
            return oss.str();
        }


    }


}
// DEBUG_LOG macro definition


#ifndef DEBUG_LOG
//Severity as int or LogSeverity, ... as any types 

#define DEBUG_LOG(severity, ...) \
    std::string __currentTrace = std::to_string(std::stacktrace::current());                                                            \
    if (GAWWebFramework::CommonFunctions::isDebug() or Logger::LogSeverity(severity) == Logger::_LogSeverity::INFO)           \
    {                                                                                                          \
        if( 1 or Logger::LogSeverity(severity) == Logger::_LogSeverity::INFO)                                  \
        {                                                                                                      \
        std::string __msg = GAWWebFramework::CommonFunctions::formatString(__VA_ARGS__);                       \
        Logger::LogSeverity log(severity);                                                                     \
        std::cout << "DEBUG: " << __msg << " [File: " << __FILE__ <<                                           \
            ", Line: " << __LINE__ << "]" <<                                                                   \
            " STACK-TRACE: " << __currentTrace <<                                                              \
            " SEVERITY : " << log.GetSeverityAsString()<< std::endl;                                           \
        }                                                                                                      \
    }                                                                                                          \
    if (Logger::LogSeverity(severity) == Logger::_LogSeverity::SEVERE)                                         \
    {                                                                                                          \
      	throw std::runtime_error(GAWWebFramework::CommonFunctions::formatString(__VA_ARGS__));                 \
                                                                                                               \
    }                                                                                                          \
//there is a minor optimization here with the format string
// i dont care enough ab

#endif // !DEBUG_LOG
namespace Logger 
{
    enum class _LogSeverity {

        INFO = 0,
        SEVERE,
    };
    class LogSeverity 
    {
    public:
        LogSeverity(unsigned int x)
        {
            __LogSeverityEnum = (_LogSeverity)x;
        }
        LogSeverity(_LogSeverity severity)
        {
            __LogSeverityEnum = severity;
        }
        LogSeverity(LogSeverity& newSelf)
        {
            this->__LogSeverityEnum = newSelf.__LogSeverityEnum;
        }
        _LogSeverity GetSeverityAsEnumValue() 
        {
            return this->__LogSeverityEnum;
        };
        std::string GetSeverityAsString() const
        {
            switch (__LogSeverityEnum) 
            {
                case _LogSeverity::INFO:
                    return "INFO";
                    break;
                case _LogSeverity::SEVERE:
                    return "SEVERE";
                    break;
            }
            return "";
        }
        std::string GetSeverityAsString() 
        {
            switch (__LogSeverityEnum)
            {
            case _LogSeverity::INFO:
                return "INFO";
                break;
            case _LogSeverity::SEVERE:
                return "SEVERE";
                break;
            }
            return "";
        }
        static std::string GetSeverityFromChar(unsigned char x) 
        {
            static LogSeverity logSeverity(x);
            return logSeverity.GetSeverityAsString();
        }
        bool operator==(_LogSeverity const& rhs) const { return this->__LogSeverityEnum == rhs; }

    private:

        _LogSeverity __LogSeverityEnum; 
    };


};
#endif // !1