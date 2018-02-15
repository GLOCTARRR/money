#ifndef NETWORK_HTTPSERVER_CONNECTMANAGER_H_
#define NETWORK_HTTPSERVER_CONNECTMANAGER_H_

#include <set>
#include <boost/noncopyable.hpp>
#include "connection.h"

namespace network
{

class ConnectManager: private boost::noncopyable
{
public:
	ConnectManager();
	virtual ~ConnectManager();

	void start(ConnectionPtr connect);
	void stop(ConnectionPtr connect);
	void stop_all();

	private:
	  std::set<ConnectionPtr> connections_;
	};

} /* namespace network */

#endif /* NETWORK_HTTPSERVER_CONNECTMANAGER_H_ */
