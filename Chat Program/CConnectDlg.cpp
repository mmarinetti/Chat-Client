/*!
 * \file CConnectDlg.cpp
 *
 * \author Enter_your_name_here
 */

#include "CConnectDlg.h"

#include <sstream>

BEGIN_EVENT_TABLE(CConnectDlg, wxDialog)
	EVT_BUTTON(ID_Close, CConnectDlg::OnCloseButton)
	EVT_BUTTON(ID_Connect, CConnectDlg::OnConnectButton)
END_EVENT_TABLE()

CConnectDlg::CConnectDlg(CFrame *parent, CClient *client) :
wxDialog(parent, wxID_ANY, L"Connect",
		wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE),
		mFrame(parent), mClient(client)
{
	// Create a vertical sizer so we have a top part of the box
	// for the options and a bottom part for the Ok and Cancel buttons
	wxBoxSizer* vSizer;
	vSizer = new wxBoxSizer( wxVERTICAL );

	// Create the grid sizer for the controls that edit the parameters
	wxGridSizer *gSizer = new wxGridSizer(2);
	vSizer->Add(gSizer, 0, wxALL | wxEXPAND, 20);

	wxStaticText *label1 = new wxStaticText( this, wxID_ANY, L"Server Ip:", wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	gSizer->Add( label1, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL);

	std::wstringstream str2;
	mServerIp = new wxTextCtrl( this, ID_ServerIp, str2.str().c_str(), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer->Add( mServerIp, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL);
	mServerIp->ChangeValue(L"127.0.0.1");

	wxStaticText *label2 = new wxStaticText( this, wxID_ANY, L"Username:", wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	gSizer->Add( label2, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL);

	std::wstringstream str3;
	mUsername = new wxTextCtrl( this, ID_Username, str3.str().c_str(), wxDefaultPosition, wxDefaultSize, 0 );
	mUsername->SetFocus();
	gSizer->Add( mUsername, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL);

	// Create a horizontal sizer that will hold the Ok and Cancel buttons
	// and add it to the vertical sizer
	wxBoxSizer *hSizer;
	hSizer = new wxBoxSizer(wxHORIZONTAL);
	vSizer->Add(hSizer, 0, wxALL | wxEXPAND);

	mCloseButton = new wxButton( this, ID_Close, L"Close", wxDefaultPosition, wxDefaultSize, 0 );
	hSizer->Add(mCloseButton, 1, wxALL | wxEXPAND);

	mConnectButton = new wxButton(this, ID_Connect, L"Connect", wxDefaultPosition, wxDefaultSize, 0);
	hSizer->Add(mConnectButton, 1, wxALL | wxEXPAND);
	mConnectButton->SetDefault();

	// Set the top level sizer and force the window to match the size
	this->SetSizer( vSizer );
	this->Layout();
	vSizer->Fit( this );
}

CConnectDlg::~CConnectDlg()
{
	// TODO Auto-generated destructor stub
}

/*! Handle a Cancel button press
 * \param event The command event
 */
void CConnectDlg::OnCloseButton(wxCommandEvent &event)
{
	EndModal(wxCANCEL);
}

void CConnectDlg::OnConnectButton(wxCommandEvent &event)
{
	char ip[128];
	char usr[256];
	strncpy(ip, (const char*)mServerIp->GetValue().mb_str(), 127);
	strncpy(usr, (const char*)mUsername->GetValue().mb_str(), 255);
	if(ip == NULL || mServerIp <= 0)
	{
		mServerIp->SetFocus();
		return;
	}

	mClient->SetServerName(ip);
	mClient->SetUsername(usr);
	mClient->Connect();
	EndModal(wxOK);
}

