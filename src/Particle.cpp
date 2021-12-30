#include "Particle.h"

void Particle::setup(int pos_x, int pos_y, int p_rad) {

	position.set(pos_x, pos_y);
	p_radius = p_rad;
	null_vector.set(0, 0);
}


void Particle::update() {
	
	//debug();
	next_frame();
	
	
	
	//acceleration.set(0, 0);
	
	
}

void Particle::draw() {

	ofDrawCircle(position.x, position.y, p_radius);
}

ofVec2f Particle::drag(ofVec2f vector) {
	ofVec2f drag = fluid_density * vector * (0.1 * p_radius);
	return drag;

}

void Particle::sum_vectors(ofVec2f force, bool collision) {
	ofVec2f n_grav(0, 0); // removing gravity & velocity from collision detection
	if (collision == false) {
		n_grav.set(gravity);
	}


	ofVec2f drag_n = (drag(velocity));
	ofVec2f	acc_n = acceleration + gravity - drag_n + force;
	ofVec2f vel_n = (velocity + acc_n);
	ofVec2f pos_n = position + vel_n;
	
	acceleration.set(acc_n);
	velocity.set(vel_n);
	position.set(pos_n);


}

void Particle::next_frame() {
	
	if (position.y >= ofGetHeight() - p_radius) { // y screen collision
		bounces_y += 1;
		position.set(position.x, ofGetHeight() - p_radius);
		
		int react_vy = velocity.y * -1 * p_bounciness / bounces_y;
		ofVec2f react_force(0, react_vy * 5);

		velocity.set(velocity.x, 0);
		sum_vectors(react_force, true);
		acceleration.set(null_vector);


	}
	else if (position.x >= ofGetWidth() - p_radius) { // x  right screen collision
		bounces_x += 1;
		position.set(ofGetWidth() - p_radius, position.y);

		int react_vx = velocity.x * -1 * p_bounciness / bounces_x;
		ofVec2f react_force(react_vx * 5, 0);

		velocity.set(0, velocity.y);
		sum_vectors(react_force, true);

		acceleration.set(null_vector);

	}	
	else if (position.x <= 0 + p_radius) { // x left screen collision
		bounces_x += 1;
		position.set(0 + p_radius, position.y);


		int react_vx = velocity.x * -1 * p_bounciness / bounces_x;
		ofVec2f react_force(react_vx * 5, 0);

		velocity.set(0, velocity.y);
		sum_vectors(react_force, true);
		acceleration.set(null_vector);

	}
	else {
		sum_vectors(null_vector);
		acceleration.set(null_vector);
	}
		
	
}

void Particle::debug() {
	cout << "position = " << position << "\n";
	cout << "velocity = " << velocity << "\n";
	cout << "acceleration = " << acceleration << "\n";
	cout << "gravity = " << gravity << "\n";
	cout << "over screen bottom " << (ofGetHeight() ) - (position.y + p_radius) << "\n";
	cout << "reacting force = " << reacting_force << "\n";
	cout << "screen height = " << ofGetHeight() << "\n";
	cout << "bottom of ball = " << ofGetHeight() + p_radius;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	
}

void Particle::set_bounciness(float i) {

	p_bounciness = i;

}

void Particle::set_fluid_density(float i) {

	fluid_density = i;
}

void Particle::set_p_radius(int i) {

	p_radius = i;

}

void Particle::reset_bounces() {
	bounces_y = 0();
	bounces_x = 0();
}

ofVec2f Particle::get_pos() {
	return position;
}

int Particle::get_p_rad() {
	return p_radius;
}



void Particle::add_force(ofVec2f force) {

	acceleration.set(acceleration + force);
}