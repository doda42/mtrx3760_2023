// polygon_plugins.cpp
// Modified from http://wiki.ros.org/pluginlib/Tutorials to separate the plugins and main
// and to separate implementation out of the header file and into polygon_plugins.cpp

#include <pluginlib/class_list_macros.h>
#include <plugindemo_main/polygon_base.h>
#include <plugindemo_plugins/polygon_plugins.h>

//--Exports--------------------------------------------------------
PLUGINLIB_EXPORT_CLASS(polygon_plugins::Triangle, polygon_base::RegularPolygon)
PLUGINLIB_EXPORT_CLASS(polygon_plugins::Square, polygon_base::RegularPolygon)

namespace polygon_plugins
{

  //---------------------------------------------------------------
  Triangle::Triangle()
  {
  }

  void Triangle::initialize(double side_length)
  {
    side_length_ = side_length;
  }

  double Triangle::area()
  {
    return 0.5 * side_length_ * getHeight();
  }

  double Triangle::getHeight()
  {
    return sqrt((side_length_ * side_length_) - ((side_length_ / 2) * (side_length_ / 2)));
  }

  //---------------------------------------------------------------
  Square::Square()
  {
  }

  void Square::initialize(double side_length)
  {
    side_length_ = side_length;
  }

  double Square::area()
  {
    return side_length_ * side_length_;
  }

};

