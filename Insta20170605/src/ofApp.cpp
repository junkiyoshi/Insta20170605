#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("20170605");

	this->noise_x = ofRandom(10);
	this->noise_y = ofRandom(10);
	this->noise_z = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	ofRotateY(90);

	float x, y, z;
	float noise_value = 0.05;
	float tmp_noise_x = this->noise_x;
	float tmp_noise_y = this->noise_y;
	float tmp_noise_z = this->noise_z;

	for (float len = ofGetWidth(); len > 0; len -= ofGetWidth() / 50) {

		x = len * ofMap(ofNoise(tmp_noise_x), 0, 1, 0, 0.5);
		y = len * ofMap(ofNoise(tmp_noise_y), 0, 1, 0, 0.5);
		z = len * ofMap(ofNoise(tmp_noise_z), 0, 1, 0, 0.5);

		ofLine(ofVec3f(x, y, z), ofVec3f(-x, y, z));
		ofLine(ofVec3f(x, -y, z), ofVec3f(-x, -y, z));
		ofLine(ofVec3f(x, y, -z), ofVec3f(-x, y, -z));
		ofLine(ofVec3f(x, -y, -z), ofVec3f(-x, -y, -z));

		tmp_noise_x += noise_value;
		tmp_noise_y += noise_value;
		tmp_noise_z += noise_value;
	}

	this->noise_x += 0.025;
	this->noise_y += 0.025;
	this->noise_z += 0.025;

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
