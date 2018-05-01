#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxGrafica.h"
#include "top_tracks.h"

class ofApp : public ofBaseApp{

public:
		void setup();
		void update();
		void draw();

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

		void setupColors();
		void setupHistograms();
		void setupGUI();
		vector<vector<ofxGPoint>> calculateHistograms(vector<vector<pair<string, double>>> dataset,
			int start_limit, int end_limit, vector<double> means, vector<double> stds);
		void histogramUpdate();
		void setupTitles(vector<vector<pair<string, double>>> dataset);
		void setupBounds(vector<double> means, vector<double> stds);

		void onButtonEvent(ofxDatGuiButtonEvent e);
		void onTextInputEvent(ofxDatGuiTextInputEvent e);

		// Drawing functions
		void drawStartScreen();
		void drawInstructionScreen();
		void drawHistograms();
		void drawPredictions();
private:
	// Spotify themed colors
	ofColor black_;
	ofColor green_;
	ofColor grey_;

	ofTrueTypeFont title_font_;
	ofTrueTypeFont font_;
	// From examples
	ofxDatGuiTextInput* input_;
	ofxDatGuiButton* start_button_;
	ofxDatGuiButton* prediction_button_;

	ofxGPlot plot_;
	vector<vector<ofxGPoint>> histogram_points_l_;
	vector<vector<ofxGPoint>> histogram_points_d_;
	vector<string> histogram_titles_;

	vector<double> lower_bounds_;
	vector<double> upper_bounds_;

	int current_index_ = 0;
	int feature_size_;

	// Flags to determine which screen
	bool start_ = true;
	bool instruction_ = false;
	bool histogram_ = false;
	bool prediction_ = false;
	
	ofImage parameters_;
	ofImage globals_;

};
