#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "utils.h"

namespace utils {

void* get_in_addr(sockaddr* addr) {
  if (addr->sa_family == AF_INET)
    return &(((struct sockaddr_in*) addr)->sin_addr);

  return &(((struct sockaddr_in6*) addr)->sin6_addr);
}

} // namespace utils
