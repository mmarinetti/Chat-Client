/*!
 * \file CApp.cpp
 *
 * \author Michael Marinetti
 */

#include "CApp.h"
#include "CFrame.h"
#include "CRecvThread.h"

IMPLEMENT_APP(CApp)

CApp::CApp()
{
	// TODO Auto-generated constructor stub

}

CApp::~CApp()
{
	// TODO Auto-generated destructor stub
}

/*! Application initialization function
 *
 * This function is called once when the application is started. It creates the main frame
 * for the program and displays it.
 * \returns true
 */
bool CApp::OnInit()
{
	CFrame *frame = new CFrame();
	frame->Show(true);
	SetTopWindow(frame);

	CRecvThread *t = new CRecvThread(frame);
	t->SetClient(frame->GetClient());
	wxThreadError err = t->Create();
    if (err != wxTHREAD_NO_ERROR)
    {
        wxMessageBox( _("Couldn't create thread!") );
        return false;
    }

    err = t->Run();

    if (err != wxTHREAD_NO_ERROR)
    {
        wxMessageBox( _("Couldn't run thread!") );
        return false;
    }
	return true;
}
