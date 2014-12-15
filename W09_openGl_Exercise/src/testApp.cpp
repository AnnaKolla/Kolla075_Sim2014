#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetWindowShape(200, 200);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(0,0,0);
    
    glBegin(GL_TRIANGLE_STRIP);
    
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(50,50 );
    
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(50,150 );
    
    glColor3f(0, 0.0, 1.0);
    glVertex2f(150,150 );
    
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(150,50 );
    
    glColor3f(.0, 1.0, 0.0);
    glVertex2f(50,50 );
    
   
    
    glEnd();


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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
