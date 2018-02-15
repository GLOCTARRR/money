#ifndef HTTP_HEADER_HPP
#define HTTP_HEADER_HPP

#include <string>

namespace network {

struct Header
{
  std::string name;
  std::string value;
};

} // network

#endif // HTTP_HEADER_HPP
