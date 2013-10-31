/*!
 * \file CThread.h
 *
 * ** insert description here **
 *
 * \author Enter_your_name_here
 */

#pragma once
#ifndef CTHREAD_H_
#define CTHREAD_H_

#include <pthread.h>

class CThread
{
public:
	CThread() {}
	virtual ~CThread() {}

	bool StartInternalThread()
	{
		return (pthread_create(&mThread, NULL, InternalThreadEntryFunc, this) == 0);
	}

	void WaitForInternalThreadToExit()
	{
		(void) pthread_join(mThread, NULL);
	}

protected:
	virtual void InternalThreadEntry() = 0;

private:
	static void *InternalThreadEntryFunc(void *This)
	{
		((CThread *)This)->InternalThreadEntry();
		return NULL;
	}

	pthread_t mThread;
};

#endif /* CTHREAD_H_ */
