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

#include "debug.h"
#include "irc_bot.h"

void check_args(int argc, char** argv);

int main(int argc, char** argv) {
  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  IRCBot* bot = new IRCBot();

  if (argc == 3)
    bot->Connect(argv[1], argv[2], &hints);
  else
    bot->Connect(&hints);

  delete bot;
}
