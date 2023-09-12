// Lab 3 example solution 
// Comparing different containers for storing a binary occupancy map
//
// Copyright (c) Donald Dansereau, 2023

#include "OccupancyMap2DVector.h"
#include "OccupancyMapSet.h"

#include <iostream>

//-----------------------------------------------------------------------------
int main()
{

  {
    // Test a 2D vector approach
    COccupancyMap2DVector myMap;
    myMap.EvalPerformance( "ExampleObservations_Small.txt", "ExampleNotObserved_Small.txt" );
  }

  {
    // Test a set approach
    COccupancyMapSet myMap;
    myMap.EvalPerformance( "ExampleObservations_Small.txt", "ExampleNotObserved_Small.txt" );
  }

  return 0;
}

