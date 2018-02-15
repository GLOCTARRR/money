#ifndef NETWORK_HTTPSERVER_HTTPSERVER_H_
#define NETWORK_HTTPSERVER_HTTPSERVER_H_

#include <boost/asio.hpp>
#include <string>
#include <boost/noncopyable.hpp>
#include "connection.h"
#include "connectmanager.h"
#include "requesthandler.h"

namespace network {

class HttpServer : private boost::noncopyable {
public:
	explicit HttpServer(const std::string& address, const std::string& port,
	      const std::string& doc_root);

	virtual ~HttpServer();

	void run();

private:
	void start_accept();
	void handle_accept(const boost::system::error_code& e);
	void handle_stop();

	boost::asio::io_service io_service_;
	boost::asio::signal_set signals_;
	boost::asio::ip::tcp::acceptor acceptor_;
	ConnectManager connection_manager_;
	ConnectionPtr new_connection_;
	RequestHandler request_handler_;
};

} /* namespace network */

#endif /* NETWORK_HTTPSERVER_HTTPSERVER_H_ */
