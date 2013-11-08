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

#include <wx/wx.h>

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

class CFrame;

#define BUFLEN 256

//Client Class
class CClient
{
public:
	CClient(CFrame *f);
	virtual ~CClient();

	bool Connect();
	void Send_Message(char message[256]);
	wxString ReceiveMessages();
	void Close();

	void SetServerName(char *name) {tcp_server_name_str = name;}
	void SetUsername(char usr[256]) {strncpy(mUser, usr, 255);}

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
    char mUser[256];
};

#endif /* CCLIENT_H_ */
