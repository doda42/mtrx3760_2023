// OccupancyMap2DVector.h
//
// Example of a 2D vector implementation of occupancy map
// 
// Initial revision: Donald G Dansereau, 2022

#ifndef _OCCUPANCYMAP2DVECTOR_H
#define _OCCUPANCYMAP2DVECTOR_H

#include "OccupancyMapBase.h"

#include <string>
#include <utility>        // std::pair
#include <vector>

//----------------------------------------------------------------------------------------------------------
// Derived class for an occupancy map.
// This implementation uses a 2D vector (vector of vectors) to store observations.
// See the base class for more information.
class COccupancyMap2DVector: public COccupancyMapBase
{
  public:
   
    // initialise the map to all empty
    COccupancyMap2DVector();
    
    // Return the name of the approach
    virtual std::string GetNameOfApproach();

    // Add a location observed to be occupied to the map
    virtual void AddOccupiedLocation(std::pair<int,int> Location);
    
    // Check if a location is occupied
    virtual bool CheckIsOccupied( std::pair<int,int> Location );


  private:

    // The 2D vector: a vector of vectors
    std::vector<std::vector<bool>> mMyMap;
};



#endif // _OCCUPANCYMAP2DVECTOR_H
