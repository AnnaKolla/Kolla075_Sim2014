#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
    
    ofMesh mesh;
    ofVbo vbo;
    ofEasyCam camera;
    ofLight light;
    bool wireFrame;
		
};
