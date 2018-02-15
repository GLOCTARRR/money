#include "connectmanager.h"

namespace network {

void ConnectManager::start(ConnectionPtr connect)
{
  connections_.insert(connect);
  connect->start();
}

void ConnectManager::stop(ConnectionPtr connect)
{
  connections_.erase(connect);
  connect->stop();
}

void ConnectManager::stop_all()
{
  std::for_each(connections_.begin(), connections_.end(),
      boost::bind(&Connection::stop, _1));
  connections_.clear();
}

} /* namespace network */
