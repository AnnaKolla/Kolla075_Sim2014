#include "ofApp.h"

/*tutorial for 3D colouring
 
 by  Rick Companje*/


 
 
#define foreach(t,v) for(typeof(v.begin()) p=v.begin(); p!=v.end(); p++) { typeof(*p) &t=*p;
#define endfor }

class Vertex : public ofVec3f {
public:
    Vertex(float x, float y) : ofVec3f(x,y) {}
    Vertex(ofVec3f v) { set(v); }
    ofFloatColor color;
    ofVec3f normal;
};

class Triangle {
public:
    vector<Vertex> v;
    
    Triangle() {};
    
    Triangle(Vertex a, Vertex b, Vertex c) {
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
    
};

class Rectangle {
public:
    vector<Triangle> triangles;
    
    Rectangle() { };
    
    Rectangle(float x, float y, float w, float h) {
        set(x,y,w,h);
    }
    
    void set(float x, float y, float w, float h) {
        triangles.clear();
        triangles.push_back(Triangle(x,y+h,x+w,y,x,y));
        triangles.push_back(Triangle(x,y+h,x+w,y+h,x+w,y));
    }
    
    void setColors(ofFloatColor lt, ofFloatColor rt, ofFloatColor rb, ofFloatColor lb) {
        if (triangles.size()) {
            triangles[0].v[0].color = lb;
            triangles[0].v[1].color = rt;
            triangles[0].v[2].color = lt;
            triangles[1].v[0].color = lb;
            triangles[1].v[1].color = rb;
            triangles[1].v[2].color = rt;
        }
    }
    
    void subdivide(int depth=0) {
        if (depth==0) return;
        for (int d=0; d<depth; d++) {
            vector<Triangle> tmp;
            foreach (t1,triangles)
            vector<Triangle> divided=t1.subdivide();
            foreach(t2,divided)
            tmp.push_back(t2);
            endfor
            endfor
            triangles = tmp;
        }
    }
    
    vector<Vertex> getVertices() {
        vector<Vertex> vertices;
        foreach(triangle,triangles)
        foreach(v,triangle.v)
        vertices.push_back(v);
        endfor
        endfor
        return vertices;
    }
    
    void rotate(float x, float y, float z) {
        foreach(t,triangles) t.rotate(x,y,z); endfor
    }
    
    void translate(float x, float y, float z) {
        foreach(t,triangles) t.translate(x,y,z); endfor
    }
};

class Box {
public:
    
    vector<Rectangle> sides;
    
    Box() { }
    
    Box(float s, int depth=0) {
        set(s);
        subdivide(depth);
    }
    
    void set(float s) {
        for (int i=0; i<6; i++) {
            Rectangle side(-s/2,-s/2,s,s);
            side.translate(0,0,s/2);
            side.rotate(i==4 ? 90 : i==5 ? -90 : 0, i<4?i*90 : 0, 0);
            sides.push_back(side);
        }
    }
    
    void subdivide(int depth=0) {
        foreach (side,sides)
        side.subdivide(depth);
        endfor
    }
    
    vector<ofVec3f> getVertices() {
        vector<ofVec3f> v;
        foreach (rect,sides)
        vector<Vertex> vertices = rect.getVertices();
        foreach (vertex,vertices)
        v.push_back(vertex);
        endfor
        endfor
        return v;
    }
    
    vector<ofFloatColor> getColors() {
        vector<ofFloatColor> c;
        foreach (rect,sides)
        vector<Vertex> vertices = rect.getVertices();
        foreach (vertex,vertices)
        float r = vertex.normalized().x+.5;
        float g = vertex.normalized().y+.5;
        float b = vertex.normalized().z+.5;
        c.push_back(ofFloatColor(r,g,b));
        endfor
        endfor
        return c;
    }
    
    vector<ofVec3f> getNormals() {
        vector<ofVec3f> n;
        foreach (rect,sides)
        vector<Vertex> vertices = rect.getVertices();
        foreach (vertex,vertices)
        float r = vertex.normalized().x;
        float g = vertex.normalized().y;
        float b = vertex.normalized().z;
        n.push_back(ofVec3f(r,g,b));
        endfor
        endfor
        return n;
    }
};

class Sphere : public Box {
public:
    Sphere(float s, float depth) : Box(s, depth) {
        foreach(side,sides)
        foreach(triangle,side.triangles)
        foreach(v,triangle.v)
        v.normalize()*=s;
        endfor
        endfor
        endfor
    }
};

void ofApp::setup() {
    ofBackground(0);
    ofSetWindowShape(500,500);
    ofEnableLighting();
    light.enable();
    light.setAmbientColor(ofColor(0,0,0)); //255,255,255));
    glEnable(GL_DEPTH_TEST);
    Sphere b(250,0);
    mesh.addVertices(b.getVertices());
    mesh.addColors(b.getColors());
    mesh.addNormals(b.getNormals());
    wireFrame = false;
}

void ofApp::update() {
    ofSetWindowTitle(ofToString(ofGetFrameRate(),2));
}

void ofApp::draw(){
    camera.begin();
    if (wireFrame) mesh.drawWireframe();
    else mesh.draw();
}

void ofApp::keyPressed(int key) {
    if (key>='0' && key<='9') {
        Sphere b(250,key-'0');
        mesh.clear();
        mesh.addVertices(b.getVertices());
        mesh.addNormals(b.getNormals());
        mesh.addColors(b.getColors());
    }
    
    if (key=='w') wireFrame=!wireFrame;
    if (key=='l') { ofEnableLighting(); }
    if (key=='L') { ofDisableLighting();  }
    
}