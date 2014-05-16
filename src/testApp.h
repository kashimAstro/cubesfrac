#pragma once

#include "ofMain.h"
class testApp : public ofBaseApp{
	public:
		void setup();
		void draw();
		void Fractal(float x,float y,float z,float s, float f, int l);
};
