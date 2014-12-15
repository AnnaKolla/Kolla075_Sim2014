#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableNormalizedTexCoords();
    ofImage img;
    img.loadImage("images.png");
    img.mirror(false, true);
    text.allocate(128, 128, GL_RGB, false);
    ang = 0;
    glEnable(GL_DEPTH_TEST);
    text.loadData(img.getPixels(), 128, 128, GL_RGBA);
    
    light.setPointLight();
    light2.setPointLight();
    light.lookAt(ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0));

}

//--------------------------------------------------------------
void ofApp::update(){
    ang += 0.1;
    
    light.setPosition( cos(ofGetElapsedTimef()) * 200 + 200, 200, sin(ofGetElapsedTimef()) * 200);
    light2.setPosition( cos(ofGetElapsedTimef()) * 50 + 100, sin(ofGetElapsedTimef()) *
                       100 + 100, 0);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableLighting();
    light.enable();
    
    ofPushMatrix();
    ofBackground(122,122,122);
    text.bind();
    ofTranslate(ofGetWidth() * .5, ofGetHeight() * .5, 0);
    ofRotate(ang, 1.0, 1.0,1.0);
    ofDrawBox(200);
    text.unbind();
    ofPopMatrix();
    
    ofDisableLighting();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
