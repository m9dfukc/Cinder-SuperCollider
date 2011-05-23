/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#include "SCNode.h"
#include "SCGroup.h"

namespace cinder { namespace supercollider {

int SCNode::id_base = 2000;

SCNode::SCNode()
{
	nodeID = 0;
	created = false;
	server = SCServer::local();
}

SCNode::~SCNode()
{
}

void SCNode::addToHead(SCGroup group)
{
	this->create(0, group.nodeID);
}

void SCNode::addToTail(SCGroup group)
{
	this->create(1, group.nodeID);
}

void SCNode::free()
{
	cinder::osc::Message m;	
	m.setAddress("/n_free");
	m.addIntArg(nodeID);
	server->sendMsg(m);
	
	created = false;
}

void SCNode::create(int position, int groupID)
{
}

} // namespace supercollider
} // namespace cinder
