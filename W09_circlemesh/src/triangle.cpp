//
//  triangle.cpp
//  circlemesh
//
//  Created by Annelie Koller on 12/8/14.
//
//

#include "triangle.h"

vector<Vertex> v;



Triangle(Vertex a, Vertex b, Vertex c); {
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
};

Triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    v.push_back(Vertex(x1,y1));
    v.push_back(Vertex(x2,y2));
    v.push_back(Vertex(x3,y3));
}

vector<Triangle> subdivide() {
    float ab = v[0].distance(v[1]);
    float bc = v[1].distance(v[2]);
    float ca = v[2].distance(v[0]);
    
    int longest = ab>bc && ab>ca ? 0 : bc>ab && bc>ca ? 1 : 2;
    
    int a=(longest+0)%3;
    int b=(longest+1)%3;
    int c=(longest+2)%3;
    
    vector<Triangle> t;
    t.push_back(Triangle(v[a].getMiddle(v[b]),v[c],v[a]));
    t.push_back(Triangle(v[a].getMiddle(v[b]),v[b],v[c]));
    return t;
}

void rotate(float x, float y, float z) {
    foreach(vv,v) vv.rotate(x,y,z); endfor
}

void translate(float x, float y, float z) {
    foreach(vv,v) vv += ofVec3f(x,y,z); endfor
}