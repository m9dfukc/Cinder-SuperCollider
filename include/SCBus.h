/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#pragma once

#include "SuperCollider.h"
#include "SCServer.h"

namespace cinder { namespace supercollider {
	
using namespace std;
	
class SCBus
{
	
  public:
	SCBus(int rate = RATE_AUDIO, int channels = 2, SCServer *server = SCServer::local());
	
	void free();
	
	static int id_base;
	
	SCServer *server;
	int rate;
	int index;
	int channels;
	
};
	
} // namespace supercollider
} // namespace cinder

