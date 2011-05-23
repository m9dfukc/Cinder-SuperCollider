/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#pragma once

#include <vector>

#include "OscArg.h"
#include "OscBundle.h"
#include "OscListener.h"
#include "OscMessage.h"
#include "OscSender.h"
#include "SCServer.h"
#include "SCResourceAllocator.h"

namespace cinder { namespace supercollider {

using namespace std;
	
class SCBuffer;

class SCServer
{
  public:	
	SCServer(string hostname, unsigned int port);
	~SCServer();

	static SCServer     *local();
	
	void process();
	/* to be done - implement Cinder draw callback */
	// void _process();
	void notify();
	
	void sendMsg(cinder::osc::Message& message);
	void sendBundle(cinder::osc::Bundle& bundle);	
	
	SCResourceAllocator *allocatorBusAudio;
	SCResourceAllocator *allocatorBusControl;
	SCResourceAllocator *allocatorBuffer;
	SCResourceAllocator *allocatorSynth;

	SCBuffer *buffers[1024];
	
  protected:

#ifdef _OscSENDERRECEIVER_H
	/* to be done - extend osc block with the missing functionality */
	//cinder::osc::SenderReceiver	osc;
#else
	cinder::osc::Sender			osc;
#endif
	
	static SCServer *plocal;
	string hostname;
	unsigned int port;
};
	
} // namespace supercollider
} // namespace cinder


