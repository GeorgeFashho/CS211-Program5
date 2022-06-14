/*
 *  George Fashho [6/1/2022] Vertex.h
 *
 * Holds functions for vertex Class
 */


#ifndef _VERTEX_H
#define _VERTEX_H

#include <cstdlib>
#include <iostream>
#include <ostream>

using namespace std;  // Debateable, but makes things easier.

class Vertex {
	
	/* Private data members */
		
	private: 
	    static int nextID;
	    int ID;
	    double coordinates[ 3 ];
	    double luminosity;
	    
	/* Public methods */
	
	public: 
	    
		// Two constructors and one destructor
		Vertex( double X, double Y, double Z, double luminosity );
		Vertex( const Vertex & vertex ); // Copy constructor
		~Vertex( );
		
		// Getters.  Note methods and variable names don't match in this case.
		int getID( ) const;    
		double getX( ) const;    
		double getY( ) const;    
		double getZ( ) const;    
		double getLuminosity( ) const;
};

// non-class function to allow cout << Vertex statements.
ostream & operator << ( ostream & out, const Vertex & vertex );

#endif //_VERTEX_H
