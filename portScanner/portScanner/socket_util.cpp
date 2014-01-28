//
//  socket_util.cpp
//  portScanner
//
//  Created by Seth Wimberly on 1/26/14.
//  Copyright (c) 2014 Seth Wimberly. All rights reserved.
//

#include "socket_util.h"

using namespace std;


/*
 * Create a raw socket
 */
void create_raw_socket(int * sock, int protocol, errors &error)
{
    *sock = socket(AF_INET, SOCK_RAW, protocol);
    
    if (*sock == -1) {
        cout<<"cannot create socket"<<endl;
        error = CANNOT_CREATE_SOCKET;
        exit(1);
    }
    else {
        // make socket thread safe using fcntl, by setting socket to be non blocking
        if (fcntl(*sock, F_SETFL, O_NONBLOCK) < 0) {
            // unable to set socket to non blocking -- error
            cout<<"Unable to set socket to non blocking mode"<<endl;
            error = CANNOT_SET_SOCKET_TO_NONBLOCKING_MODE;
            exit(1);
        }
        else {
            int one = 1;
            const int *one_val = &one;
            
            //use setsockopt to let the kernal know that the header is included in the packet
            //and it should not build the header
            if (setsockopt(*sock, IPPROTO_IP, IP_HDRINCL, one_val, sizeof(one)) < 0) {
                error = SETSOCKOPT_ERROR;
                cout<<"SETSOCKOPT error"<<endl;
                exit(1);
            }
            
        }
    }
    
}

void create_tcp_packet(uint8_t *datagram, uint16_t datagram_length, char *ipaddress, int port, char *primary_ip_address, struct sockaddr_in &destination_sockaddr_in, scan_type type_of_scan, uint current_time, uint16_t IP_id, int tcp_sequence)
{
    
}