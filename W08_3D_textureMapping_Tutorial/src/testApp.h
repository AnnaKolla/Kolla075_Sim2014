#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVideoPlayer video;    //Prerecorded video
    ofFbo fbo;
    ofMesh mesh;
    ofImage image;
    ofPixels fboPixels;

    
private:
    
    int videoWidth = 720;
    int videoHeight = 480;
    int W = 100; //Grid size
    int H = 100;
    int meshSize = 6;
    
    float tiltCurrent = 0;
    float tiltTarget = 0;
    float turnCurrent = 1;
    float turnTarget = 1;
};