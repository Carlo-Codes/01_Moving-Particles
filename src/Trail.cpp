#include "Trail.h"

Trail::Trail(ofVec3f pos, int rad) {
	radius = rad;
	positions.push_back(pos);
	ofColor tran_white(255, 255, 255, 0);


}


void Trail::update(ofVec3f pos) {

	if (positions.size() > max_pos) {

		positions.erase(positions.begin());
		trail_line.removeVertex(0);
	}
	positions.push_back(pos);
	trail_line.addVertex(pos);
	
}

void Trail::draw() {
	ofEnableAlphaBlending();
	int offsets = 5;
	float scaling = 0.8;
	
	for (int i = 0; i < positions.size(); i++) {
		ofSetColor(tran_white);
		//ofDrawCircle(positions[i], radius * scaling);
		
	}
	
	trail_line.draw();
}


vector <glm::vec3> Trail::get_positions() {
	
	return positions;

}

void Trail::remove_first_pos() {

	positions.erase(positions.begin());

}

void Trail::debug() {




}