#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "pub_sub/Num.h"

int main(int argc, char **argv) {
	// Initialise ROS
	ros::init(argc, argv, "pub");

	// Create a new node handler
	ros::NodeHandle n;

	// Create new publisher object
	ros::Publisher chatter_pub = n.advertise<pub_sub::Num>("publisher", 1000);

	// Fix loop frequency at 10 Hz
	ros::Rate loop_rate(10);

	// Main ROS loop
	while (ros::ok()) {
		// Create a new message (String version)
		/* std_msgs::String msg; */
		/* std::stringstream ss; */
		/* ss << "Hello, world!\n"; */
		/* msg.data = ss.str(); */

		// Create a new message (custom message type version)
		static int i = 0;
		i = (i + 1) % 1000;
		pub_sub::Num msg;
		msg.num = i;

		// Publish the message on the chatter_pub topic
		chatter_pub.publish(msg);

		// Sleep according to the correct frequency (as set before)
		loop_rate.sleep();
	}

	return 0;
}
