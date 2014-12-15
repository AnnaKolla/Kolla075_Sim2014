#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
        ofBackground(0,0,0);
        ofDisableArbTex();
        ofEnableAlphaBlending();
        ofSetFrameRate(60);
        glEnable(GL_DEPTH_TEST);
        
//        colormap.loadImage("felt.jpg");
//        bumpmap.loadImage("feltbw.jpg");
    
    colormap.loadImage("bulb.jpg");
    bumpmap.loadImage("bulbbw.jpg");
    
//    colormap.loadImage("coral.jpg");
//    bumpmap.loadImage("coral copy.jpg");
//    
   
    
        quadric = gluNewQuadric();
        gluQuadricTexture(quadric, GL_TRUE);
        gluQuadricNormals(quadric, GLU_SMOOTH);
        
        shader.load("shaders/displace.vert", "shaders/displace.frag");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    shader.begin();
    shader.setUniformTexture("colormap", colormap, 1);
    shader.setUniformTexture("bumpmap", bumpmap, 2);
    shader.setUniform1i("maxHeight",mouseX);
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateY(360*sinf(float(ofGetFrameNum())/500.0f));
    ofRotate(-90,1,0,0);
    gluSphere(quadric, 150, 400, 400);
    
    shader.end();

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
