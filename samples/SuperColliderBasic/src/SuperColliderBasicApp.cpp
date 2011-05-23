#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "SuperCollider.h"

using namespace ci;
using namespace ci::app;
using namespace ci::supercollider;
using namespace std;

class SuperColliderBasicApp : public AppBasic {
public:
	void setup();
	void mouseDown( MouseEvent event );	
	void mouseDrag( MouseEvent event );
	void mouseUp( MouseEvent event );	
	void update();
	void draw();
	
	SCSynth	*synth;
	SCBus	*bus;
};

void SuperColliderBasicApp::setup()
{
	gl::clear( Color( 1, 1, 1 ) ); 
	
	synth = new SCSynth("sine_harmonic");
	synth->create();
}

void SuperColliderBasicApp::mouseDown( MouseEvent event )
{	
	if( event.isLeftDown() ) 
	{
		synth->set("amp", 0.8f);
	}
}

void SuperColliderBasicApp::mouseDrag( MouseEvent event )
{
	if( event.isLeftDown() ) 
	{
		synth->set("freq", event.getX() + 40);
		synth->set("amp", 1.0f - (float) event.getY() / getWindowHeight());
		synth->set("pan", (float) event.getX() / getWindowWidth() - 0.5f);
		
		gl::color( Color( 1, 0, 0 ) );
		gl::drawSolidCircle(event.getPos() , 5.0);
	}
}

void SuperColliderBasicApp::mouseUp( MouseEvent event )
{
	synth->set("amp", 0.0f);
}

void SuperColliderBasicApp::update()
{
}

void SuperColliderBasicApp::draw()
{
}


CINDER_APP_BASIC( SuperColliderBasicApp, RendererGl )

/*------------------------------------------------------------------------------
 * The below SynthDefs must be loaded into SuperCollider before execution.
 * copy+paste the lot and hit enter...
 *------------------------------------------------------------------------------
 
 SynthDef(\sine_harmonic, { |outbus = 0, freq = 200, amp = 0.1, gate = 1, pan = 0|
 var data, env;
 
 amp = Lag.kr(amp, 0.4);
 
 // generate, degrade, filter, echo
 data = SinOsc.ar(freq, 0, amp);
 data = Latch.ar(data, Impulse.ar(Rand(1000, 35000)));
 data = LPF.ar(data, 1000);
 data = Pan2.ar(data, pan);
 data = data + CombN.ar(data, 0.5, 0.3, 15.0, 0.3);	
 
 // envelope
 env = EnvGen.kr(Env.asr(0.5, 1.0, 1.0), gate: gate, doneAction: 2);
 data = data * env;
 
 data = [ data[0], data[1] * Select.kr(IRand(0, 3), [ 1, 1, -1 ]) ];
 
 Out.ar(outbus, data);
 }).store;
 
 */