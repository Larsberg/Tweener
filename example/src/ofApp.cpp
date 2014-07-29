#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	c.set(70, 255, 90);
	auto t = tweens.addTween(&c, ofColor(0,0,0, 10), ofColor(255, 10), 3000, 100, Tween::Ease::Bounce::Out)->yoyo()->loop();
	t->setOnComplete(onComplete);
	
	//ball
	tweens.addTween(&position.x, -200.f, 200.f, 500, 0, Tween::Ease::Sinusoidal::InOut)->yoyo()->loop();
	tweens.addTween(&position.y, -200.f, 200.f, 500, 250, Tween::Ease::Sinusoidal::InOut)->yoyo()->loop();
	tweens.addTween(&ballColor, ofColor(255,255,0), ofColor(0,255,255), 3000)->loop();

	ofSetBackgroundAuto(false);
	ofSetDepthTest(true);
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
//	ofBackground(c);
	glClear( GL_DEPTH_BUFFER_BIT );
	
	ofSetDepthTest(false);
	ofBackgroundGradient(c, ofFloatColor(0,0,0,.1));
	
	camera.begin();
	
	ofSetDepthTest(true);
	ofNoFill();
	ofSetColor(0, 0, 0, 10);
	ofCircle(0, 0, 200);
	
	ofFill();
	ofSetColor(ballColor);
	ofDrawSphere(position, 15);
	
	camera.end();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	
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
void ofApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
	
}
