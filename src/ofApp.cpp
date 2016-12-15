#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //slid.setup("MEDIDOR",50,0,100);
    //grups.setName("settings");
    //grups.add(slid.getParameter());
    //panel.setup(grups);
    //panel.setPosition(ofGetWidth()/2,0);
	//ofSetFullscreen(true);
	ofSetVerticalSync(true);
	IPs = gesArch.loadIps();
	gui = new ofxUISuperCanvas("IP");
	gui->addSpacer();
	gui->setWidgetFontSize(OFX_UI_FONT_SMALL);
	gui->setPosition(0, 0);
	ddl = gui->addDropDownList("lista Ip",IPs);
	gui->autoSizeToFitWidgets();
	//ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
   crearGrafica();
}

//--------------------------------------------------------------
void ofApp::update(){
	int t = gesArch.getSizeFil();
	if (t != gesArch.sizeFile()) {
		gesArch.setSizeFil(gesArch.sizeFile());
		ddl->addToggle(gesArch.finalIp(t));
	}
   for(int i=0;i<grafi.size();i++){
       Graficas *gra=grafi.at(i);
       gra->update();
   }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //
    int x=1024;
    //crear el ajuste del 6 para el total
    for(int i=0;i<grafi.size();i++){
        Graficas *gra=grafi.at(i);
        switch(i){
             case(0):
                gra->draw(x,0,ofGetWidth(),ofGetHeight());
                break;

             case(1):
                x-=ofGetWidth()/4.9;
                 gra->draw(x,0,ofGetWidth(),ofGetHeight());
                 break;

             case(2):
                 x-=ofGetWidth()/4.9;
                 gra->draw(x,0,ofGetWidth(),ofGetHeight());
                 break;

             case(3):
                x=1024;
                gra->draw(x,(ofGetHeight()/15*7)+4,ofGetWidth(),ofGetHeight());
                 break;

             case(4):
            x-=ofGetWidth()/4.9;
            gra->draw(x,(ofGetHeight()/15*7)+4,ofGetWidth(),ofGetHeight());
                 break;

             case(5):
            x-=ofGetWidth()/4.9;
            gra->draw(x,(ofGetHeight()/15*7)+4,ofGetWidth(),ofGetHeight());
                 break;
        }
    }
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
  //panel.setSize(0,0);
   //panel.getFloatSlider("MEDIDOR").setSize(0,0);
   //gui->setVisible(false);


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
//--------------------------------------------------------------


void ofApp::crearGrafica(){
    for(int i=0;i<IPs.size();i++){
        Graficas *gra = new Graficas();
        gra->setIPs(IPs.at(i));
        gra->setup();
        grafi.push_back(gra);
    }
}

