#include "ofApp.h"

#define q 500
		

int rad_min = 5;
int rad_max = 10;



//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(60);
	Fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
	Fbo.begin();
	ofClear(255, 255, 255, 0);
	Fbo.end();

	ps.populate(q, rad_min, rad_max);

}


//--------------------------------------------------------------
void ofApp::update() {

	ps.p2p_collision();
	ps.erase_repop();


	Fbo.begin();
	ofEnableAlphaBlending();
	ofSetColor(0, 0, 0, 50);
	ps.fbo_trails(5, 0.5);
	// constantly applying a grey square over the scence to blend out the trials
	ofFill();
	ofSetColor(255, 255, 255, 10);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	//
	Fbo.end();

}


//--------------------------------------------------------------
void ofApp::draw(){

	ps.draw_particles();

	Fbo.draw(0,0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


