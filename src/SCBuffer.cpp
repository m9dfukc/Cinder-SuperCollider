/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#include "SCBuffer.h"

namespace cinder { namespace supercollider {

SCBuffer::SCBuffer(int frames, int channels, SCServer *server)
{
	this->server     = server;
	this->frames     = frames;
	this->channels   = channels;
	
	index = server->allocatorBuffer->alloc(1);
	
	server->buffers[index] = this;
	ready = false;
}

void SCBuffer::read(string path)
{
	// XXX do we need to strncpy this?
	// i think so.
	this->path.assign(path);
	
	cinder::osc::Message m;
	m.setAddress("/b_allocRead");
	m.addIntArg(index);
	m.addStringArg(path);
	
	// would be nice to also send a b_query at this point, but
	// Osc does not have support for byte array args
	
	server->sendMsg(m);
}

void SCBuffer::query()
{
	cinder::osc::Message m;	
	m.setAddress("/b_query");
	m.addIntArg(index);
	server->sendMsg(m);
}

void SCBuffer::alloc()
{
	cinder::osc::Message m;	
	m.setAddress("/b_alloc");
	m.addIntArg(index);
	m.addIntArg(frames);
	m.addIntArg(channels);	
	server->sendMsg(m);
}

void SCBuffer::free()
{
	cinder::osc::Message m;	
	m.setAddress("/b_free");
	m.addIntArg(index);
	server->sendMsg(m);
	
	server->allocatorBuffer->free(index);
}
	
} // namespace supercollider
} // namespace cinder

