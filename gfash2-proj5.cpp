
/*  gfash2-proj5.c

	Written [6/1/2022] by [George Fashho] for CS 211, Summer 2022

	The program maintains a collection of points in 3D
    space, and certain properties of the collection as a whole. Then you will use this information to test
    whether a given  point intersects with the collection of points or not.

*/

#include <cstdlib>
#include <iostream>
#include <string.h>
#include "Vertex.h"
#include "VertexSet.h"

#define X 0
#define Y 1
#define Z 2

int debugMode = false;
 
 using namespace std;	// Debatable, but easier for now.
  
 int main( int argc, char ** argv ) {

     for (int i = 0; i < argc; i++) { //debugging information!!

         /* access the ith ARGument Value */
         if (strcmp(argv[i], "-d") == 0) {
             printf("Debug mode on!\n");
             debugMode = true;  //debug mode on since -d called
         }
     }

     VertexSet vertices; //declaring VertexSet instance

     double userInput[4];
     cout<<"Please enter a list of coordinates and luminosities of vertices ending with a negative luminosity: \n";
     cin>>userInput[X]>>userInput[Y]>>userInput[Z]>>userInput[3]; //prompting user to enter vertices

     while(userInput[3]>=0.0){  //keep accepting user input till negative luminosity reached

         Vertex temp (userInput[X],userInput[Y],userInput[Z],userInput[3]); //creating temp Vertex

         vertices.addVertex(temp);  //adding user Vertex into the array of vertices

         cin>>userInput[X]>>userInput[Y]>>userInput[Z]>>userInput[3];
     }

     if(debugMode) {
         cout<<"[ DEBUG START ]\n";
         vertices.printAll(cout);   //printing all information for debugging purposes
         cout<<"[ DEBUG END ]\n";
     }

     vertices.printStats(cout); //printing information for array of vertices

     cout<<"\nPlease enter another list of coordinates and luminosities of vertices to find an intersection: \n";

     cin>>userInput[X]>>userInput[Y]>>userInput[Z]>>userInput[3];   //prompting user to enter a vertex

     while(userInput[3]>=0.0){  //keep accepting input till -ve luminosity reached

         Vertex temp (userInput[X],userInput[Y],userInput[Z],userInput[3]);
         cout<<"Coordinates inputted [X, Y, Z]: "<<"[ "<<userInput[X]<<", "<<userInput[Y]<<", "<<userInput[Z]<<" ]\n";

         if(debugMode){
             cout<<"[ DEBUG ]: Comparing lower and upper bounds to userInput: \n";
             vertices.printStats(cout);
             for(int i = 0 ; i < 3 ; i++){
                 cout<<i<<": "<<userInput[i]<<"\n";
             }
         }

         double distance = 0.0; //initializing variable to hold distance between center of bounding box and vertex point
         if(vertices.intersect(temp,distance)){ //checking for intersection

             cout<<"*The coordinates inputted intersect with the bounding box*\n"
             <<"The distance between the center of the box and this vertex is: "
             <<distance<<"\n";
         }
         else{
             cout<<"*The coordinates inputted !do not! intersect with the bounding box*\n";
         }
         cin>>userInput[X]>>userInput[Y]>>userInput[Z]>>userInput[3];
     }

	return 0;
  	
 } //end main()
 
 
