/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#include "SCBus.h"

namespace cinder { namespace supercollider {

int SCBus::id_base = 64;

SCBus::SCBus(int rate, int channels, SCServer *server)
{
	this->rate = rate;
	this->channels = channels;
	this->server = server;	
	
	if (this->rate == RATE_CONTROL)
	{
		this->index = server->allocatorBusControl->alloc(this->channels);
	}
	else
	{
		this->index = server->allocatorBusAudio->alloc(this->channels);
	}
}


void SCBus::free()
{
	// nothing is actually allocated server-side,
	// so all we need to do here is reflect the availability of this address
	if (this->rate == RATE_CONTROL)
		server->allocatorBusControl->free(this->index);
	else
		server->allocatorBusAudio->free(this->index);
}

} // namespace supercollider
} // namespace cinder
