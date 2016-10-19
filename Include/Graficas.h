#ifndef GRAFICAS_H
#define GRAFICAS_H

#include "ofxHistoryPlot.h"
#include "GestorArchivo.h"


class Graficas {

private :
 std::vector<ofxHistoryPlot *>  graficas;
 int margen=256;
 GestorArchivo File;
 std::string ip;


public:

 Graficas();


 virtual ~Graficas();

 bool mousePressed(ofMouseEventArgs &arg);

 void draw(float x, float y, int width, int height);

 void update();

 void setup();

 void setIPs(std::string);

 string getIps();


};
#endif // GRAFICAS_H
