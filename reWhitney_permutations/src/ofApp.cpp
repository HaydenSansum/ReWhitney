#include "ofApp.h"

// Main FUNCTIONS
//--------------------------------------------------------------
void ofApp::setup(){
    
    // Set up variables 
    center_pos = ofPoint(350,350);
    point_size = 2;
    N_circles = 10;
    for (int i = 0; i < 50; i++){
        cur_angles.push_back(0);
        rose_ks.push_back(2);
        rose_ns.push_back(1);
    }
    
    
    // Set up drawing
    ofBackground(0);
    ofSetColor(200,20,20);
    
    ofSleepMillis(2000);
    
    //rose_k = 2;
//    rose_n = 1;
    
    ofSetFrameRate(30);
    frame_count = 0;
    
    // GUI
    gui.setup();
    gui.add(freq.setup("freq", 0.001, 0.0001, 0.01));
    gui.add(max_k.setup("max_k", 20, 2, 100));
    gui.add(rose_n.setup("n", 1, 1, 10));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    float cur_time = ofGetElapsedTimef();
    
    for (float i = 0; i < N_circles; i++) {
        cur_angles[i] = cur_angles[i] + ((10+(i/10))*sin(cur_time * ((i+1) * 0.001))*0.02);
    }
    
    if (frame_count % 30) {
        // Every 30 frames update each K - update based on a sine wave of different frequencies
        for (float i = 0; i < N_circles; i++) {
            float k_new = ofMap(sin(cur_time * freq), -1, 1, 2, max_k);
            rose_ks[i] = k_new;
        }
    }
    
    
    frame_count++;
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    for (float i = 0; i < N_circles; i++) {
        float cur_angle = cur_angles[i];
        float cur_rose_k = rose_ks[i];
        draw_rose(300, cur_rose_k, rose_n, cur_angle + (i*0.05), 300, center_pos, point_size);
    }
    
    gui.draw();
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

//--------------------------------------------------------------
void ofApp::draw_rose(float radius, float k, float n, float cur_angle, int resolution, ofPoint center, int point_size){
    
    float angle_segment = (2*PI) / resolution;
    
    for (int i = 0; i < resolution; i++) {
        if ( i % 5 == 0) {
            ofSetColor(255);
        } else {
            ofSetColor(200,20,20);
        }
        float draw_angle = (angle_segment * i);
        
        float rose_radius = cos(k * draw_angle) * radius;
        
        float draw_x = cos(cur_angle + draw_angle) * rose_radius;
        float draw_y = sin(cur_angle + draw_angle) * rose_radius;
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
