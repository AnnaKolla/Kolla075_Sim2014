//
//  Particle.h
//  myCircletest
//
//  Created by Annelie Koller on 10/12/14.
//
//

#ifndef __myCircletest__Particle__
#define __myCircletest__Particle__

#include "ofMain.h"


class Particle {
public:
    
    Particle(float _theta, float _u);
    
    float theta, u;
    float vTheta, vU;
    float x,y,z,radius;
    
    void update();
    void draw();
   
};


#endif /* defined(__myCircletest__Particle__) */
