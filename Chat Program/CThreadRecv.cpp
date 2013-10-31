/*!
 * \file CThreadRecv.cpp
 *
 * \author Enter_your_name_here
 */

#include "CThreadRecv.h"

/*CThreadRecv::CThreadRecv()
{
	// TODO Auto-generated constructor stub

}*/

CThreadRecv::~CThreadRecv()
{
	// TODO Auto-generated destructor stub
}

void CThreadRecv::InternalThreadEntry()
{
	mClient->ReceiveMessages();
}

