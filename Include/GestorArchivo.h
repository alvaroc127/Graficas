#ifndef GESTORARCHIVO_H
#define GESTORARCHIVO_H

#include <fstream>
#include <vector>
#include <string>
#include <sstream>

static const std::string direcc = "C:\\ArchivosSignal\\";
static const std::string direcc1 = "C:\\ArchivosSignal\\IP.txt";


class GestorArchivo{

     std::fstream inFile;
     int sizeFil;
     int pos=0;


public:
    GestorArchivo();
   virtual ~GestorArchivo();
    std::vector<std::string> loadIps();    
    int getSizeFil();
    int sizeFile();
    std::string finalIp(int);
    void setSizeFil(int);
    uint8_t readFile(std::string);
	int posi();



};

#endif // GESTORARCHIVO_H
