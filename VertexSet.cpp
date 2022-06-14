/*
 *  George Fashho [6/1/2022] VertexSet.cpp
 *
 * Holds information for vertexSet Class
 */

#include "VertexSet.h"
#include "Vertex.h"
#include <math.h>


#define X 0
#define Y 1
#define Z 2

using namespace std;

// No-argument constructor.  Set allocated to 10 by default
VertexSet::VertexSet( ) {

    nAllocated = 10;
    vertices = new Vertex*[nAllocated];
    nVertices = 0;
    luminosity = 0.0 ;
    lowerBounds[0] = 0.0 ;
    upperBounds[0] = 0.0;
    center[0] = 0.0;
} // Constructor ( )


// Constructor with an argument. 
// @param initialCapacity: nAllocated is set to initialCapacity
VertexSet::VertexSet( int initialCapacity) {
    nAllocated = initialCapacity;
    vertices = new Vertex*[nAllocated];
    nVertices = 0;
    luminosity = 0.0 ;
    lowerBounds[0] = 0.0 ;
    upperBounds[0] =0.0;
    center[0] = 0.0;
} // Constructor( int )


// Destructor frees all associated dynamic memory
VertexSet::~VertexSet( ) {

    for(int i  = 0 ; i < nVertices ;i ++){
        delete vertices[i];
    }

    delete[] vertices ;

} // Destructor


// Returns number of vertices in the array
int VertexSet::getNumberOfVertices( ) const {
    return nAllocated;
} // getNumberOfVertices


/* Adds a vertex to the set.  Allocate new memory as needed.
 Returns true if successful, false otherwise
 Calculates average luminosity as well as center of bounding box and upper/lower bounds!
*/
bool VertexSet::addVertex( const Vertex & vertex ) {

    Vertex *newVertex = new Vertex(vertex);

    if(nVertices == 0){
        lowerBounds[0] = vertex.getX();
        lowerBounds[1] = vertex.getY();
        lowerBounds[2] = vertex.getZ(); //initializing upper & lower bounds
        upperBounds[0] = vertex.getX();
        upperBounds[1] = vertex.getY();
        upperBounds[2] = vertex.getZ();

    }
    if (vertex.getX() < lowerBounds[0]) {
        lowerBounds[0] = vertex.getX();
    }  if (vertex.getY() < lowerBounds[1]) {
        lowerBounds[1] = vertex.getY();
    }  if (vertex.getZ() < lowerBounds[2]) {
        lowerBounds[2] = vertex.getZ();         //finding upper & lower bounds
    }  if (vertex.getX() > upperBounds[0]) {
        upperBounds[0] = vertex.getX();
    }  if (vertex.getY() > upperBounds[1]) {
        upperBounds[1] = vertex.getY();
    }  if (vertex.getZ() > upperBounds[2]) {
        upperBounds[2] = vertex.getZ();
    }

    if(nAllocated == nVertices)
    {
        Vertex ** temp = vertices;
        nAllocated = 2*nAllocated;
        vertices = new Vertex*[nAllocated];
        if(temp == NULL)
        {
            return false;                       //allocating more space to array if original is full
        }
        for(int i=0; i<nVertices; ++i)
        {
            vertices[i] = temp[i];  //copying data  to new array
        }
        delete[] temp;  //freeing memory
        temp = NULL;
    }
    /*Calculating average luminosity*/
    luminosity = (luminosity * (double)nVertices + newVertex->getLuminosity())/((double)nVertices+1.0);

    vertices[nVertices] = newVertex;
    nVertices++;

    /*Finding center of bounding box*/
    for(int i = 0 ; i<3 ; i++){
        center[i] = (upperBounds[i] + lowerBounds[i]) / 2;
    }

    return true;
}


// Return true if there is an intersection, false otherwise
//Calculating distance between vertex and center of bounding box!
bool VertexSet::intersect( const Vertex & vertex , double & distance) const {
    if (vertex.getX() >= lowerBounds[X] && vertex.getX() <= upperBounds[X]) {
        if (vertex.getY() >= lowerBounds[Y] && vertex.getY() <= upperBounds[Y]) {
            if (vertex.getZ() >= lowerBounds[Z] && vertex.getZ() <= upperBounds[Z]) {

                distance = sqrt( ((vertex.getX() - center[X])*(vertex.getX() - center[X])) +((vertex.getY() - center[Y])*(vertex.getY() - center[Y]))
                        +((vertex.getZ() - center[Z])*(vertex.getZ() - center[Z])));

                return true;
            }
        }
    }
	return false;  // TODO:  Replace this line with code that checks.
} // intersect


// The following function "prints" to outStream all the information about
// a VertexSet, except the actual vertices themselves.
void VertexSet::printStats( ostream & outStream ) const {

	outStream << "This vertex set has " << nVertices << " stored out of " << nAllocated << " available.\n";
    outStream <<" Luminosity: "<<(double)(luminosity)<<"\n Lower Bounds: ( "<<lowerBounds[0]<<", "<<lowerBounds[1]<<", "<<lowerBounds[2]
              <<" ) \n Upper Bounds: ( "<<upperBounds[0]<<", "<<upperBounds[1]<<", "<< upperBounds[2]<<" )\n"
              <<"The center  of the bounding box is: ( "<<center[X]<<", "<< center[Y]<<", "<<center[Z]<<") \n";
} // printStats


// The following function "prints" to outStream all the information about
// a VertexSet, including the actual vertices themselves.
void VertexSet::printAll( ostream & outStream ) const {

    printStats(outStream);
    for(int i = 0 ; i < nVertices ;i ++){
        outStream<< *vertices[i];

    }
} // printAll


// Return the address of the vertex with the given ID, or NULL otherwise
Vertex * VertexSet::getVertexByID( int id ) const {

    for(int i=0; i<nVertices; ++i)
    {
        if(id == vertices[i]->getID())
        {
            return vertices[i];
        }
    }
    return NULL;
} // getVertexByID



