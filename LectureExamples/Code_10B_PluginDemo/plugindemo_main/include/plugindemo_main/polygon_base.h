// polygon_base.h  
// Modified from http://wiki.ros.org/pluginlib/Tutorials to separate the plugins and main

#ifndef PLUGINDEMO_MAIN_POLYGON_BASE_H_
#define PLUGINDEMO_MAIN_POLYGON_BASE_H_

namespace polygon_base
{

  class RegularPolygon
  {
    public:
      virtual void initialize( double side_length ) = 0; // pure virtual
      virtual double area() = 0; // pure virtual
      virtual ~RegularPolygon(){}

    protected:
      RegularPolygon(){}
  };
  
};

#endif
