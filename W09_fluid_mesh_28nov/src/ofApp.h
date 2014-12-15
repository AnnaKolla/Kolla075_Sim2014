#pragma once

#include "ofMain.h"
#include "ofxFluid.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
    ofxFluid fluid;
    
    ofVec2f oldM;
    ofVec2f gravity;
    ofVec2f emitPos;
    int     width,height;
    float   x,y,z,w,h;
    bool    bPaint, bObstacle, bBounding, bClear;
    bool clear;
     bool drawObstacles;
    
    ofEasyCam       cam;
    
    ofTexture       heightMap;
   
    ofShader        normalShader;
    //ofFbo           normalFbo;
    ofFbo           obstacles;
    
    ofVboMesh       terrain;
    ofShader        terrainShader;
    
    bool            bWireframe;
};
