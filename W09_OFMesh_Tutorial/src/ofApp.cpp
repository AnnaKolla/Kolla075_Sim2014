#include "ofApp.h"

/*openframeworks generating mesh tutorial online*/


//--------------------------------------------------------------
void ofApp::setup(){
    
    image.loadImage("stars.png");
    image.resize(200,200);
    
    ofSetFrameRate(60);
    
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    float intensityThreshold = 150;
    int w = image.getWidth();
    int h = image.getHeight();
    
    for (int x=0; x<w; ++x){
        for (int y=0; y<w; ++y){
            
           ofColor c = image.getColor(x, y);
            
            float intensity = c.getLightness();
            
            if (intensity >= intensityThreshold) {
                
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                
                ofVec3f pos(4*x,4*y,0.0);
                
            mesh.addVertex(pos);
            mesh.addColor(c);
                
                offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000),ofRandom(0,100000)));   //NOISE
                
            }
            
        }
    }
    
    
    float connectionDistance = 30;
    
    int numVerts = mesh.getNumVertices();
    
    for (int a= 0; a<numVerts; a++) {
        ofVec3f verta = mesh.getVertex(a);
        
        for (int b = a+1; b<numVerts; b++) {
            ofVec3f vertb = mesh.getVertex(b);
            
            float distance = verta.distance(vertb);
            
            if(distance <= connectionDistance){
                mesh.addIndex(a);
                mesh.addIndex(b);
                
            }
            
        }

    }
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    int numVerts = mesh.getNumVertices();     //ADD NOISE
    
    for (int i= 0; i < numVerts; i++) {
        
        ofVec3f vert = mesh.getVertex(i);
        
        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        float displacementScale = 0.75;
        ofVec3f timeOffsets = offsets[i];
        
        
        vert.x += (ofSignedNoise(time * timeScale+timeOffsets.x)) * displacementScale;
         vert.y += (ofSignedNoise(time * timeScale+timeOffsets.y)) * displacementScale;
         vert.z += (ofSignedNoise(time * timeScale+timeOffsets.z)) * displacementScale;
        
        mesh.setVertex(i, vert);
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cout << mesh.getNumVertices() << endl;
    
    
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0,0,0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    easyCam.begin();
        ofPushMatrix();
            ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
            mesh.draw();
    
    ofPopMatrix();
    easyCam.end();
                 

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
