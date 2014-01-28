//
//  socket_util.h
//  portScanner
//
//  Created by Seth Wimberly on 1/26/14.
//  Copyright (c) 2014 Seth Wimberly. All rights reserved.
//

#ifndef __portScanner__socket_util__
#define __portScanner__socket_util__

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
//#include <netinet/ether.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <fcntl.h>

enum errors {CAN_CONTINUE, CANNOT_CREATE_SOCKET, CANNOT_SET_SOCKET_TO_NONBLOCKING_MODE, SETSOCKOPT_ERROR, SENDTO_ERROR};

void create_raw_socket(int * sock, int protocol, errors &error);

#endif /* defined(__portScanner__socket_util__) */
