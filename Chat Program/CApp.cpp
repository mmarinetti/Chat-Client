/*!
 * \file CApp.cpp
 *
 * \author Michael Marinetti
 */

#include "CApp.h"
#include "CFrame.h"

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
	return true;
}
