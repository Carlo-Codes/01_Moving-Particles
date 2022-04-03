#pragma once
#include "ofMain.h"
#include "Particle.h"

class ParticleSystem 
{


	vector <Particle> particlegroup;


	int p_rad_min;
	int p_rad_max;
	int quantity;



public:
	ParticleSystem();
	ParticleSystem(int quantity, int p_rad_min, int p_rad_max);
	void populate(int quantity, int p_rad_min, int p_rad_max);
	void p2p_collision();
	
	void create_particle(int rad_min, int rad_max);
	void erase_repop();
	void fbo_trails(int steps, float scale);
	void draw_particles();

	void mouse_press_force(int x, int y, int button);//, vector <Particle>& particlegroup);

	vector <Particle> get_particlegroup();


};