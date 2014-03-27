
#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include "../include/qnode.hpp"
#include <std_msgs/String.h>
#include <sstream>

/**
 * // written by Vincenzo Giovanni Comito < clynamen@gmail.com > the 19-07-13
 * This class must be changed somehow:
 * Every time a new instance is created for every publisher this
 * class creates a new thread, since we may map only a publisher to a single callback.
 * With new version of ros it is possible to use a callback
 * that brings metadata about the caller, so it may be possible to track
 * the publisher and use a single callback for multiple publisher, thus a single thread.
 *
 * */

namespace dianamessenger {
QNode::QNode(int argc, char** argv, const std::string &name ) :
	init_argc(argc),
	init_argv(argv),
	node_name(name)
	{}

QNode::~QNode() {
	shutdown();
}
/**
 * This is called by the qt application to stop the ros node before the
 * qt app closes.
 */
void QNode::shutdown() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::on_init() {
	ros::init(init_argc,init_argv,node_name);
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // our node handles go out of scope, so we want to control shutdown explicitly.
	ros_comms_init();
	start();
	return true;
}

bool QNode::on_init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,node_name);
  std::cout << " master: "<< master_url<< std::endl;
  std::cout << " host: "<< host_url<< std::endl;
	if ( ! ros::master::check() ) {
    std::cout << " Unable to start! "<< host_url<< std::endl;
		return false;
	}
	ros::start(); // our node handles go out of scope, so we want to control shutdown explicitly.
	ros_comms_init();
  std::cout << "On init - QNODE"<< std::endl;
	start();
	return true;
}

}
