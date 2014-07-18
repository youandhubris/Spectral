#include "ofApp.h"

void ofApp::setup()
{
    ofBackground(0);
    ofSetFrameRate(31);
    
    // Setup post-processing chain
    post.init(ofGetWidth(), ofGetHeight());
    post.createPass<FxaaPass>()->setEnabled(true);
    post.createPass<BloomPass>()->setEnabled(true);
    post.createPass<GodRaysPass>()->setEnabled(true);
    
    
    //Set up sound sample
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
    
    //Update sound engine
    ofSoundUpdate();   //Get current spectrum with N bands
    float *val = ofSoundGetSpectrum(N);
    //We should not release memory of val,
    //because it is managed by sound engine
    //Update our smoothed spectrum,
    //by slowly decreasing its values and getting maximum with val
    //So we will have slowly falling peaks in spectrum
    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.98;    //Slow decreasing
        spectrum[i] = max(spectrum[i], val[i]);
    }

}

void ofApp::draw()
{
    glPushAttrib(GL_ENABLE_BIT); // copy enable part of gl state
    // setup gl state
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    post.begin(cam); // begin scene to post process
    
    // draw lines
    for (int i=0; i<N; i++) {
        color.setHsb(230-i*0.5875, 255, 255-spectrum[i]*(i+1)*2000);
        ofSetColor(color);
        ofRect(-800+i*4, -25+spectrum[i]*3000, -spectrum[i]*(i/20+1)*800, 2, 75-spectrum[i]*6000);
        
        color.setHsb(230-i*0.5875, 255, 255-spectrum[i]*(i+1)*4000);
        ofSetColor(color);
        ofRect(-798+i*4, -25+spectrum[i]*5000, -spectrum[i]*(i/20+1)*800, 2, 75-spectrum[i]*10000);
    }
    
    post.end(); // end scene and draw
    
    // set gl state back to original
    glPopAttrib();
    
    /* save as tga
    myImage.grabScreen(0,0,1920,200);
    myImage.saveImage("partOfTheScreen-"+ofToString(snapCounter)+".tga");
    snapCounter++;
     */
    
    
}