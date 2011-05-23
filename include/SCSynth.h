/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#pragma once

#include <vector>
#include <boost/unordered_map.hpp>

#include "SCNode.h"

namespace cinder { namespace supercollider {

using namespace std;

typedef boost::unordered_map< string, float > dictionary;

class SCSynth : public SCNode
{
  public:	
	SCSynth(string name = "sine", SCServer *server = SCServer::local());
	~SCSynth();

	SCSynth (const SCSynth & other) { copy (other); }
	SCSynth& operator= (const SCSynth & other) { return copy(other); }

	/// for operator= and copy constructor
	SCSynth & copy(const SCSynth & other);
	
	void create(int position = 0, int groupID = 1);
	void grain(int position = 0, int groupID = 1);
	
	void set(string arg, double value);
	void set(string arg, int value);
		
  protected:

	string name;
	dictionary args;
};
	
} // namespace supercollider
} // namespace cinder

