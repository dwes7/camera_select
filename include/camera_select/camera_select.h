#ifndef CAMERA_SELECT_H
#define CAMERA_SELECT_H


#include <ros/ros.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <image_transport/image_transport.h>
#include "sensor_msgs/Image.h"
#include "sensor_msgs/Joy.h"

namespace camera_select
{

class Camera_select
{

public:

    Camera_select();
    ~Camera_select();
    void publish_image();

private:
    // setting up ros node handlers
    ros::NodeHandle nh_;
    ros::NodeHandle nh_private_;
    image_transport::ImageTransport it;

    // joy subscribner
    ros::Subscriber joy_sub;

    //image subsribers
    image_transport::Subscriber img_sub0;
    image_transport::Subscriber img_sub1;
    image_transport::Subscriber img_sub2;
    image_transport::Subscriber img_sub3;
    image_transport::Subscriber img_sub4;

    //image publishers
    image_transport::Publisher img_pub;

    //callback functions
    void joy_callback(const sensor_msgs::Joy::ConstPtr& msg);

    // image callbacks
    void image_callback0(const sensor_msgs::ImageConstPtr& msg);
    void image_callback1(const sensor_msgs::ImageConstPtr& msg);
    void image_callback2(const sensor_msgs::ImageConstPtr& msg);
    void image_callback3(const sensor_msgs::ImageConstPtr& msg);
    void image_callback4(const sensor_msgs::ImageConstPtr& msg);

    // image message, Gets updated according to the active camera.
    sensor_msgs::Image image;

    //camera control stuff
    int counter;

    // TODO: make this a rosparameter
    #define num_cam 4

    // used for counter
    ros::Time begin;
   


};
} // end namespace

#endif //CAMERA_SELECT_H
