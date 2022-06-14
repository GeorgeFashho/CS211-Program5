/*
 *  George Fashho [6/1/2022] Vertex.cpp
 *
 * Holds information for vertex Class
 */

#include "Vertex.h"

// Initializing the static int class variable.
int Vertex::nextID = 0;
 

/* Vertex constructor: Used to build a Vertex and incrementing ID
 * Param @X: X coord
 * Param @Y: Y coord
* Param @Z: Z coord
 * Param @luminosity: luminosity
 * */
Vertex::Vertex( double X,  double Y,  double Z,  double luminosity ) {
	
	// Sample.  "this->luminosity" refers to class variable, 
	//              "= luminosity" refers to the passed parameter
	
	this->luminosity = luminosity;
    coordinates[0] = X;
    coordinates[1] = Y;
    coordinates[2] = Z;
    ID = nextID ;
    nextID++;
}

/*  Copy constructor that copies all the data of the input vertex,
	including the ID. .*/
Vertex::Vertex( const Vertex & vertex ) {
	
	luminosity = vertex.luminosity;
    coordinates[0] = vertex.coordinates[0];
    coordinates[1] = vertex.coordinates[1];
    coordinates[2] = vertex.coordinates[2];
    ID = vertex.ID ;
}

// Destructor.

Vertex::~Vertex( ) {
	
}

// Getters return class values
int Vertex::getID( ) const {
    return ID;
}

double  Vertex::getX( ) const {
    return coordinates[0];
}

double Vertex::getY( ) const {
    return coordinates[1];
}

double Vertex::getZ( ) const {
    return coordinates[2];
}

double Vertex::getLuminosity( ) const {
    return luminosity;
}

/*Out function to output data about the vertex*/
 ostream & operator << ( ostream & out, const Vertex & vertex ) {
 	
     out << "\nVertex ID: "<<vertex.getID()<<" Coordinates: ( X: " << vertex.getX( )<< " Y: "<<vertex.getY( )<<" Z: "<<vertex.getZ( )
     <<" ) \n[ Luminosity: "<<vertex.getLuminosity( );

 	out << " ]\n";
 	
 	return out;
 	
 } // operator << ( ostream &, Vertex ) 

