#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    num =  150;
    float n = 24;
    float r = 240;
    
    myField.setup( 1000, 1000, 1000, 50 );
    myField.setPerlin();
    
    particleList.clear();
    
    for( int i=0; i<10000; i++ ){
        addParticle();
    }
    
    
    for(int i =0; i < num; i++){
        
        ofPoint p;
        points.push_back(p);
        
        float t;
        theta.push_back(t);
        
        float ph;
        phi.push_back(ph);
        
        int r;
        radius.push_back(r);
        
        
    }
    
    for(int i = 0; i < num; i++){
        
        theta[i] = i/n * PI/2;  //x
        phi[i] = i/n * PI;
        radius[i] = 100+i;
        
        points[i] = ofPoint(radius[i] * cos(theta[i])*sin(phi[i]), radius[i] * sin(theta[i])*sin(phi[i]), radius[i] * cos(phi[i]));
        
    }
    
}

//--------------------------------------------------------------
void ofApp::addParticle() {
        Particle part;
        part.pos = ofVec3f( ofRandom(myField.width), ofRandom(myField.height), ofRandom(myField.depth) );
        
        particleList.push_back( part );
    }
    
    
    
//--------------------------------------------------------------
void ofApp::update(){
    //myField.update();
    
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].applyForce( myField.getForceAtPosition(particleList[i].pos ) * 0.005 );
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    cam.begin();
    
    ofPushMatrix(); {
       // ofTranslate(myField.width*0.5*-1, myField.height*0.5*-1, myField.depth*0.5*-1);
    
        
        
        //myField.draw();
        
        glBegin(GL_POINTS);
       for( int i=0; i<particleList.size(); i++ ){
            particleList[i].draw();
       }
     
        glEnd();
        
        for(int i = 0; i < num; i++){
            
            points[i] = ofPoint(radius[i]*cos(theta[i])*sin(phi[i]), radius[i]*sin(theta[i])*sin(phi[i]), radius[i]*cos(phi[i]));
            
            
            if(radius[i] < 1000){
                radius[i] ++;
            }
            
            
        }
        
        for(int i = 0; i< num; i++){
            for(int j = i+1; j < num; j++){
                
                float  dist = pow(points[i].x - points[j].y, 2) + pow(points[i].y - points[j].z, 2) + pow(points[i].z - points[j].x, 2);
          
                ofSetColor(0, 30);
                ofSetLineWidth(1);
                ofLine(points[i].x, points[i].y, points[i].z, points[j].x, points[j].y, points[j].z);
              
            }
            
        }
        

    
    } ofPopMatrix();
    
    cam.end();

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
