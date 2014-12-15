//
//  Spring.cpp
//  SpringParticle
//
//  Created by Annelie Koller on 10/5/14.
//
//

#include "Spring.h"

//--------------------------------------------------------------


Spring::Spring(){
    
    PartA = NULL;
    PartB = NULL;
}


void Spring::update(){
    
    if ((PartA == NULL) || (PartB == NULL)){
        return;
}


    
    ofPoint ptA = PartA -> pos;
    ofPoint ptB = PartB -> pos;
    resDist = 100;     //a.distance(b);


    float theirDist = (ptA - ptB).length();
    float springForce = (springiness * (resDist - theirDist)); //hooke's law f = -k*x
    
    ofPoint frcAdd = (ptA - ptB).normalized() * springForce;
    
    PartA -> addForce(frcAdd.x, frcAdd.y);
    PartB -> addForce(-frcAdd.x, -frcAdd.y);
    
    
}

//--------------------------------------------------------------

void Spring::draw(){
    
    if ((PartA == NULL) || (PartB == NULL)){
        return;
    }

    
    ofLine(PartA->pos.x, PartA->pos.y, PartB->pos.x, PartB->pos.y);
    
}