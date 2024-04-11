#include "ros/init.h"
#include "ros/ros.h"
#include "dynamic_reconfigure/server.h"
#include "parameters_test/parametersConfig.h"
#include <cstdint>

void callback(parameters_test::parametersConfig &config, uint32_t level) {
	ROS_INFO("Reconfigure request: %d %f %s %s %d", config.int_param, config.double_param, config.str_param.c_str(), config.bool_param ? "True" : "False", config.size);
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "param_second");
	dynamic_reconfigure::Server<parameters_test::parametersConfig> server;
	dynamic_reconfigure::Server<parameters_test::parametersConfig>::CallbackType f;

	f = boost::bind(&callback, _1, _2);

	server.setCallback(f);

	ROS_INFO("Spinning node");

	ros::spin();

	return 0;
}
