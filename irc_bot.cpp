#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "irc_bot.h"
#include "utils.h"

IRCBot::IRCBot() {
}

IRCBot::~IRCBot() {
}

void IRCBot::Connect(const struct addrinfo* hints) {
  Client::Connect(kDefaultService, kDefaultNode, hints);
}

void IRCBot::Connect(const char* node, const char* service,
    const struct addrinfo* hints) {
  Client::Connect(node, service, hints);

  //if (user_)
  // Send(MSG_USER);
  //if (nick_)
  //  Send(MSG_NICK);
}

/*
void IRCBot::SetUser(char* user) {
  user_ = user;

  if (connected_)
    Send(USER, user_);
}

void IRCBot::SetNick(char* nick) {
  nick_ = nick;

  if (connected_)
    Send(NICK, nick_);
}
*/

//void IRCBot::Send(const char* type, char* arg1) {
//  int wlen = snprintf(buf_, sizeof(buf_), "%s);
//}

void IRCBot::Run() {
  snprintf(buf_, sizeof(buf_), "USER %s 0 * :%s\r\n", "my_test_nick_nameee",
      "testOwner");
  send(sock_, buf_, strlen(buf_), 0);
  snprintf(buf_, sizeof(buf_), "NICK %s\r\n", "mytestnicknameee");
  send(sock_, buf_, strlen(buf_), 0);
  snprintf(buf_, sizeof(buf_), "JOIN %s\r\n", "#bestfriendsclub");
  send(sock_, buf_, strlen(buf_), 0);

  int rlen;
  while ((rlen = recv(sock_, buf_, sizeof(buf_), 0))) {
    if (rlen == -1) {
      perror("recv");
      exit(EXIT_FAILURE);
    }

    fprintf(stdout, "~~Received %d bytes~~\n", rlen);
    buf_[rlen] = '\0';
    fputs(buf_, stdout);

    // Respond to pings.
    if (!strncmp(buf_, "PING ", 5)) {
      buf_[1] = 'O';
      send(sock_, buf_, strlen(buf_), 0);
    }

    snprintf(buf_, sizeof(buf_), "test message\n");
    send(sock_, buf_, strlen(buf_), 0);
  }
}
