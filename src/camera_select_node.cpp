#include "ros/ros.h"
#include "camera_select/camera_select.h"



int main(int argc, char **argv)
{
    ros::init(argc, argv, "camera_select");
    ros::NodeHandle nh_private("~");
    int rate;
    nh_private.param<int>("rate", rate, 100);

    camera_select::Camera_select cs;
    ros::Rate loop_rate(20);
    while(ros::ok())
    {
        ros::spinOnce();
        cs.publish_image();

        loop_rate.sleep();
    }
    return 0;
}