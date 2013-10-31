/*!
 * \file CThreadRecv.h
 *
 * ** insert description here **
 *
 * \author Enter_your_name_here
 */

#pragma once
#ifndef CTHREADRECV_H_
#define CTHREADRECV_H_

#include "CThread.h"
#include "CClient.h"

class CThreadRecv : public CThread
{
public:
	CThreadRecv(CClient *c) {mClient = c;}
	virtual ~CThreadRecv();

	virtual void InternalThreadEntry();

private:
	CClient *mClient;
};

#endif /* CTHREADRECV_H_ */
