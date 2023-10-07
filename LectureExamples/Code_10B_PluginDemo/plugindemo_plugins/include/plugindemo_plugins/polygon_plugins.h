// polygon_plugins.h  
// Modified from http://wiki.ros.org/pluginlib/Tutorials to separate the plugins and main
// and to separate implementation out of the header file and into polygon_plugins.cpp

#ifndef PLUGINDEMO_PLUGINS_POLYGON_PLUGINS_H_
#define PLUGINDEMO_PLUGINS_POLYGON_PLUGINS_H_

#include <cmath>
#include <plugindemo_main/polygon_base.h>

namespace polygon_plugins
{

  class Triangle : public polygon_base::RegularPolygon
  {
    public:
      Triangle();
      void initialize( double side_length ); // override pure virtual
      double area(); // override pure virtual
      double getHeight(); // new powers

    private:
      double side_length_;
  };

  class Square : public polygon_base::RegularPolygon
  {
    public:
      Square();
      void initialize( double side_length ); // override pure virtual
      double area(); // override pure virtual

    private:
      double side_length_;
  };

};

#endif
