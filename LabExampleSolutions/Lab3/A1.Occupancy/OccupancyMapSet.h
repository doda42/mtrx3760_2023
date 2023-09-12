// OccupancyMapSet.h
//
// Example of a set implementation of occupancy map
// 
// Initial revision: Donald G Dansereau, 2023

#ifndef _OCCUPANCYMAPSET_H
#define _OCCUPANCYMAPSET_H

#include "OccupancyMapBase.h"

#include <string>
#include <utility>        // std::pair
#include <set>

//----------------------------------------------------------------------------------------------------------
// Derived class for an occupancy map.
// This implementation uses a set to store observations.
// See the base class for more information.
class COccupancyMapSet: public COccupancyMapBase
{
  public:
   
    // Return the name of the approach to implementing the translator as a string, e.g. CTranslatorSetTable
    virtual std::string GetNameOfApproach();

    // Add a location observed to be occupied to the map
    virtual void AddOccupiedLocation(std::pair<int,int> Location);
    
    // Check if a location is occupied
    bool CheckIsOccupied( std::pair<int,int> Location );


  private:

    // The set
    std::set<std::pair<int,int>> mMyMap;
};



#endif // _OCCUPANCYMAPSET_H
