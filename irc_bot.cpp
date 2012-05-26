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
  close(sock_);
}

bool IRCBot::Connect(const char* node, const char* service,
    const struct addrinfo* hints) {
  struct addrinfo* server_info;
  struct addrinfo* p;
  char server_str[INET6_ADDRSTRLEN];

  int ret;
  if ((ret = getaddrinfo(node, service, hints, &server_info))) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
    exit(EXIT_FAILURE);
  }

  for (p = server_info; p != NULL; p = p->ai_next) {
    if (-1 == (sock_ = socket(p->ai_family, p->ai_socktype, p->ai_protocol))) {
      perror("socket");
      continue;
    }

    if (-1 == connect(sock_, p->ai_addr, p->ai_addrlen)) {
      close(sock_);
      perror("connect");
      continue;
    }

    break;
  }

  EXIT_IF(p == NULL, "Failed to connect.\n");

  inet_ntop(p->ai_family, utils::get_in_addr((struct sockaddr*) p->ai_addr),
      server_str, INET6_ADDRSTRLEN);
  fprintf(stdout, "Connected to %s\n", server_str);

  freeaddrinfo(server_info);
}
