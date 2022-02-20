#include "Trail.h"

Trail::Trail(ofVec3f pos, int rad) {
	radius = rad;
	trail_line.addVertex(pos);
	ofColor tran_white(255, 255, 255, 0);


}


void Trail::update() {


	if (trail_line.getVertices().size() > max_pos) {
		trail_line.removeVertex(0);
	}



}

void Trail::draw() {
	ofEnableAlphaBlending();
	int offsets = 5;
	float scaling = 0.8;
	
	
	trail_line.draw();
}


vector <glm::vec3> Trail::get_verticies() {
	
	return trail_line.getVertices();

}

void Trail::remove_pos(int i) {


	trail_line.removeVertex(i);

}

void Trail::debug() {




}


void Trail::add_position(ofVec3f pos) {
	trail_line.addVertex(pos);
}

void Trail::remove_last() {

	trail_line.removeVertex(trail_line.getVertices().size());

}