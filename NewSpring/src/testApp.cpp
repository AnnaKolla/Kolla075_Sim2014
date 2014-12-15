#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(0);
    
    ofSetVerticalSync(true);
    
    
    Particle myParticle;
    
    myParticle.setInitialCondition(400,400,0,0);
    particles.push_back(myParticle);
    
    myParticle.setInitialCondition(400,500,0,0);
    particles.push_back(myParticle);
    
    myParticle.setInitialCondition(500,500,0,0);
    particles.push_back(myParticle);
    
    myParticle.setInitialCondition(500,400,0,0);
    particles.push_back(myParticle);
    
    
    Spring mySpring;
    
    
    for (int i = 0; i < particles.size(); i++){
        
        mySpring.resDist		= 50;
        mySpring.springiness	= 0.1f;
        mySpring.PartA = & (particles[i  ]);
        mySpring.PartB = & (particles[(i+1) % particles.size()]);
        springs.push_back(mySpring);
    }
    
    
    
    mySpring.resDist		= (particles[0].pos-particles[2].pos).length();
    mySpring.springiness	= 0.1f;
    mySpring.PartA = & (particles[0]);
    mySpring.PartB = & (particles[2]);
    springs.push_back(mySpring);
    
    mySpring.resDist		= (particles[1].pos-particles[3].pos).length();
    mySpring.springiness	= 0.1f;
    mySpring.PartA = & (particles[1]);
    mySpring.PartB = & (particles[3]);
    springs.push_back(mySpring);
    
}


//--------------------------------------------------------------
void testApp::update(){
    
    
    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perfom damping and
    // then update
    
    springs[0].resDist = 50 + 50 * sin(ofGetElapsedTimef()*10);
    springs[2].resDist = 50 + 50 * sin(ofGetElapsedTimef()*10 + PI);
    
    for (int i=0; i<particles.size(); i++) {
        
        particles[i].resetForce();
        
        
        for (int i=0; i<particles.size(); i++) {
            
            particles[i].addForce(0,0.1f);
            particles[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
            
        }
        
        for (int i=0; i<springs.size(); i++) {
            springs[i].update();
        }
        
        for (int i=0; i<particles.size(); i++) {
            
            particles[i].bounceOffWalls();
            particles[i].addDampingForce();
            particles[i].update();
            
        }
    }
}




//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0xffffff);
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
    
    for (int i = 0; i < springs.size(); i++){
        springs[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch (key){
            
        case ' ':
            // reposition everything:
            for (int i = 0; i < particles.size(); i++){
                particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
            }
            break;
    }
    
    
}



//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    particles[0].pos.set(mouseX, mouseY);
    /*particles.erase(particles.begin());
     particle myParticle;
     myParticle.setInitialCondition(x,y,0,0);
     particles.push_back(myParticle);*/
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    particles[0].bFixed = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
