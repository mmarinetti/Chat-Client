/*!
 * \file CClient.h
 *
 * ** insert description here **
 *
 * \author Enter_your_name_here
 */

#pragma once
#ifndef CCLIENT_H_
#define CCLIENT_H_

class CFrame;

#include <cstdio>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define BUFLEN 256

class CClient
{
public:
	CClient(CFrame *f);
	virtual ~CClient();

	bool Connect();
	void Send_Message(char message[256]);
	void ReceiveMessages();
	void Close();

	void SetServerName(char *name) {tcp_server_name_str = name;}

	bool isConnected() {return mConnected;}

private:
	CFrame *mFrame;

    sockaddr_in          tcp_server_addr;
    int                  tcp_connection_fd;

    int                  bytes_received;
    int                  bytes_sent;

    char                 *tcp_server_name_str;
    unsigned short int   tcp_server_port;

    bool                 mConnected;

    struct packet {
    	char message[256];
    	char username[256];
    };

    packet mSendPacket;
    packet mReceivePacket;
};

#endif /* CCLIENT_H_ */
