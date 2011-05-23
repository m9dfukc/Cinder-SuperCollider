/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#include "SCServer.h"
#include "SCBuffer.h"
#include "OscArg.h"
#include "OscBundle.h"
#include "OscListener.h"
#include "OscMessage.h"
#include "OscSender.h"
#include "SCServer.h"

namespace cinder { namespace supercollider {

#define LISTEN_PORT 57150

SCServer *SCServer::plocal = NULL;

SCServer::SCServer(string hostname = "localhost", unsigned int port = 57110)
{
	this->hostname = hostname;
	this->port = port;

#ifdef _OscSENDERRECEIVER_H
	
	osc.setup(LISTEN_PORT, hostname, port);
	/* to be done - implement Cinder draw callback */
	// ofAddListener(ofEvents.draw, this, &SCServer::_process);
	
#else
	
	osc.setup(hostname, port);
	
#endif
	
	allocatorBusAudio = new SCResourceAllocator(512);
	allocatorBusAudio->pos = 64;
	
	allocatorBusControl = new SCResourceAllocator(512);
	allocatorBuffer = new SCResourceAllocator(512);
	
	if (plocal == 0)
		plocal = this;
}

SCServer::~SCServer()
{
}

SCServer *SCServer::local()
{
	if (plocal == 0)
	{
		plocal = new SCServer;
	}
	
	return plocal;
}


void SCServer::process()
{
	
#ifdef _OscSENDERRECEIVER_H			

	while(osc.hasWaitingMessages())
	{
		cinder::osc::Message m;
		osc.getNextMessage(&m);
		printf("** got OSC! %s\n", m.getAddress().c_str());
		
		/*-----------------------------------------------------------------------------
		 * /done
		 *  - buffer read completed
		 /*---------------------------------------------------------------------------*/
		if (m.getAddress() == "/done")
		{
			string cmd = m.getArgAsString(0);
			int index = m.getArgAsInt32(1);
			printf("** buffer read completed, ID %d\n", index);
			buffers[index]->ready = true;
		}

		/*-----------------------------------------------------------------------------
		 * /b_info
		 *  - information on buffer size and channels
		/*---------------------------------------------------------------------------*/
		else if (m.getAddress() == "/b_info")
		{
			int index = m.getArgAsInt32(0);
			buffers[index]->frames = m.getArgAsInt32(1);
			buffers[index]->channels = m.getArgAsInt32(2);
			buffers[index]->sampleRate = m.getArgAsFloat(3);
			buffers[index]->ready = true;			
		}
		
		// buffer alloc/read failed
		else if (m.getAddress() == "/fail")
		{
		}
	}
	
#else
	
	fprintf(stderr, "This version of Osc does not have support for sender/receive objects. Please update to enable receiving responses from SuperCollider.\n");
	
#endif
	
}
	
/* to be done - implement Cinder draw callback
void SCServer::_process() 
{	
	this->process();
}
 */
	
void SCServer::notify()
{
	cinder::osc::Message m;
	m.setAddress("/notify");
	m.addIntArg(1);
	osc.sendMessage(m);
}

void SCServer::sendMsg(cinder::osc::Message& m)
{
	osc.sendMessage(m);
}

void SCServer::sendBundle(cinder::osc::Bundle& b)
{
	osc.sendBundle(b);
}
	
} // namespace supercollider
} // namespace cinder

