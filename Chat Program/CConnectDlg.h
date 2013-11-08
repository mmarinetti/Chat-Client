/*!
 * \file CConnectDlg.h
 *
 * ** insert description here **
 *
 * \author Enter_your_name_here
 */

#pragma once
#ifndef CCONNECTDLG_H_
#define CCONNECTDLG_H_

#include "CFrame.h"
#include "CClient.h"

class CConnectDlg : public wxDialog
{
public:
	CConnectDlg(CFrame *parent, CClient *client);
	virtual ~CConnectDlg();

	//! Id values for our controls
	enum Ids {ID_Close, ID_Connect, ID_ServerIp, ID_Username};

	// Don't put anything between this line and the next
	// private, protected, or public
	DECLARE_EVENT_TABLE()

private:
	//! Default constructor disabled
	CConnectDlg();

	//! Connect Button
	wxButton *mConnectButton;

	//! Close button
	wxButton *mCloseButton;

	wxTextCtrl *mServerIp;

	wxTextCtrl *mUsername;

	//! Frame this Animation Player is associated with
	CFrame *mFrame;

	CClient *mClient;

	void OnCloseButton(wxCommandEvent& event);
	void OnConnectButton(wxCommandEvent& event);
};

#endif /* CCONNECTDLG_H_ */
