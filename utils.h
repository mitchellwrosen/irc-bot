#ifndef _UTILS_H_
#define _UTILS_H_

#include <sys/socket.h>
#include <sys/types.h>

namespace utils {

void* get_in_addr(struct sockaddr* addr);

} // namespace utils

#endif  // _UTILS_H_
