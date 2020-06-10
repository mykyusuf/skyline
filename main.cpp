#include <cstdlib>
#include<iostream>
#include<fstream>
#include <stdlib.h>
#include "Board.h"

using namespace std;

int main(int argc, char** argv) {

    ifstream myReadFile;
    myReadFile.open("data.txt");
    char output[2];
    int width,height,position;
    int mh,mw,maxh=0,maxw=0;
    
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {


            myReadFile >> output;
            if(output[1]!=NULL)
                width=(output[0]-48)*10+output[1]-48;
            else
                width=output[0]-48;
            myReadFile >> output;
            if(output[1]!=NULL)
                height=(output[0]-48)*10+output[1]-48;
            else
                height=output[0]-48;
            myReadFile >> output;
            if(output[1]!=NULL)
                position=(output[0]-48)*10+output[1]-48;
            else
                position=output[0]-48;
            
            mh=height;
            mw=width+position;
            
            if(mh>maxh)
                maxh=mh;
            if(mw>maxw)
                maxw=mw;
            

        }
    }
    
    myReadFile.close();
    
    Board b(maxh,maxw+1);

    b.print();
    
    
    return 0;
}

