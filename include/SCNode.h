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

namespace cinder { namespace supercollider {

using namespace std;
	
class SCGroup;

class SCNode
{
  public:	
	SCNode();
	~SCNode();
	
	void addToHead(SCGroup group);
	void addToHead(unsigned int groupID) { create(0, groupID); }
	void addToHead() { create(0, 1); }
	void addToTail(SCGroup group);
	void addToTail(unsigned int groupID) { create(1, groupID); }
	void addToTail() { create(1, 1); }
	void addBefore(const SCNode& node) { create(2, node.nodeID); }
	void addAfter(const SCNode& node) { create(3, node.nodeID); }
	
	// pure virtual method
	virtual void create(int position = 0, int groupID = 1);
	
	void free();

	static int id_base;
	
	// can't use 'id' as a keyword when mixing with objective-c!
	int nodeID;
		
  protected:

	bool created;
	
	SCServer *server;

};

} // namespace supercollider
} // namespace cinder

