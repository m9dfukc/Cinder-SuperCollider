/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#include "SCSynth.h"

namespace cinder { namespace supercollider {

SCSynth::SCSynth(string name, SCServer *server)
{
	SCNode();
	
	this->name = name;
	this->server = server;
}

SCSynth::~SCSynth()
{
}

void SCSynth::create(int position, int groupID)
{
	cinder::osc::Bundle b;
	cinder::osc::Message m;

	if (nodeID == 0)
		nodeID = SCNode::id_base++;
	
	m.setAddress("/s_new");
	m.addStringArg(name.c_str());
	m.addIntArg(nodeID);
	m.addIntArg(position);
	m.addIntArg(groupID);
	b.addMessage(m);
	
	for (dictionary::const_iterator it = args.begin(); 
        it != args.end(); ++it)
	{
		string key = it->first;
		float value = it->second;

		m.clear();
		m.setAddress("/n_set");
		m.addIntArg(nodeID);
		m.addStringArg(key.c_str());
		m.addFloatArg(value);
		b.addMessage(m);
	}

	server->sendBundle(b);
	
	created = true;
}

void SCSynth::grain(int position, int groupID)
{
	nodeID = -1;
	create(position, groupID);
}

void SCSynth::set(string arg, double value)
{
	args.insert(dictionary::value_type(arg, value));
	
	if (created)
	{
		cinder::osc::Message m;
		m.setAddress("/n_set");
		m.addIntArg(nodeID);
		m.addStringArg(arg);
		m.addFloatArg(value);
		
		server->sendMsg(m);
	}
}

void SCSynth::set(string arg, int value)
{
	args.insert(dictionary::value_type(arg, value));
	
	if (created)
	{
		cinder::osc::Message m;
		m.setAddress("/n_set");
		m.addIntArg(nodeID);
		m.addStringArg(arg);
		m.addIntArg(value);
		
		server->sendMsg(m);
	}
}

} // namespace supercollider
} // namespace cinder
