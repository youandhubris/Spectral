#include "ofApp.h"

void ofApp::setup()
{
    ofBackground(0);
    ofSetFrameRate(31);
    
    // Setup post-processing
    post.init(ofGetWidth(), ofGetHeight());
    post.createPass<FxaaPass>()->setEnabled(true);
    post.createPass<BloomPass>()->setEnabled(true);
    post.createPass<GodRaysPass>()->setEnabled(true);
    
    
    //Setup sound
    sound.loadSound( "walden.wav" );
    sound.setLoop(false);
    //sound.play();
    
    //Set spectrum values to 0
    for (int i=0; i<N; i++) {
        spectrum[i] = 0.0f;
    }
}

void ofApp::update()
{
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    if (ofGetMousePressed() == true) {
        sound.play();
        // sound.setPositionMS(325000);
    }
    
    //Update sound
    ofSoundUpdate();
    
    float *val = ofSoundGetSpectrum(N);

    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.98;
        spectrum[i] = max(spectrum[i], val[i]);
    }

}

void ofApp::draw()
{
    glPushAttrib(GL_ENABLE_BIT);
    // setup gl state
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    post.begin(cam);
    
    for (int i=0; i<N; i++) {
        color.setHsb(230-i*0.5875, 255, 255-spectrum[i]*(i+1)*2000);
        ofSetColor(color);
        ofRect(-800+i*4, -25+spectrum[i]*3000, -spectrum[i]*(i/20+1)*800, 2, 75-spectrum[i]*6000);
        
        color.setHsb(230-i*0.5875, 255, 255-spectrum[i]*(i+1)*4000);
        ofSetColor(color);
        ofRect(-798+i*4, -25+spectrum[i]*5000, -spectrum[i]*(i/20+1)*800, 2, 75-spectrum[i]*10000);
    }
    
    post.end();
    
    // set gl state back to original
    glPopAttrib();
}