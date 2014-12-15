#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(1);
    
    //ofBackground(0,0,0);
    
    lineLength = 8;
    rotationAngle = 10.0;
    angleOffset = 2;
    fractalProportion = 0.8;
    newTrunk.startingPointX = ofGetWidth()/2;
    newTrunk.startingPointY = ofGetHeight()-300;
    
    frameNumber = 0;
    appInfo = "";
    font.loadFont("verdana.ttf", 9, true, true, true);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    frameNumber++;
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    font.drawString(appInfo, 2, 12);
    
    newTrunk.draw(frameNumber, rotationAngle);

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
