#include "../Include/Graficas.h"




Graficas::Graficas(){



}


Graficas::~Graficas(){


}

void Graficas::draw(float x, float y, int width, int height){
    for(int i=0;i<7;i++){
            ofxHistoryPlot *pl=graficas.at(i);
            switch(i){
                 case(0):
                      pl->draw(x,y,width/5,height/15);
                    break;

                 case(1):
                     y+=height/15;
                     pl->draw(x,y+1,width/5,height/15);
                     break;

                 case(2):
                      y+=height/15;
                     pl->draw(x,y+1,width/5,height/15);
                     break;

                 case(3):
                    y+=height/15;
                     pl->draw(x,y+1,width/5,height/15);
                     break;

                 case(4):
                     y+=height/15;
                         pl->draw(x,y+1,width/5,height/15);
                     break;

                 case(5):
                     y+=height/15;
                         pl->draw(x,y+1,width/5,height/15);
                     break;

                 case(6):
                 y+=height/15;
                     pl->draw(x,y+1,width/5,height/15);
                     break;
              }
        }
}

void Graficas::update(){

    for(int i=0;i<7;i++){
           ofxHistoryPlot *pl=graficas.at(i);
           switch(i){
                case(0):
                     pl->update((float)File.readFile(ip+ "\\" + "ECGSig1.txt"));
                   break;

                case(1):
                    pl->update((float)File.readFile(ip+ "\\" + "ECGSig2.txt"));
                    break;

                case(2):
                    pl->update((float)File.readFile(ip+ "\\" + "ECGSig3.txt"));
                    break;

                case(3):
                    pl->update((float)File.readFile(ip+ "\\" + "SPO2Sign.txt"));
                    break;

                case(4):
                    pl->update((float)File.readFile(ip+ "\\" + "RESPSign.txt"));
                    break;

                case(5):
                    pl->update((float)File.readFile(ip + "\\" + "ROJASign.txt"));
                    break;

                case(6):
                pl->update((float)File.readFile(ip+ "\\" + "AMARILLASign.txt"));
                    break;
             }
        }
}

void Graficas::setup(){
    margen=256;
    for(int i=0;i<7;i++){
		ofxHistoryPlot *plot = new ofxHistoryPlot(NULL, "grafica" + to_string(i), margen, false);
        plot->setAutoRangeShrinksBack(true);
           switch(i){
                case(0):
                   plot->setColor(ofColor(0,128,0));
                   break;

                case(1):
                    plot->setColor(ofColor(0,128,0));
                    break;

                case(2):
                    plot->setColor(ofColor(0,128,0));
                    break;

                case(3):
                    plot->setColor(ofColor(255,255,0));
                    break;

                case(4):
                    plot->setColor(ofColor(255,0,0));
                    break;

                case(5):
                    plot->setColor(ofColor(255,255,0));
                    break;

                case(6):
                plot->setColor(ofColor(0,255,255));
                    break;
        }
        plot->setRespectBorders(true);
        plot->setLineWidth(1);
        plot->setBackgroundColor(ofColor(0,220));
        plot->setDrawGrid(true);
        plot->setGridColor(ofColor(30));
        graficas.push_back(plot);
    }

}

void Graficas::setIPs(std::string ip){
        this->ip=ip;
}


string  Graficas::getIps(){
    return ip;
}
