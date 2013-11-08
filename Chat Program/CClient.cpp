/*!
 * \file CClient.cpp
 *
 * \author Enter_your_name_here
 */

#include "CClient.h"
#include "CFrame.h"

using namespace std;

CClient::CClient(CFrame *f)
{
	tcp_server_name_str = 0;
	mConnected = false;
	mFrame = f;
}

CClient::~CClient()
{
	// TODO Auto-generated destructor stub
}

bool CClient::Connect()
{
	struct hostent *hostEnd = gethostbyname(tcp_server_name_str);

	tcp_connection_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(tcp_connection_fd < 0)
	{
		return false;
		//exit(1);
	}

	memset(&tcp_server_addr, 0, sizeof(tcp_server_addr));

    tcp_server_addr.sin_family = AF_INET;
    tcp_server_addr.sin_port = htons(12345);

    memcpy(&tcp_server_addr.sin_addr, hostEnd->h_addr, hostEnd->h_length);

    if(connect(tcp_connection_fd, (sockaddr *)&tcp_server_addr, sizeof(tcp_server_addr)) < 0)
    {
        cerr << "ERROR: Unable to connect to server." << endl;
        if(close(tcp_connection_fd) < 0)
        {
            cerr << "ERROR: Error when closing TCP socket." << endl;
        }
        return false;
        //exit(1);
    }

    mConnected = true;

	return true;
}

void CClient::Send_Message(char message[256])
{
	strncpy(mSendPacket.message, message, 256);
	strncpy(mSendPacket.username, mUser, 256);
    bytes_sent = send(tcp_connection_fd, &mSendPacket, sizeof(mSendPacket), 0);

    if(bytes_sent < 0)
    {
        cerr << "ERROR: Error sending message to server." << endl;
        exit(1);
    }
    else
    {
        cout << "[TCP] Sent: " << mSendPacket.message << endl;
    }
}

wxString CClient::ReceiveMessages()
{
	bytes_received = 0;
	while(bytes_received <= 0)
	{
		bytes_received = recv(tcp_connection_fd, &mReceivePacket, sizeof(mReceivePacket), 0);
	}

	wxString msg(mReceivePacket.message, wxConvUTF8);
	wxString usr(mReceivePacket.username, wxConvUTF8);
	return usr + L": " + msg + L"\n";
}

void CClient::Close()
{
    if(close(tcp_connection_fd) < 0)
    {
        cerr << "ERROR: Error when closing TCP socket." << endl;
    }
    exit(1);
}

