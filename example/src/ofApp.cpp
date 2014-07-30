#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

	ofSetBackgroundAuto(false);
	ofSetDepthTest(true);
	
	//background
	c.set(70, 255, 90);
	auto t = tweens.addTween(&c, ofColor(0,0,0, 5), ofColor(155, 5), 3000, 100, Tween::Ease::Bounce::Out)->yoyo()->loop();
	t->setOnComplete(onComplete);
	
	//circling balls
	colors.resize(100);
	positions.resize(colors.size());
	
	for(int i=0; i<positions.size(); i++)
	{
		//position
		float speed = ofRandom(200, 2000);
		positions[i].x = i * 80 - (positions.size() * .5 * 80.);
		tweens.addTween(&positions[i].y, -200.f, 200.f, speed, 0, Tween::Ease::Sinusoidal::InOut)->yoyo()->loop();
		tweens.addTween(&positions[i].z, -200.f, 200.f, speed, speed * .5, Tween::Ease::Sinusoidal::InOut)->yoyo()->loop();
		
		//color
		tweens.addTween(&colors[i],
						ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255), 255),
						ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255), 255),
						ofRandom(400, 2000))->loop()->yoyo();
	}
	
	//tween curve
	crv = new Tween::TweenCurve<float>(&f1, 0.f, -40.f, 0, 1000, Tween::Ease::Sinusoidal::InOut);
	tweens.addTween(crv)->loop()->setOnUpdate(onUpdateFloatCurve);
	
	crv->addPoint(.75, 50., Tween::Ease::Bounce::InOut);
	crv->addPoint(.5, 0., Tween::Ease::Cubic::In);
	crv->addPoint(.25, -25., Tween::Ease::Cubic::Out);
	
	//create a polyline for drawing to the screen
	float step = 1. / (400-1);
	for(int i=0; i<400; i++)
	{
		float sample = crv->sample(step * i);
		curveLine.addVertex(ofVec3f(i, sample, 10));
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
	glClear( GL_DEPTH_BUFFER_BIT );
	ofBackgroundGradient(ofFloatColor(0.1,0.11,0.13,.05), ofFloatColor(0,0,0,.05));
	
	camera.begin();
	
	ofEnableDepthTest();
	
	for(int i=0; i<positions.size(); i++)
	{
		ofSetColor(colors[i]);
		ofDrawSphere(positions[i], 35);
	}
	
	camera.end();
	
	
	//draw tween curve
	ofPushMatrix();
	ofTranslate(0, 50);
	
	//	background rectangle
	ofSetColor(0, 0, 0, 30);
	ofRect(0,-50,400,100);
	
	//	curve polyline
	ofSetLineWidth(1);
	ofSetColor(255, 100);
	curveLine.draw();
	
	//	draw a sphere at the current value
	ofSetColor(255,255, 0);
	ofDrawSphere( crv->getProgress() * 400, crv->getValue(), 10, 4);
	
	ofPopMatrix();
	
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
