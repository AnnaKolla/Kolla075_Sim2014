//
//  Particle.cpp
//  myCircletest
//
//  Created by Annelie Koller on 10/12/14.
//
//

#include "Particle.h"
#include "ofMain.h"
GLUquadricObj *quadratic = NULL;

Particle::Particle(float _theta, float _u){
    
    radius = 150;
    theta = _theta = 0;
    u = _u = 0;
    vTheta = 0;
    vU = 0;
    
    quadratic = gluNewQuadric();			// Create A Pointer To The Quadric Object
    gluQuadricTexture(quadratic, GL_TRUE);		// Create Texture Coords
    gluQuadricNormals(quadratic, GLU_SMOOTH);	// Create Smooth Normals
    
}

void Particle::update() {
    
    vTheta += ofRandom(-0.001,0.001);
    theta += vTheta;
    
    if (theta<0||theta>PI) {
        vTheta*=-1;
    }
    
    vU += ofRandom(-0.001,0.001);
    u += vU;
    
    if (u<-1||u>1) vU*=-1;
    
    vU *= 0.95;
    vTheta *= 0.95;
    
    x = radius*cos(theta)*sqrt(1-(u*u));
    y = radius*sin(theta)*sqrt(1-(u*u));
    z = radius*u;
}

void Particle::draw() {
    ofPushMatrix();
    ofTranslate(x,y,z);
    gluSphere(quadratic, 3.0, 3.0, 2.0);

    ofPopMatrix();
    
    }

