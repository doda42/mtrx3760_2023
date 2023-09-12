// OccupancyMapSet.cpp
//
// Example of a set implementation of occupancy map
// 
// Initial revision: Donald G Dansereau, 2023


#include "OccupancyMapSet.h"

#include <string>
#include <utility>        // std::pair
#include <set>


//--Return the name of the approach, hard-coded is fine-----------------------------------------------
std::string COccupancyMapSet::GetNameOfApproach() 
{ 
  return "Set-based approach"; 
}

//--Add an occupied location to the record of known occupied locations---------------------------------
void COccupancyMapSet::AddOccupiedLocation(std::pair<int,int> Location)
{
  mMyMap.insert( Location );
}

//--Check if a given location has been observed as occupied locations-----------------------------------
bool COccupancyMapSet::CheckIsOccupied( std::pair<int,int> Location ) 
{ 
  bool Result = false;
  if( mMyMap.find( Location ) != mMyMap.end() )
    Result = true;
  return Result;
}
    

