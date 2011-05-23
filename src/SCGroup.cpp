/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#include "SCGroup.h"

namespace cinder { namespace supercollider {

void SCGroup::create(int position, int groupID)
{
	nodeID = SCNode::id_base++;
	
	cinder::osc::Message m;	
	
	m.setAddress("/g_new");
	m.addIntArg(nodeID);
	m.addIntArg(position);
	m.addIntArg(groupID);
	
	server->sendMsg(m);
	
	created = true;
}
	
} // namespace supercollider
} // namespace cinder

