#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofEnableDepthTest();
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetCircleResolution(100);
	this->resolution = 5;
	this->timer_1 = 0;
	this->timer_2 = 0;
	
	float i = 0;
	float side_length = 500;

	while (i < side_length) {
		this->positions_vector.push_back(glm::vec3(i, 0, 0));
		i += this->resolution;
	}
	i = 0;

	while (i < side_length) {
		this->positions_vector.push_back(glm::vec3(side_length, i, 0));
		i += this->resolution;
	}

	i = 0;

	while (i < side_length) {
		this->positions_vector.push_back(glm::vec3(side_length - i, side_length, 0));
		i += this->resolution;
	}


	i = 0;

	while (i < side_length) {
		this->positions_vector.push_back(glm::vec3(0, side_length - i, 0));
		i += this->resolution;
	}



}

//--------------------------------------------------------------
void ofApp::update(){
	this->timer_1 += 5;
	this->timer_2 += .1;
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	int i;

	int size = (int)positions_vector.size()*.75;
	int array_size = (int)positions_vector.size();
	int start = (int)this->timer_1 % (array_size);

	auto color = ofColor();

	ofRotateY(ofGetFrameNum()*.8);

	ofSetColor(0, 0, 0);
	for (i = start; i < start + size; i++) {

		auto change = ofMap(sin(this->timer_2/5) + 1, 0, 2, 0, 10);
		auto center = glm::vec3(250, 250, 0);

		// Drawing 1
		color.setHsb(ofMap(i,start,start+size,140 + change,160 + change), 180, 220);
		ofSetColor(color);
		ofDrawSphere(positions_vector[i% (array_size)] - center, 35);

		// Drawing 2
		color.setHsb(ofMap(i, start, start + size, 180+change, 210 + change), 180, 220);
		ofSetColor(color);
		auto vec = 2 * (positions_vector[(i + (array_size / 2)) % (array_size)] - center);
		float angle = (PI / 2);
		auto rotated_vector = glm::rotate(vec, angle, glm::vec3(0.0f, 1.0f, 0.0f));
		ofDrawSphere(rotated_vector, 35);

		// Drawing 3
		color.setHsb(ofMap(i, start, start + size, 210 + change, 250 + change), 180, 210);
		ofSetColor(color);
		vec = 3 * (positions_vector[(i + (array_size / 4)) % (array_size)] - center);
		ofDrawSphere(vec, 35);

	}
	cam.end();
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
