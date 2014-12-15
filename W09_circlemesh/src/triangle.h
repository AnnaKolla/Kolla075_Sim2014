//
//  triangle.h
//  circlemesh
//
//  Created by Annelie Koller on 12/8/14.
//
//

#ifndef __circlemesh__triangle__
#define __circlemesh__triangle__

#include "vertex.h"
#include "ofMain.h"

class Triangle {
    
    
public:
    
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
    
    
    void rotate(float x, float y, float z);
     
    
    void translate(float x, float y, float z);
    
    vector<Vertex>
    
};


#endif /* defined(__circlemesh__triangle__) */
