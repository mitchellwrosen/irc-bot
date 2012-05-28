#ifndef _IRC_BOT_H_
#define _IRC_BOT_H_

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "client.h"

const char kDefaultNode[] = "irc.freenode.net";
const char kDefaultService[] = "6667";

namespace msg {

const char NICK[] = "NICK";
const char PING[] = "PING";
const char PONG[] = "PONG";
const char PRIVMSG[] = "PRIVMSG";
const char USER[] = "USER";

} // namespace msg

class IRCBot : public Client {
 public:
  IRCBot();
  ~IRCBot();

  // Connect to the specified server, or the default.
  void Connect(const struct addrinfo* hints);
  void Connect(const char* node, const char* service,
    const struct addrinfo* hints);

  // Setters.
  //void SetUser(const std::string& user);
  //void SetNick(const std::string& nick);

  // Sends a message of the specified type with the specified arguments.
  void Send(char* type);
  void Send(char* type, char* arg1);
  void Send(char* type, char* arg1, char* arg2);

  void Run();


 private:
  char buf_[4096];

  char* user_;
  char* nick_;

};

#endif  // _IRC_BOT_H_
