
/*_____________________________
 openFrameworks tutorial, part II: Video Texture Mapping
 Sabine Rosenberg
 
 */


#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    video.loadMovie( "sea.mov" );	//Load the video file
	video.play();                           //Start the video
    
    //setup fbo
    fbo.allocate(videoWidth, videoHeight);
    // clear fbo
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    //Set up vertices and colors
	for (int y=0; y<H; y++) {
		for (int x=0; x<W; x++) {
			mesh.addVertex(ofPoint((x - W/2) * meshSize, (y - H/2) * meshSize, 0 ));
            // adding texure coordinates allows us to bind textures to it later
            // --> this could be made into a function so that textures can be swapped / updated
            mesh.addTexCoord(ofPoint(x * (videoWidth / W), y * (videoHeight / H)));
			mesh.addColor(ofColor( 255, 255, 255 ));
		}
	}
    
	//Set up triangles' indices
	for (int y=0; y<H-1; y++) {
		for (int x=0; x<W-1; x++) {
			int i1 = x + W * y;
			int i2 = x+1 + W * y;
			int i3 = x + W * (y+1);
			int i4 = x+1 + W * (y+1);
			mesh.addTriangle( i1, i2, i3 );
			mesh.addTriangle( i2, i4, i3 );
		}
	}
}

//--------------------------------------------------------------
void testApp::update(){

    //update video
    video.update();
    
    if (video.isFrameNew()) {
        // draw video into fbo
        fbo.begin();
        
        int alpha = 20; // amount of smoothing
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, alpha);
        
        // draw image into fbo
        video.draw(0, 0);
        ofDisableAlphaBlending();
        fbo.end();
    }
    
    //convert fbo to ofImage format
    fbo.readToPixels(fboPixels);
    image.setFromPixels(fboPixels);
    
    //Change vertices
	for (int y=0; y<H; y++) {
		for (int x=0; x<W; x++) {
            
            //Vertex index
			int i = x + W * y;
			ofPoint p = mesh.getVertex( i );
            
            float scaleX = videoWidth / W;
            float scaleY = videoHeight / H;
            
            // get brightness
            int index = ((x * scaleX) + videoWidth * (y * scaleY)) * 4; // fbo has four components (including Alpha)
            int brightness = fboPixels[index] / 4; // 4 is an arbitrary scalar  to reduce the amount of distortion
            
			//Change z-coordinate of vertex
			p.z = brightness; // ofNoise(x * 0.05, y * 0.05, ofGetElapsedTimef() * 0.5) * 100;
			mesh.setVertex( i, p );
            
			//Change color of vertex
            mesh.setColor(i , ofColor(255, 255, 255));
		}
	}


}

//--------------------------------------------------------------
void testApp::draw(){
    
    //Set background to black and rendering color to white
    ofBackground(0);
    ofSetHexColor(0xffffff);
    
//    fbo.draw(0, 0);
    
    ofPushMatrix(); //Store the coordinate system
	
    //Move the coordinate center to screen's center
	ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );
    
    tiltCurrent = ofLerp(tiltCurrent, tiltTarget, 0.1);
    turnCurrent = ofLerp(turnCurrent, turnTarget, 0.1);
    ofRotateX(tiltCurrent);
    ofRotateZ(turnCurrent);
    
    //Draw mesh
    image.bind();
    mesh.draw();
    image.unbind();
//    mesh.drawWireframe();
	ofPopMatrix(); //Restore the coordinate system
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == OF_KEY_DOWN){
        tiltTarget -= 5;
    } else if (key == OF_KEY_UP){
        tiltTarget += 5;
    } else if (key == OF_KEY_LEFT){
        turnTarget -= 5;
    } else if (key == OF_KEY_RIGHT){
        turnTarget += 5;
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
