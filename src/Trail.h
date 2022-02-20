#pragma once
#include "ofMain.h"

class Trail
{
	int radius;
	ofColor tran_white;
	int max_pos = 25; //trail length
	ofPolyline trail_line;
	



	public:
		Trail(ofVec3f pos, int rad);
		void update();
		void draw();
		void debug();
		void remove_pos(int i);
		void add_position(ofVec3f pos);
		void remove_last();
		

		vector <glm::vec3> get_verticies();
};

