#ifndef _IRC_BOT_H_
#define _IRC_BOT_H_

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

class IRCBot {
 public:
  IRCBot();
  ~IRCBot();

  bool Connect(const char* node, const char* service,
      const struct addrinfo* hints);

 private:
  int sock_;

};

#endif  // _IRC_BOT_H_
