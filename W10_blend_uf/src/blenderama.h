//
//  blenderama.h
//  nov10_blend
//
//  Created by Annelie Koller on 11/17/14.
//
//

#ifndef __nov10_blend__blenderama__
#define __nov10_blend__blenderama__



#include "ofMain.h"

#define numCubes 20

class blenderama:public ofBaseApp{
    
public:
    float ang;
    int currentLBlend, currentRBlend; // indexes to store the current blending value
    ofImage img; // an image to load a picture for a texture
    ofTexture text; // a texture to use
    ofVec3f cubePos[numCubes]; // an array to store all the text values
    void setup();
    void update();
    void draw();
    void keyPressed (int key);
};

#endif /* defined(__nov10_blend__blenderama__) */
