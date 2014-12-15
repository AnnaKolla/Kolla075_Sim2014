#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);

        
    }


//--------------------------------------------------------------
void ofApp::update(){
    
    ball.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofRotateX(mouseY/5);
    ofRotateY(mouseX/5);
    
    ball.draw();


}
