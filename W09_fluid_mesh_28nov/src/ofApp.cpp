#include "ofApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    
    ofDisableArbTex();
    ofLoadImage(heightMap, "heightmap.png");
  
    ofEnableArbTex();
    
    normalShader.load("","normal.frag");
    terrainShader.load("terrain");

    int scale = 1.0;
    int w = ofGetWidth()/scale;
    int h = ofGetHeight()/scale;
 
    // Initial Allocation
    //
    fluid.allocate(w, h, 0.2);
     obstacles.allocate(w,h);
    
    fluid.begin();
    ofSetColor(0,0);
    ofSetColor(255);
    //ofCircle(w*0.5, h*0.35, 40);
    
    // Seting the gravity set up & injecting the background image
    //
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    
    //fluid.setGravity(ofVec3f(0.0,0.0,0.0));
//    fluid.setGravity(ofVec2f(0.0,0.0098));
    

        fluid.end();
          obstacles.begin();
       ofScale(1.0/scale, 1.0/scale);
       ofBackground(1,1, 0, 0);
    
    
    for (int y = 0; y < h; y++){
        for (int x = 0; x<w; x++){
            
            //  Per pixel we set the position, normal and texCoord
            //
            float offsetX = 0;
            float offsetY = (x%2==1)?0.5:0.0;
            terrain.addVertex(ofPoint((x+offsetX)*scale,(y+offsetY)*scale,0));
            terrain.addNormal(ofPoint(1,0,0));
            terrain.addTexCoord(ofVec2f((float)(x+offsetX)/(float)w,(float)(y+offsetY)/(float)h));
        }
    }
    for (int y = 0; y<h-1; y++){
        for (int x=0; x<w-1; x++){
            if(x%2==0){
                terrain.addIndex(x+y*w);				// a
                terrain.addIndex((x+1)+y*w);			// b
                terrain.addIndex(x+(y+1)*w);			// d
                
                terrain.addIndex((x+1)+y*w);			// b
                terrain.addIndex((x+1)+(y+1)*w);		// c
                terrain.addIndex(x+(y+1)*w);			// d
            } else {
                terrain.addIndex((x+1)+y*w);			// b
                terrain.addIndex(x+y*w);				// a
                terrain.addIndex((x+1)+(y+1)*w);		// c
                
                terrain.addIndex(x+y*w);				// a
                terrain.addIndex(x+(y+1)*w);			// d
                terrain.addIndex((x+1)+(y+1)*w);		// c
            }
        }
        
    }
    
  
          obstacles.end();
    
    bWireframe = true;
    
    fluid.setObstacles(obstacles);
    fluid.setUseObstacles(false);

    ofSetWindowShape(w, h);
        
   
}



//--------------------------------------------------------------
void testApp::update(){
    
    fluid.setGravity(gravity);
    
    ofPoint m = emitPos;
    ofPoint d = (m - oldM)*10.0;
    oldM = m;
    ofPoint c = ofPoint(w*0.5, h*0.5) - m;
    c.normalize();
    fluid.addTemporalForce(m, d, ofFloatColor(c.x,c.y,0.5)*sin(ofGetElapsedTimef()),3.0f);
    
    //  Update
    
    if(clear) {
        fluid.clear();
        fluid.setObstacles(obstacles);
    } clear = false;
    
    
    //if(ofGetFrameNum() % 2 == 1) {
    fluid.update();
    
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    //  Compute the normals inside a FBO
    //  a FBO is like a screen... we can render and draw in it.
    //  but instead of been render on the monitor is render into memory (Frame Buffer Object)
    //  That have a texture that then we will pass to the vertex/frag shader that creates the terrain
    //
    obstacles.begin();
    ofClear(0);
    ofSetColor(255);
    normalShader.begin();
    normalShader.setUniformTexture("texture", heightMap,0);
    glBegin(GL_QUADS);
    
    glTexCoord2f(0, 0);
    glVertex2f(0, 0);
    
    glTexCoord2f(1.0, 0);
    glVertex2f(width, 0);
    
    glTexCoord2f(1.0, 1.0);
    glVertex2f(width, height);
    
    glTexCoord2f(0, 1.0);
    glVertex2f(0, height);
    
      glEnd();
    normalShader.end();
    obstacles.end();
    
      ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
    
      ofClear(0,0,0);
    //ofBackground(0);
    
    // Camera!
    cam.begin();
    
    // Action!
    ofPushMatrix();
    
    ofSetColor(255,255,255,255);
    
    fluid.draw(0,0,w,h);
    
    if(drawObstacles) {
        ofSetColor(255,255,255,255);
        obstacles.draw(0,0,w,h);
        //fluid.drawVelocity();
    }
    
    
    //  Center the mesh;
    //
    ofTranslate(-ofGetWidth()*0.5, -ofGetHeight()*0.5);
    
    //  Draw the mesh applying the shader that will move the points to different height
    //  acording to the texture
    //
    terrainShader.begin();
    terrainShader.setUniformTexture("heightMap", heightMap,0);
    terrainShader.setUniformTexture("normalMap", obstacles,1);
    terrainShader.setUniform1f("time",ofGetElapsedTimef());     // We can play with this later ;)
    if(bWireframe){
        terrain.drawWireframe();
    } else {
        terrain.draw();
    }
    terrainShader.end();
    
    ofPopMatrix();
    
    cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if( key == 'p')
        bPaint = !bPaint;
    if( key == 'o')
        bObstacle = !bObstacle;
    if( key == 'b')
        bBounding = !bBounding;
    if( key == 'c')
        bClear = !bClear;

    if(key == 'w'){
        bWireframe = !bWireframe;
    } else {
        terrainShader.load("terrain");
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