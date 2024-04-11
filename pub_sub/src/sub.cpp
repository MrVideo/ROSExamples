#include "ros/ros.h"
#include "std_msgs/String.h"
#include "pub_sub/Num.h"

void pubCallback(const pub_sub::Num::ConstPtr& msg) {
	ROS_INFO("I heard %ld", msg->num);
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "sub");

	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("/publisher", 1000, pubCallback);

	ros::spin();

	return 0;
}
