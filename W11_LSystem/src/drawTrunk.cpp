//
//  drawTrunk.cpp
//  LSystem_Nov10
//
//  Created by Annelie Koller on 11/12/14.
//
//

#include "drawTrunk.h"


drawTrunk::drawTrunk(){
    
}



void drawTrunk::draw(int depth, float angle){
    
    ofTranslate(startingPointX, startingPointY);
    
    
    ofSetLineWidth(depth*4);
    ofSetColor(0);
    ofLine(0,ofGetHeight(),0,0);
    drawBranch(depth, angle);
    
    }



void drawTrunk::drawBranch(int depth, float angle) {
    
    float newAngle = angle + angleOffset;
    
    ofPushMatrix();
    ofRotate(newAngle);
    drawLeaf(depth, newAngle);
    ofPopMatrix();
    ofRotate(-newAngle);
    drawLeaf(depth, newAngle);
    
}

void drawTrunk::drawLeaf(int depth, float angle) {
    
    int leafLength = lineLength*depth,
    leafSize = 20;
    
    //appInfo += ofToString(leafLength)+"\n";
    ofTranslate(0,-leafLength);
    ofSetLineWidth(depth);
    
    ofLine(0,leafLength,0,0);
    
    if(depth == 0) {
        ofEnableAlphaBlending();
        ofSetColor(ofRandom(255),0,0,15);
        
        if (ofRandom(100) > 0) {
            ofFill();
            ofEllipse(0,0,leafSize,leafSize);
        }
        ofSetColor(255,255,255);
    }
    if(depth>0){
        drawBranch(depth-1, angle);
    }
    
}

