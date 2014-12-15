//
//  ParticleBall.h
//  myCircletest
//
//  Created by Annelie Koller on 10/12/14.
//
//

#ifndef __myCircletest__ParticleBall__
#define __myCircletest__ParticleBall__

#include "ofMain.h"
#include "Particle.h"

//#define NUM_PARTICLES 3000

class ParticleBall {

public:

    ParticleBall();
   
    
    void update();
    void draw();
    
    Particle** particles;
    
    int NUM_PARTICLES;
   
};



#endif /* defined(__myCircletest__ParticleBall__) */
