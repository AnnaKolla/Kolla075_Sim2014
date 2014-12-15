//
//  Spring.h
//  SpringParticle
//
//  Created by Annelie Koller on 10/5/14.
//
//

#ifndef __SpringParticle__Spring__
#define __SpringParticle__Spring__


#include "ofMain.h"
#include "Particle.h"


class Spring {
    
public:
    
    Spring();
    
    Particle * PartA;
    Particle * PartB;
    
    float resDist;  //a-b
    float springiness; //constant k
    
    void update();
    void draw();

};

#endif /* defined(__SpringParticle__Spring__) */
