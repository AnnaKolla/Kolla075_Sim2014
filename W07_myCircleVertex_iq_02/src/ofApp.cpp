#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for (int i = 0; i <= latBands; i++) {
        
        theta = i * PI/latBands;       //angle
        sinTheta = sin(theta);
        cosTheta = cos(theta);
        
        
        for (int j = 0; j <= longBands; j++) {
            
            pie = j * 2*PI/longBands;       //angle
            sinPie = sin(pie);
            cosPie = cos(pie);
            
            x = cosPie * sinTheta;
            y = cosTheta;
            z = sinPie * sinTheta;
            
            mesh.addVertex( ofVec3f( x, y, z ));
            
            u = 1 - (j / longBands);
            v = 1 - (i/ latBands);
        }
    }
    
    for (int i = 0; i < latBands; i++) {
        for (int j = 0; j < longBands; j++) {
            
            
            float  first = (i * (longBands +1)) + j;
            float  second = first + longBands + 1;
            
            //        mesh.addIndex(indices[i][1]);
            //        mesh.addIndex(indices[i][2]);
            //        mesh.addIndex(indices[i][3]);
            //
            //             mesh.addIndex(indices[j][1]);
            //             mesh.addIndex(indices[j][2]);
            //             mesh.addIndex(indices[j][3]);
            
            mIndices[0] =  first;
            mIndices[1] = second;
            mIndices[2] = first + 1;
            mIndices[3] = second;
            mIndices[4] = second+1;
            mIndices[5] = first +1 ;
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(122,122,122);
    ofPushMatrix();
    ofTranslate(400, 400, 0);

    mesh.drawWireframe();
    ofPopMatrix();
    
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
