//
//  Spring.h
//  Springs
//
//  Created by Annelie Koller on 10/5/14.
//
//

#ifndef __Springs__Spring__
#define __Springs__Spring__

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

#endif /* defined(__Springs__Spring__) */
