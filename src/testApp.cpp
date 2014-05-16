#include "testApp.h"

int width,height;
ofLight light;
ofMaterial material;
ofEasyCam cam;
ofImage matCap;
ofShader shader;

void testApp::setup() {
	 width=ofGetWidth();
         height=ofGetHeight();
//	 ofSetSmoothLighting(true);
//         light.setDiffuseColor( ofFloatColor(85, 245, 55) );
//         light.setSpecularColor( ofFloatColor(1, 133, 234));
//         material.setShininess( 120 );
//         material.setSpecularColor(ofColor(5, 5, 255, 55));
//         light.setPosition(200,200,200);
	 ofEnableDepthTest();
	 ofDisableArbTex();
         matCap.loadImage("matcap.jpg");
         shader.load("sem");
}

void testApp::draw() {
   ofBackgroundGradient(ofColor(95),ofColor(0),OF_GRADIENT_CIRCULAR);
   cam.begin();
   shader.begin();
   shader.setUniformTexture("tMatCap", matCap, 1);
   float scale = ofGetHeight() / 3;
//   ofEnableDepthTest();
//   ofEnableLighting();
//   light.enable();
//   material.begin();
   Fractal(0,0,0,40,0.4,5);
//   material.end();
//   ofDisableLighting();
//   ofDisableDepthTest();
   shader.end();
   cam.end();
}

void testApp::Fractal(float x,float y,float z,float s, float f, int l){
  ofTranslate(x,y,z);
  ofFill();
  ofDrawBox(s);
  ofNoFill();
  ofSetColor(0);
  ofDrawBox(s);
  l--;
  if (l>0) {
    float ox=-s/2;
    float oy=-s/2;
    float oz=-s/2;
    ofPushMatrix(); Fractal(ox,oy,oz,s*f,f,l); ofPopMatrix();
    ofPushMatrix(); Fractal(ox+s,oy,oz,s*f,f,l); ofPopMatrix();
    ofPushMatrix(); Fractal(ox,oy+s,oz,s*f,f,l); ofPopMatrix();
    ofPushMatrix(); Fractal(ox+s,oy+s,oz,s*f,f,l); ofPopMatrix();
    ofPushMatrix(); Fractal(ox,oy,oz+s,s*f,f,l); ofPopMatrix();
    ofPushMatrix(); Fractal(ox+s,oy,oz+s,s*f,f,l); ofPopMatrix();
    ofPushMatrix(); Fractal(ox,oy+s,oz+s,s*f,f,l); ofPopMatrix();
    ofPushMatrix(); Fractal(ox+s,oy+s,oz+s,s*f,f,l); ofPopMatrix();
  }
}
