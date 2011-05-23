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
	
class SCBuffer
{
	
  public:
	SCBuffer(int frames = 0, int channels = 0, SCServer *server = SCServer::local());
	
	void read(string path);
	void query();
	void alloc();
	void free();
	
	static int id_base;
	
	SCServer *server;

	int index;
	int frames;
	int channels;
	float sampleRate;
	bool ready;
	
	string path;
	
};
	
} // namespace supercollider
} // namespace cinder

