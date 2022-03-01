#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
	
};

ParticleSystem::ParticleSystem(int quantity, int rad_min, int rad_max) {
	p_rad_min = rad_min;
	p_rad_max = rad_max;
	for (int i = 0; i < quantity; i++) {

		create_particle(rad_min, rad_max);


	}

};

void ParticleSystem::populate(int quantity, int rad_min, int rad_max) {
	p_rad_min = rad_min;
	p_rad_max = rad_max;
	for (int i = 0; i < quantity; i++) {

		create_particle(rad_min, rad_max);
	}

};

void ParticleSystem::p2p_collision() {

	int particle_group_size = particlegroup.size();

	for (int i = 0, j; i < particle_group_size; i++) {
		for (j = 0; j < particle_group_size; j++) {

			// Ball 2 ball collision 
			ofVec2f i_pos(particlegroup[i].get_pos()); //get pos of first particle
			ofVec2f j_pos(particlegroup[j].get_pos()); // get pois of second particle
			int i_rad = particlegroup[i].get_p_rad(); // get rads
			int j_rad = particlegroup[j].get_p_rad();

			float force_modifier = 0.25;

			float distance_between = i_pos.distance(j_pos); //using ofvec.distance (slow) to get the distance between balls
			float touching_distance = i_rad + j_rad; // setting which distance is touching

			if (distance_between <= touching_distance) { // if particles touch

				int particle_i2j_dx = particlegroup[i].get_pos().x - particlegroup[j].get_pos().x; //difference in x between particles
				int particle_i2j_dy = particlegroup[i].get_pos().y - particlegroup[j].get_pos().y; //difference in y

				ofVec2f react_vector_i(particle_i2j_dx, particle_i2j_dy);
				ofVec2f react_force_i = react_vector_i * force_modifier * 1 / i_rad; //add size adjusted force

				int particle_j2i_dx = particlegroup[j].get_pos().x - particlegroup[i].get_pos().x;
				int particle_j2i_dy = particlegroup[j].get_pos().y - particlegroup[i].get_pos().y;

				ofVec2f react_vector_j(particle_j2i_dx, particle_j2i_dy);
				ofVec2f react_force_j = react_vector_j * force_modifier * 1 / j_rad;//add size adjusted force

				particlegroup[i].add_force(react_force_i);
				particlegroup[j].add_force(react_force_j);


			}

		}
		particlegroup[i].update();

	}
}

void ParticleSystem::create_particle(int rad_min, int rad_max) {


	int rand_x = ofRandom(0, ofGetWidth());
	int rand_y = ofRandom(0, ofGetHeight() / 4 * 3);
	int particle_size = ofRandom(rad_min, rad_max);

	Particle temp_particle(rand_x, rand_y, particle_size);
	particlegroup.push_back(temp_particle);
}

void ParticleSystem::erase_repop() {
	for (int i = 0; i < particlegroup.size(); i++) { //removing and repopulating particles
		int particle_y_position = particlegroup[i].get_pos().y;
		if (particle_y_position >= ofGetHeight() * 0.9) { // as long as particle is in last 10% of screen
			if (particlegroup[i].get_bounces_y() >= 2) {
				particlegroup.erase(particlegroup.begin() + i);
				create_particle(p_rad_min, p_rad_max);
			}
		}
	}
}

void ParticleSystem::fbo_trails(int steps, float scale) {

	for (int i = 0; i < particlegroup.size(); i++) {
		for (int j = 0; j < steps; j++) {

			ofVec2f pos = particlegroup[i].get_pos();
			int rad = particlegroup[i].get_p_rad();

			ofDrawCircle(pos, rad * scale);

		}

	}
}

void ParticleSystem::draw_particles() {

	for (int i = 0; i < particlegroup.size(); i++) {

		ofSetColor(255, 255, 255, 255);
		particlegroup[i].draw();

	}

}