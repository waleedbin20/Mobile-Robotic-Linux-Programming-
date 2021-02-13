#include <math.h>
#include <iostream>
#include <fstream>

#define PI 3.14159265 

/* Declaring Width and time interval for one complete cycle*/
int wheel_base = 30;
int delta_t = 1; 
const int SIZE = 200;

/* Declaring the initial position of the robot*/
double rob_x[SIZE]={30}, rob_y[SIZE]={30}, rob_angle[SIZE]={PI/4};

/* two testing velocities of the robot*/
double vl = 10.0, vr = 8.0;
double vlt = 5.0, vrt= 7.0;

/* Function that performs the odometry calculation*/
int robot_Kinematic(double left_velocity, double right_velocity){  
 
  for(int k = 0; k<SIZE; k++){
        /* Calculating the angle for the robot*/     
	rob_angle[k+1] = rob_angle[k]+ ((right_velocity - left_velocity)/wheel_base) * delta_t; 
 
        /* Calculating the x axis position for the robot*/     
	rob_x[k+1] = rob_x[k] + ((right_velocity + left_velocity)/2) * cos(rob_angle[k]) * delta_t;

        /* Calculating the y axis position for the robot*/     
	rob_y[k+1] = rob_y[k] +  ((right_velocity + left_velocity)/2) * sin(rob_angle[k]) * delta_t;
  }
  return 0;
}


FILE *fptr;
 
int main(int argc,char**argv){

  int c; 
  // creating a file and writing to it
  fptr = fopen("odometry_resul-test2", "w");
 
  // calling the function which will do the calculation
  robot_Kinematic(vlt,vrt);

  fprintf(fptr, "%d, %d \n", 30,30);
 
  // looping through the array size which will print the coordinates of the robot pose
  for(c = 1; c <SIZE; c++){

   fprintf (fptr, "%f, %f \n", rob_x[c],rob_y[c]);
  }

  fclose(fptr);
  return 0;

}
