// OccupancyMap2DVector.cpp
//
// Example of a 2D vector implementation of occupancy map
// todo: get rid of hard-coded max size constants, make the map adapt to max observed
// 
// Initial revision: Donald G Dansereau, 2022


#include "OccupancyMap2DVector.h"

#include <string>
#include <utility>        // std::pair
#include <unordered_set>


//--Constructor builds an array with all "false", i.e. empty space---------------------------------------
COccupancyMap2DVector::COccupancyMap2DVector()
{
  for( int i = 0; i < 2048; ++i )
  {
      // construct a vector of ints with the given default value
      std::vector<bool> v;
      for( int j = 0; j < 2048; ++j ) 
      {
          v.push_back( false );
      }

      // push back above one-dimensional vector
      mMyMap.push_back( v );
  }
}

//--Return the name of the approach, hard-coded is fine-----------------------------------------------
std::string COccupancyMap2DVector::GetNameOfApproach() 
{ 
  return "2D vector-based approach"; 
}

//--Add an occupied location to the record of known occupied locations---------------------------------
void COccupancyMap2DVector::AddOccupiedLocation(std::pair<int,int> Location)
{
  mMyMap[Location.first][Location.second] = true;
}

//--Check if a given location has been observed as occupied locations-----------------------------------
bool COccupancyMap2DVector::CheckIsOccupied( std::pair<int,int> Location ) 
{ 
  bool Result = mMyMap[Location.first][Location.second];
  return Result;
}
    

