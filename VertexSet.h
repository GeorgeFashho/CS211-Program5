/*
 *  George Fashho [6/1/2022] VertexSet.h
 *
 * Holds functions for vertexSet Class
 */

#ifndef _VERTEXSET_H
#define _VERTEXSET_H

#include <cstdlib>
#include <iostream>
#include "Vertex.h"

using namespace std;  // Debatable.  Easier for now.

class VertexSet {
	
	// Private data memebers
	
	private: 
	    Vertex ** vertices; // Dynamic array of POINTERS TO Vertex objects
	    int nVertices;
	    int nAllocated;
	    double luminosity;
	    double lowerBounds[ 3 ];
	    double upperBounds[ 3 ];
        double center[ 3 ] ;
	    
	// Public methods
	
	public: 
	    
	    // Two constructors and one destructor
		VertexSet( );
		VertexSet( int initialCapacity );
		~VertexSet( );
		
		int getNumberOfVertices( ) const;
		bool addVertex( const Vertex & vertex );
		Vertex * getVertexByID( int id ) const;
		bool intersect( const Vertex & vertex,double &distance ) const;
		void printStats( ostream & out ) const;
		void printAll( ostream & out )const;
};

#endif //_VERTEXSET_H
