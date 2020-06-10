/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: MacbookPro
 *
 * Created on 13 Haziran 2018 Çarşamba, 17:35
 */

#ifndef BOARD_H
#define BOARD_H
#include<iostream>
#include<fstream>
#include <stdlib.h>

using namespace std;

class Board {
public:
    Board(int h,int w){
        
        bheight=h;
        bwidth=w;
        b = new int*[h];
        for (int i = 0; i < h; ++i){
            b[i] = new int[w];
        }
        for(int i=0;i<bheight;i++){
            
            for(int j=0;j<bwidth;j++){
                b[i][j]=0;
            }
        }
        readData();
        skyline();
        
    }
    virtual ~Board(){
        
        for (int i = 0; i < bheight; ++i)
            delete [] b[i];
        delete [] b;
    }
    
    void print(){
        for(int i=0;i<bheight;i++){
            
            for(int j=0;j<bwidth;j++){
                if(b[i][j]!=0)
                    cout<<b[i][j]-48;
                else
                    cout<<b[i][j];
            }
            cout<<endl;
        }
        
    }
    
    void skyline(){
        
        int deger=-1,var=0,var1=0,var2=0,k,m,x=bheight-1,y=0,z,yon=2,say=0;
        
        for(int j=1;j<bwidth;j++){
            
            if(b[bheight-1][j]!=0){
                for(int i=bheight-2;i>=0&&b[i][j]==0;i--){
                    
                    for(k=j;k<bwidth;k++){
                        if(b[i][k]!=0){
                            deger=b[i][k];
                            for(m=j;m>=0;m--){
                                if(deger==b[i][m]){
                                        var=i;
                                }
                            }
                        }
                    }
                         
                    

                }
                deger=-1;
                    if(var!=0){
                        b[var][j]=b[bheight-1][j];
                        b[bheight-1][j]=0;
                        var=0;
                    }
                
                
            }
            
        }
        
        while(say<24 && y!=bwidth-1){
            say++;
            
            for(z=x-1;z>=0;z--){              
                if(b[z][y]!=0){
                    var=100;
                }                
            }
            
            for(z=x+1;z<bheight-1;z++){              
                if(b[z][y]!=0){
                    var1=200;
                }                
            }
            
            for(z=0;z<bwidth;z++){              
                if(b[x][z]!=0){
                    var2=300;
                }                
            }
            if(var==100 && yon!=0){
               for(x=x-1;x>=0&&b[x][y]==0;x--){              
                   b[x][y]='1';

               }
               yon=1;
               var=0;
            }

            
            else if(var1==200 && yon!=1){
                for(x=x+1;x<bheight-1&&b[x][y]==0;x++){              
                   b[x][y]='1';

                }
                
                yon=0;
                var1=0;
            }


            
            else if(var2==300){
               for(y=y+1;y<bwidth&&b[x][y]==0;y++){              
                   b[x][y]='1';

               }
               yon=2;
               var2=0;
            }
    
            else{}
       
        }

    }
    
    void readData(){
        
        ifstream myReadFile;
        myReadFile.open("data.txt");
        char output[2];
        int width,height,position;
        int i=0;
        
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
            
            b[bheight-1][position]='1';
            b[bheight-height][position]='1';
            b[bheight-1][position+width]='1';
            b[bheight-height][position+width]='1';
            i++;

        }
    }
    
    myReadFile.close();
        
        
    }
private:

    int** b;
    int bheight,bwidth;
};

#endif /* BOARD_H */

