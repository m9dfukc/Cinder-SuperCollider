/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#pragma once

#include <vector>
#include <boost/unordered_map.hpp>

#include "SCNode.h"
#include "OscArg.h"
#include "OscBundle.h"
#include "OscListener.h"
#include "OscMessage.h"
#include "OscSender.h"

namespace cinder { namespace supercollider {

using namespace std;
	
class SCGroup : public SCNode
{
  public:	
	SCGroup() : SCNode() {}
	~SCGroup();

	SCGroup (const SCGroup & other) { copy (other); }
	SCGroup& operator= (const SCGroup & other) { return copy(other); }

	SCGroup & copy(const SCGroup & other);
	
	void create(int position = 0, int groupID = 1);
	void freeAll();
	
};
	
} // namespace supercollider
} // namespace cinder


