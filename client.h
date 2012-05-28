#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

class Client {
 public:
  Client();
  ~Client();

  void Connect(const char* node, const char* service,
      const struct addrinfo* hints);

 protected:
  int sock_;
  bool connected_;

 private:

};

#endif  // _IRC_BOT_H_
