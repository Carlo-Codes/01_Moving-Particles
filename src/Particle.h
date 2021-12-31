#pragma once
#include "ofMain.h"


class Particle
{

	ofVec2f position;
	ofVec2f velocity;
	ofVec2f acceleration;
	ofVec2f gravity = ofVec2f(0,0.9);
	int p_radius = 10;
	float fluid_density = 0.1;
	float p_bounciness = 0.5;
	int bounces_y;
	int bounces_x;
	ofVec2f reacting_force;
	ofVec2f drag(ofVec2f vector);
	void next_frame();
	void sum_vectors(ofVec2f ex_force, bool collision = false);

public:
	void setup(int pos_x, int pos_y, int p_rad);
	void update();
	void draw();
	void set_bounciness(float i);
	void set_fluid_density(float i);
	void set_p_radius(int i);
	void reset_bounces();
	ofVec2f get_pos();
	int get_p_rad();
	void add_force(ofVec2f force);
	


	ofVec2f null_vector;

	void debug();


};

