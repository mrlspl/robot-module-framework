# Robot Module Framework
A framework for developing modules for robots inspired by [Robot Operating System (ROS)](http://www.ros.org/).
Unlike ROS, this framework is for building up a single component that can be used either in a bigger system like ROS or somewhere else.

Most of the concepts of this framework is common with ros, despite that it is nestable and in order to prevent catastropy of too much nesting, a project dependency manager is incorporated to keep modules small enough. For nesting, it is recommended to define separate projects and depend them to each other. In this way dependent project can use the smaller module in its code without actually nesting source directory. 

for using Cmake and Update Dxygen go to bulid dir and run "cmake .." command and then run "make doc" to generate html and lateX files .
