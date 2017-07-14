
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <image_transport/image_transport.h>
#include <sensor_msgs/Joy.h>
#include "camera_select/camera_select.h"


namespace camera_select
{

Camera_select::Camera_select():
    //set image_transport node
    it(image_transport::ImageTransport(nh_))

{
        
    // Joy_subscriber
    joy_sub = nh_.subscribe<sensor_msgs::Joy>("/joy", 1, &Camera_select::joy_callback, this);

    //initialize subscribers
    img_sub0 = it.subscribe("/usb_cam0/image_raw",10, &Camera_select::image_callback0, this);

    img_sub1 = it.subscribe("/usb_cam1/image_raw",10, &Camera_select::image_callback1, this);

    img_sub2 = it.subscribe("/usb_cam2/image_raw",10, &Camera_select::image_callback2, this);

    img_sub3 = it.subscribe("/usb_cam3/image_raw",10, &Camera_select::image_callback3, this);

    img_sub4 = it.subscribe("/usb_cam4/image_raw",10, &Camera_select::image_callback4, this);

    //initialize publishers (do not yet publish)
    img_pub = it.advertise("base_cam0",1);

    // image message
    image;

    // camera counter. Increments with a button press.
    counter = 0;

    //initialize timer
    begin = ros::Time::now();
}

Camera_select::~Camera_select()
{

}

// TODO instead of sensor Msgs, we wand RoverState msgs.
void Camera_select::joy_callback(const sensor_msgs::Joy::ConstPtr& msg){

//use ROS timer for debouncing
ros::Time tempTime = ros::Time::now();
bool camtoggle = msg->buttons[0];
//if it's been over 1/4 second since you switched, switch
if((tempTime - begin).toSec() > 0.25 && camtoggle){
    counter ++;
    if(counter == num_cam)
        counter = 0;
    begin = tempTime;
}

ROS_INFO_STREAM("Camera " << counter < "is selected");
return;
}

//  image publisher. Gets called in main.
void Camera_select::publish_image(){
    img_pub.publish(image);
}

// The next 5 functions are the image callbacks. 
void Camera_select::image_callback0(const sensor_msgs::ImageConstPtr& msg){
    

    if (counter == 0){
        image = *msg;
        ROS_INFO_STREAM("Camera 0 is publishing. counter number is: " << counter);
    }
}

void Camera_select::image_callback1(const sensor_msgs::ImageConstPtr& msg){

    if (counter == 1){
        image = *msg;
        ROS_INFO_STREAM("Camera 1 is publishing. counter number is: " << counter);
    }
}

void Camera_select::image_callback2(const sensor_msgs::ImageConstPtr& msg){

    if (counter == 2){
        image = *msg;
        ROS_INFO_STREAM("Camera 2 is publishing. counter number is: " << counter);
    }
}

void Camera_select::image_callback3(const sensor_msgs::ImageConstPtr& msg){

    if(counter == 3){
        image = *msg;
        ROS_INFO_STREAM("Camera 3 is publishing. counter number is: " << counter);
    }
}

void Camera_select::image_callback4(const sensor_msgs::ImageConstPtr& msg){
   
    if (counter == 4){
        image = *msg;
        ROS_INFO_STREAM("Camera 4 is publishing. counter number is: " << counter);
    }
}
}

