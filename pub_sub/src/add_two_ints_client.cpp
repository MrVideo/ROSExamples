#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "pub_sub/AddTwoInts.h"
#include "ros/service_client.h"
#include <cstdlib>

int main(int argc, char **argv) {
	ros::init(argc, argv, "add_two_ints_client");
	
	if (argc != 3) {
		ROS_INFO("Usage: add_two_ints_client first_int second_int");
		return 1;
	}

	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<pub_sub::AddTwoInts>("add_two_ints");
	pub_sub::AddTwoInts srv;
	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);

	if (client.call(srv)) {
		ROS_INFO("Sum: %ld", srv.response.sum);
	} else {
		ROS_ERROR("Failed to call service add_two_ints");
		return 1;
	}

	return 0;
}
