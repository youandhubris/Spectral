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
    
    // Post-processing
    ofxPostProcessing post;
    ofEasyCam cam;
    
    // Sound
    ofSoundPlayer sound;
    const int N = 400;
    float spectrum[ 400 ];
    ofColor color;
};
