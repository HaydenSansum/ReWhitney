#include "ofApp.h"

// Main FUNCTIONS
//--------------------------------------------------------------
void ofApp::setup(){
    
    // Set up variables 
    center_pos = ofPoint(350,350);
    point_size = 1;
    N_circles = 50;
    for (int i = 0; i < 50; i++){
        cur_angles.push_back(0);
    }
    
    // Set up drawing
    ofBackground(0);
    ofSetColor(200,20,20);
    
    ofSleepMillis(2000);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    float cur_time = ofGetElapsedTimef();
    
    for (float i = 0; i < N_circles; i++) {
        cur_angles[i] = cur_angles[i] + ((10+(i/10))*sin(cur_time * (i * 0.001))*0.001);
    }
}

//ofRandom(0.0005,0.004)

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (float i = 0; i < N_circles; i++) {
        float cur_angle = cur_angles[i];
        draw_circle(10 + (i * 6.5), cur_angle, 10 + (i * 10), center_pos, point_size);
    }
    
}


// User FUNCTIONS
//--------------------------------------------------------------
void ofApp::draw_circle(float radius, float cur_angle, int resolution, ofPoint center, int point_size){
    
    float angle_segment = (2*PI) / resolution;
    
    for (int i = 0; i < resolution; i++) {
        if ( i % 5 == 0) {
            ofSetColor(255);
        } else {
            ofSetColor(200,20,20);
        }
        float draw_angle = cur_angle + (angle_segment * i);
        float draw_x = cos(draw_angle) * radius;
        float draw_y = sin(draw_angle) * radius;
        ofDrawCircle(center.x + draw_x, center.y + draw_y, point_size);
    }
}


// Helper FUNCTIONS
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.save(ofGetTimestampString() + ".png");
    }
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
