#ifndef NETWORK_HTTPSERVER_CONNECTION_H_
#define NETWORK_HTTPSERVER_CONNECTION_H_

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "reply.hpp"
#include "request.hpp"
#include "request_handler.hpp"
#include "request_parser.hpp"


namespace network {

class ConnectManager;

class Connection: public std::enable_shared_from_this<Connection>,
private boost::noncopyable
{
public:
	explicit Connection(boost::asio::io_service& io_service,
			ConnectManager& manager, request_handler& handler);
	virtual ~Connection();
	boost::asio::ip::tcp::socket& socket();
	void start();
	void stop();

private:
  void handle_read(const boost::system::error_code& e,
      std::size_t bytes_transferred);

  void handle_write(const boost::system::error_code& e);

  boost::asio::ip::tcp::socket socket_;
  ConnectManager& connectionManager_;
  request_handler& requestHandler_;
  boost::array<char, 8192> buffer_;
  request request_;
  request_parser requestParser_;
  reply reply_;


};

typedef std::shared_ptr<Connection> ConnectionPtr;

} /* namespace network */

#endif /* NETWORK_HTTPSERVER_CONNECTION_H_ */
