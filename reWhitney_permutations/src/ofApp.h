#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void draw_circle(float radius, float cur_angle, int resolution, ofPoint center, int point_size);
        void draw_rose(float radius, float k, float n, float cur_angle, int resolution, ofPoint center, int point_size);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    // Variables
    ofPoint center_pos;
    int N_circles;
    int point_size;
    vector<float> cur_angles;
    
    // Rose parameters
    float rose_k;
    float rose_n;
    
    // Helpers
    ofImage img;
    int frame_count;
		
};
