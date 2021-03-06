/*
 SuperCollider Integration for the Cinder framework <http://libcinder.org>
 Copyright (c) 2011 invertednothing.
 <http://invertednothing.com/>
 
 Based on ofxSuperCollider: a SuperCollider control addon for openFrameworks.
 Copyright (c) 2009 Daniel Jones.
 <http://www.erase.net/>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the “Software”), to
 deal in the Software without restriction, including without limitation the
 rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 sell copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
  
 THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 IN THE SOFTWARE.
 */

#pragma once

namespace cinder { namespace supercollider {

enum rates
{
	RATE_AUDIO = 0,
	RATE_CONTROL
};
	
} // namespace supercollider
} // namespace cinder
	

#include "OscArg.h"
#include "OscBundle.h"
#include "OscListener.h"
#include "OscMessage.h"
#include "OscSender.h"

#include "SCResourceAllocator.h"

#include "SCServer.h"
#include "SCNode.h"
#include "SCServer.h"
#include "SCSynth.h"
#include "SCGroup.h"
#include "SCBus.h"
#include "SCBuffer.h"
