#pragma once

#include "ofMain.h"

#include "Particle.h"

#include "Trail.h"




class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		

		ofFbo trail_Fbo;

	
		

		
};


// to do 

// add particle system class

// **use pointers instead -- see https://openframeworks.cc/ofBook/chapters/memory.html

// ***add particles randomly popping in and out of existence

// Gradually remove particles

// add clicking force and black hole attraction

// fuck around with FBO