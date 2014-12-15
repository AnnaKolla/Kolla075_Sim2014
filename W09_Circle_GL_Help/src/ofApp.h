#pragma once

#include "ofMain.h"
#include "ParticleBall.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


class ofApp : public ofBaseApp{

	public:
    
		void setup();
		void update();
		void draw();
  
    
    ParticleBall ball;
 
};
