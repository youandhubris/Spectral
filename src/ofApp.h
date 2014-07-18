#pragma once

#include "ofMain.h"
#include "ofxPostProcessing.h"

class ofApp : public ofBaseApp
{
public:
    static const unsigned NUM_BOXES = 1;
    
    void setup();
    void update();
    void draw();
    
    // scene stuff
    ofxPostProcessing post;
    ofEasyCam cam;
    
    // sound
    ofSoundPlayer sound;  //Sound sample
    const int N = 400;     //Number of bands in spectrum
    float spectrum[ 400 ];   //Smoothed spectrum values
    
    
    ofColor color;

    
    // save as tga
    ofImage myImage;
    int snapCounter;
};
