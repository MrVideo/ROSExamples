#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "pub_sub/AddTwoInts.h"
#include "ros/service_server.h"

bool add(pub_sub::AddTwoInts::Request &req, pub_sub::AddTwoInts::Response &res) {
	res.sum = req.a + req.b;
	ROS_INFO("Request: a = %ld, b = %ld", req.a, req.b);
	ROS_INFO("Response: sum = %ld", res.sum);

	return true;
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "add_two_ints_server");
	ros::NodeHandle n;

	ros::ServiceServer service = n.advertiseService("add_two_ints", add);
	ROS_INFO("Ready to add two ints.");
	ros::spin();

	return 0;
}
