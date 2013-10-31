/*!
 * \file CFrame.h
 *
 * ** insert description here **
 *
 * \author Enter_your_name_here
 */

#pragma once
#ifndef CFRAME_H_
#define CFRAME_H_

#include <wx/wx.h>

#include "CClient.h"
#include "CThreadRecv.h"

class CFrame : public wxFrame
{
public:
	CFrame();
	CFrame(const CFrame &orig);
	virtual ~CFrame();

	DECLARE_EVENT_TABLE()

	enum Ids {ID_Exit=1, ID_Connect, ID_ChatBox, ID_Enter, ID_Chat};

	void OnExit(wxCommandEvent& event);
	void OnConnect(wxCommandEvent& event);
	void OnSend(wxCommandEvent& event);
	void AddtoTextBox(char *t);

private:
	CClient mClient;

	//! Enter Button
	wxButton *mEnterButton;

	wxTextCtrl *mMessage;

	wxTextCtrl *mChatBox;

	CThreadRecv mReceiveThread;
};

#endif /* CFRAME_H_ */
