/*
 -----------------------------------------------------------------
 SPECTRAL
 -----------------------------------------------------------------
 BY HUBRIS [cargocollective.com/hubris]
 LISBON á APRIL 2014
 -----------------------------------------------------------------
 FINAL VERSION
 -----------------------------------------------------------------
 USING THE FOLLOWING ADD-ON:
 ofxPostProcessing [http://www.neilmendoza.com/ofxpostprocessing/]
 -----------------------------------------------------------------
 */

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
