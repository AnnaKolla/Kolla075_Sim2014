//
//  Particle.h
//  SpringParticle
//
//  Created by Annelie Koller on 10/5/14.
//
//

#ifndef __SpringParticle__Particle__
#define __SpringParticle__Particle__


#include "ofMain.h"
//#include "Spring.h"

class Particle {
    
public:
  
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;   // frc is also know as acceleration (newton says "f=ma")
    
    Particle();
        virtual ~Particle(){};
    
    void resetForce();
    
    void addForce(float x, float y);
    
    void addRepulsionForce(float x, float y, float radius, float scale);
    
    void addAttractionForce(float x, float y, float radius, float scale);
    
    void addRepulsionForce(Particle &p, float radius, float scale);
    
    void addAttractionForce(Particle &p, float radius, float scale);
    
    void addClockwiseForce(Particle &p, float radius, float scale);
    
    void addCounterClockwiseForce(Particle &p, float radius, float scale);
    
    
    void addDampingForce();
    
    void setInitialCondition(float px, float py, float vx, float vy);
    
    void update();
    
    void draw();
    
    void bounceOffWalls();
    
    bool  bFixed;
    
    float damping;
    
protected:
private:


};

    
#endif /* defined(__SpringParticle__Particle__) */
