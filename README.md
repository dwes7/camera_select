# camera_select

This ROS-package subscribes to at most 5 usb cameras being ran on the [usb_cam camera driver](http://wiki.ros.org/usb_cam) as well as [joy node](wiki.ros.org/joy) and allows you to cycle through the camera views with the joystick of your choice. Additional changes need to be made in order to do the following:

* Add ros parameters that allow user to define how many camera views you want

* Add ros parameters that allow user to easily specify button mapping. (eg. if user wants to see two views at the same time, the user can change a parameter and have a particular button display the two desired camera views)
