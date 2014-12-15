//
//  vertex.h
//  circlemesh
//
//  Created by Annelie Koller on 12/8/14.
//
//



#include "ofMain.h"

class Vertex {
    
 public: Vertex(float x, float y);

   
    Vertex(ofVec3f v);
    ofFloatColor color;
    ofVec3f normal;

};
