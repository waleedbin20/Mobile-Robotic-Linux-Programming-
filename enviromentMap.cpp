#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

#define PI 3.14159265

int build_enviormentMap(){
   // storing all the locations of the objects that needs to be placed in the map
   double x0[5] = {0.8, 0.8,1.7,2.2,2.25};
   double y0[5] = {1.5, 2.25,1.0,1.3,0.25};
   double r = 0.125, wall_Length = 2.5;
   double RD = PI/180;
  
  // writing to file 
  ofstream map;
  map.open("enviromenttt_Map.txt");

  //  generating circle pillar 1 in the map
  for (int i = 0; i<360; i = i+20){
    map<<x0[0]+r*cos(i*RD)<<' '<<y0[0]+r*sin(i*RD)<<endl;
  }

  //  generating circle pillar 2 in the map
  for (int c = 0; c<360; c = c+20){
    map<<x0[1]+r*cos(c*RD)<<' '<<y0[1]+r*sin(c*RD)<<endl;
  }

  //  generating circle pillar 3 in the map
  for (int d = 0; d<360; d = d+20){
    map<<x0[2]+r*cos(d*RD)<<' '<<y0[2]+r*sin(d*RD)<<endl;
  }
 
  //  generating circle pillar 4 in the map
  for (int e = 0; e<360; e = e+20){
    map<<x0[3]+r*cos(e*RD)<<' '<<y0[3]+r*sin(e*RD)<<endl;
  }

  // positioning the charger in the map
  for (int f = 0; f<360; f = f+20){
    map<<x0[4]+r*cos(f*RD)<<' '<<y0[4]+r*sin(f*RD)<<endl;
  }

  
  // Designing the first two walls for the map

  for(double j=0; j<wall_Length; j = j+0.01){
    map<<j<<' '<<0<<endl;
  }

  for(double j=0; j<wall_Length; j = j+0.01){
    map<<wall_Length<<' '<<j<<endl;
  }


  // Designing the second two walls for the map, this wil now complete the rectangle box

  for(double x=2.5; x>=0; x = x-0.01){
    map<<x<<' '<<2.5<<endl;
  }

  for(double x=2.5; x>=0; x = x-0.01){
    map<<0<<' '<<x<<endl;
  }

  map.close();
  return 0;
                                                                                                                   

}
// main funtion which will build the environment
int main(int argc, char**argv){

  int i;
  i = build_enviormentMap();
  return 0;

}
