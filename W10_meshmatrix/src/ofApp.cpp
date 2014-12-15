#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    
  
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
   light.setDiffuseColor(ofColor::yellow);
    light.setPointLight();
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    ofMatrix4x4 M;
    
    M.makeIdentityMatrix();
    
    ofMatrix4x4 M2;
    
    M2.makeIdentityMatrix();
    
    
    ofMatrix4x4 M3;
    
    M3.makeIdentityMatrix();
    
    mesh.clear();

    
    float offset = 0;
    float width = 120;
    float height = 10;
    
    //float phi = (1.+sqrt(5)*0.5)                                      5
    //ofVec3F angles[4] = {ofVec3f(0.5,-0.5)
    
    for (int i = 0 ; i <100; i++){
        
        ofMatrix4x4 R;
        R.makeRotationMatrix(3.0, ofVec3f( 0.,0.,1.));
        
        ofMatrix4x4 R2;
        R2.makeRotationMatrix(3.0, ofVec3f( 1.,0.,0));
        
        ofMatrix4x4 R3;
        R3.makeRotationMatrix(3.0, ofVec3f( 0.,1.,0));
        
        
        M *= R;
        M2 *= R2;
        M3 *= R3;
        
        mesh.addColor(ofFloatColor(1,0,0));
        mesh.addVertex(M*ofPoint(width*0.5, 0, offset -height*1.0));    //1,0
        mesh.addColor(ofFloatColor(1,1,1));
        mesh.addVertex(M*ofPoint(-width*0.5, 0, offset -height*1.0));  //0,0
        
        
        mesh.addColor(ofFloatColor(1,0,0));
        mesh.addVertex(M2*ofPoint(width*0.5, 0, offset -height*0.5));    //1,0
        mesh.addColor(ofFloatColor(1,1,1));
        mesh.addVertex(M2*ofPoint(-width*0.5, 0, offset -height*0.5));  //0,0
        
        
        mesh.addColor(ofFloatColor(1,0,0));
        mesh.addVertex(M2*ofPoint(-width*0.5, 0, offset -height*0.5));    //1,0
        mesh.addColor(ofFloatColor(0,0,1));
        mesh.addVertex(M2*ofPoint(width*0.5, 0, offset -height*0.5));  //0,0
//
        
//        ofPushMatrix(); //*R2
//       
//        
//        ofMatrix4x4 T;
////        
//        T.makeTranslationMatrix((1.+sqrt(5)*0.5), i, 0.);
//
//        M *= T;
//        
//        mesh.addVertex(T*ofPoint(-width*0.3, 0, offset -height*0.3));  //0,0
//        
//        mesh.addVertex(T*ofPoint(width*0.3, 0, offset -height*0.3));    //1,0


        width *= 1.03;
        offset += height;
        
        //ofPopMatrix();
    }
    
    
    mesh.clearNormals();
    ofPoint up = ofPoint (0,0,1);
    mesh.addNormal(up);
    mesh.addNormal(up);
    
    for ( int  i = 2; i < mesh.getVertices().size(); i += 2){
        
        ofPoint a = mesh.getVertices()[i-1];
        ofPoint b = mesh.getVertices()[i];
        ofPoint c = mesh.getVertices()[i+1];
        
        ofVec3f normal = ((b - a).cross(c-a)).normalize();
        
        mesh.addNormal(normal);
        mesh.addNormal(normal);
        
        
    }
    
   light.setPosition( cos(ofGetElapsedTimef()) * 500 + 500, 500, sin(ofGetElapsedTimef()) * 500);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
  ofBackground(0);
 
     cam.begin();
    
    light.enable();
    ofEnableLighting();
    
    
   
    mesh.drawWireframe();
    
    
    ofDisableLighting();
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){
        
        mesh.save("mesh.ply");
    
        
    }

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
//void ofApp::setNormals( ofMesh &mesh ){
//    
//    //The number of the vertices
//    
//    int nV = mesh.getNumVertices();
//    
//    //The number of the triangles
//    
//    int nT = mesh.getNumIndices() / 3;
//    
//    vector<ofPoint> norm( nV );	//Array for the normals
//    
//    //Scan all the triangles. For each triangle add its
//    
//    //normal to norm's vectors of triangle's vertices
//    
//    for (int t=0; t<nT; t++) {
//        
//        //Get indices of the triangle t
//        
//        int i1 = mesh.getIndex( 3 * t );
//        
//        int i2 = mesh.getIndex( 3 * t + 1 );
//        
//        int i3 = mesh.getIndex( 3 * t + 2 );
//        
//        //Get vertices of the triangle
//        
//        const ofPoint &v1 = mesh.getVertex( i1 );
//        
//        const ofPoint &v2 = mesh.getVertex( i2 );
//        
//        const ofPoint &v3 = mesh.getVertex( i3 );
//        
//        //Compute the triangle's normal
//        
//        ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
//        
//        //Accumulate it to norm array for i1, i2, i3
//        
//        norm[ i1 ] += dir;
//        
//        norm[ i2 ] += dir;
//        
//        norm[ i3 ] += dir;
//        
//    }
//    
//    //Normalize the normal's length
//    
//    for (int i=0; i<nV; i++) {
//        
//        norm[i].normalize();
//        
//    }
//    
//    //Set the normals to mesh
//    
//    mesh.clearNormals();
//    
//    mesh.addNormals( norm );
//    
//}
