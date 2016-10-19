#include "../Include/GestorArchivo.h"
#include <iostream>


GestorArchivo::GestorArchivo(){}

GestorArchivo::~GestorArchivo(){}



std::vector<std::string> GestorArchivo::loadIps(){
    std::vector<std::string> Ips;
    std::string ip;
	this->sizeFil = sizeFile();
    this->inFile.open(direcc1, std::ifstream::in);
    if(!inFile.is_open()){
		std::cout << "no abrio 1" << std::endl;
    }else{
        while(!inFile.eof()){
             inFile >> ip;
			 if (ip.size() > 0 && ip != " ") {
				 Ips.push_back(ip);
				 ip.clear();
			 }
        }

    }
    inFile.close();
    return Ips;
}



int GestorArchivo::sizeFile(){
    int tam=0;
    this->inFile.open(direcc1,std::ifstream::in);
    if(!inFile.is_open()){
        std::cout<<"no abrio 2"<<std::endl;
    }else{
        tam = int(inFile.tellg());
		inFile.seekg(0, std::ios::end);
		tam = (int(inFile.tellg()) - tam);
    }
    inFile.close();
    return tam;
}


int GestorArchivo::getSizeFil(){
       return this->sizeFil;
}


std::string GestorArchivo::finalIp(int tam){
    std::string ip;
    inFile.open(direcc1);
        if(!inFile.is_open()){
            std::cout<<"no abrio "<<std::endl;
        }else{
			inFile.seekg(tam, std::ios::beg);
            inFile >> ip;
        }
        inFile.close();
    return ip;
}

void  GestorArchivo::setSizeFil(int tam){
    this->sizeFil=tam;
}



uint8_t GestorArchivo::readFile(std::string ip){
    uint8_t let;
    char car;
    inFile.open(direcc+ip,std::ifstream::in |std::ofstream::out);
    if(!inFile.is_open()){
        std::cout<<"no se pudo abrir"<<direcc+ip<<std::endl;
    }else{
        inFile.seekg(pos);
        car=inFile.get();
        pos++;
        if(car!='\n'&&((uint8_t)car>20)){
        let=(uint8_t)car;
        }else{
            inFile.seekg(pos);
            car=inFile.get();
            pos++;
            if((uint8_t)car>20){
            let=(uint8_t)car;
            }else{
                inFile.seekg(pos);
                car=inFile.get();
                let=(uint8_t)car;
            }
        }

    }
    inFile.close();
    return let;
}





