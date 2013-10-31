/*!
 * \file CApp.h
 *
 * ** insert description here **
 *
 * \author Michael Marinetti
 */

#pragma once
#ifndef CAPP_H_
#define CAPP_H_

#include <wx/wx.h>

class CApp : public wxApp
{
public:
	CApp();
	CApp(const CApp &orig);
	virtual ~CApp();

	virtual bool OnInit();
};

#endif /* CAPP_H_ */
