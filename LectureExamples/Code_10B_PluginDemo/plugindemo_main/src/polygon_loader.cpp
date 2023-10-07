// polygon_loader.cpp
// Modified from http://wiki.ros.org/pluginlib/Tutorials to separate the plugins and main

#include <pluginlib/class_loader.h>
#include <plugindemo_main/polygon_base.h>

int main(int argc, char** argv)
{
  pluginlib::ClassLoader<polygon_base::RegularPolygon> poly_loader("plugindemo_plugins", "polygon_base::RegularPolygon");

  try
  {
    boost::shared_ptr<polygon_base::RegularPolygon> triangle = poly_loader.createInstance("polygon_plugins::Triangle");
    boost::shared_ptr<polygon_base::RegularPolygon> square = poly_loader.createInstance("polygon_plugins::Square");
    
    triangle->initialize(10.0);
    square->initialize(10.0);

    ROS_INFO("Triangle area: %.2f", triangle->area());
    ROS_INFO("Square area: %.2f", square->area());
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load for some reason. Error: %s", ex.what());
  }

  return 0;
}
