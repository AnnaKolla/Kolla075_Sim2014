//
//  drawTrunk.h
//  LSystem_Nov10
//
//  Created by Annelie Koller on 11/12/14.
//
//

#ifndef __LSystem_Nov10__drawTrunk__
#define __LSystem_Nov10__drawTrunk__

#include "ofMain.h"

class drawTrunk{
    
public:

    drawTrunk();
   
    
    //void setup();
    
    void draw(int depth, float angle);
    
    //void drawBase(int depth, float angle);
    
    int depth;
    float angle;
    
    int startingPointX;
    int startingPointY;
    
    void drawBranch(int depth, float angle);
    
    float angleOffset;
    
    void drawLeaf(int depth, float angle);
    
    float leafLength;
    float lineLength;
    
    
};

#endif /* defined(__LSystem_Nov10__drawTrunk__) */
