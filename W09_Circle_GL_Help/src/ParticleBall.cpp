//
//  ParticleBall.cpp
//  myCircletest
//
//  Created by Annelie Koller on 10/12/14.
//
//


#include "ParticleBall.h"

GLUquadricObj *quadratic = NULL;

ParticleBall::ParticleBall() {
    
    particles = new Particle*[NUM_PARTICLES];
    
    NUM_PARTICLES = 1000;
    
    for(int i = 0; i < NUM_PARTICLES; i++) {
        
        float theta = ofRandom(0,PI);
        float u = ofRandom(-1,1);
        
        particles[i] = new Particle(theta, u);
        quadratic = gluNewQuadric();			// Create A Pointer To The Quadric Object
        gluQuadricTexture(quadratic, GL_TRUE);		// Create Texture Coords
        gluQuadricNormals(quadratic, GLU_SMOOTH);	// Create Smooth Normals
        
    }
 
}

void ParticleBall::update() {
    
    for(int i = 0; i < NUM_PARTICLES; i++) {
        

        particles[i]->update();
    }
}

void ParticleBall::draw() {
    
    ofSetColor(80,80,80);
    
    gluSphere(quadratic, 100.0, 20, 20);
    //glutSolidSphere(140, 64, 64);
    
    ofSetColor(91,197,242,50);
    
    for(int i = 0; i < NUM_PARTICLES; i++) {
        particles[i]->draw();
    }
}