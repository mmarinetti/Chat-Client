/*!
 * \file CFrame.cpp
 *
 * \author Michael Marinetti
 */

#include <sstream>
#include <iostream>
#include <string.h>

#include "CFrame.h"
#include "CConnectDlg.h"

BEGIN_EVENT_TABLE(CFrame, wxFrame)
	EVT_MENU(ID_Exit, CFrame::OnExit)
	EVT_MENU(ID_Connect, CFrame::OnConnect)
	EVT_BUTTON(ID_Enter, CFrame::OnSend)
END_EVENT_TABLE()

CFrame::CFrame() : wxFrame(NULL, -1, L"LULZ Mike I totally hacked your computer, I'm a 7331 haxxor skills", wxPoint(20, 20), wxSize(600, 400)), mClient(this),
	mReceiveThread(&mClient)
{
	// File Menu

	wxMenu *menuFile = new wxMenu;

	wxMenuItem *connectItem = menuFile->Append(ID_Connect, L"Connect");
	connectItem->SetHelp(L"Connect to chat server");

	menuFile->AppendSeparator();

	wxMenuItem *exitItem = menuFile->Append(ID_Exit, L"E&xit");
	exitItem->SetHelp(L"Exit the program");

	// Menu Bar

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, L"&File");

	SetMenuBar(menuBar);

	CreateStatusBar();
	SetStatusText(L"Status");

	// Create a vertical sizer so we have a top part of the box
	// for the options and a bottom part for the Ok and Cancel buttons
	wxBoxSizer* vSizer;
	vSizer = new wxBoxSizer( wxVERTICAL );

	//Chat box
	wxBoxSizer *chatSizer;
	chatSizer = new wxBoxSizer(wxHORIZONTAL);
	vSizer->Add(chatSizer, 0, wxALL | wxEXPAND);

	std::wstringstream str1;
	mChatBox = new wxTextCtrl( this, ID_Chat, str1.str().c_str(), wxPoint(0, 0), wxSize(600, 280), wxALIGN_RIGHT );
	mChatBox->SetEditable(false);
	chatSizer->Add( mChatBox, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL);

	//Type box
	wxGridSizer *gSizer = new wxGridSizer(2);
	vSizer->Add(gSizer, 0, wxALL | wxEXPAND, 20);

	std::wstringstream str2;
	mMessage = new wxTextCtrl( this, ID_ChatBox, str2.str().c_str(), wxPoint(200, 280), wxSize(450, 40), 0 );
	gSizer->Add( mMessage, 0, wxCENTER);

	mEnterButton = new wxButton( this, ID_Enter, L"Send", wxPoint(500, 280), wxSize(100, 40), 0 );
	gSizer->Add(mEnterButton, 1, wxALIGN_RIGHT);
	mEnterButton->Enable(false);
	mEnterButton->SetDefault();

	// Set the top level sizer and force the window to match the size
	this->SetSizer( vSizer );
	this->Layout();
	//vSizer->Fit( this );
}

CFrame::~CFrame()
{
	// TODO Auto-generated destructor stub
}

/*! This function is called when an exit menu item is selected.
 *
 * It closes the main window, which ends the program.
 * \param event An object that describes the event.
 */
void CFrame::OnExit(wxCommandEvent& event)
{
	mReceiveThread.WaitForInternalThreadToExit();
	mClient.Close();
	Close(TRUE);
}

void CFrame::OnConnect(wxCommandEvent& event)
{
	CConnectDlg dlg(this, &mClient);
	dlg.ShowModal();

	if(mClient.isConnected()) {mEnterButton->Enable(true);}

	mReceiveThread.StartInternalThread();
}

void CFrame::OnSend(wxCommandEvent& event)
{
	char message[256];
	strncpy(message, (const char*)mMessage->GetValue().mb_str(), 255);
	if(message == NULL || mMessage <= 0)
	{
		mMessage->SetFocus();
		return;
	}

	//std::string m = std::string(message);
	mClient.Send_Message(message);
	mMessage->Clear();
}

void CFrame::AddtoTextBox(char *t)
{

}

