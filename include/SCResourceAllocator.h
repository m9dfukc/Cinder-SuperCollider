/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 
 Distributed under the MIT License.
 For more information, see SuperCollider.h.
 */

#pragma once

#include <vector>

namespace cinder { namespace supercollider {
	
using namespace std;

class SCResource
{

  public:
	
	SCResource(int address, int size)
	{
		this->address = address;
		this->size = size;
		this->next = NULL;
	}
	
	int address;
	int size;
	
	// pointer to next resource in free list
	SCResource *next;	
};

class SCResourceAllocator
{
  public:
	SCResourceAllocator(int capacity);
	
	int alloc (int resource_size);
	void free (int address);
	
	int capacity;
	int pos;
	std::vector <SCResource *> resources;
	std::vector <SCResource *> free_lists;
};

} // namespace supercollider
} // namespace cinder
