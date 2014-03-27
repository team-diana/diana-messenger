
#include "../include/publisher.hpp"

#include <iostream>

#include <QDebug>

namespace dianamessenger {

using namespace Qt;

Publisher::Publisher(int argc, char** argv, const QString& publisherName)
	: QNode(argc,argv, (publisherName + QString("Publisher")).toStdString().c_str()),
  publisherName(publisherName)
{
}

Publisher::~Publisher() {
}

void Publisher::ros_comms_init() {
  ros::NodeHandle n;
  ros_publisher = n.advertise<std_msgs::String>(publisherName.toStdString(), 1000);
}

void Publisher::publishData(const QString& data) {
  ros::Rate loop_rate(1);
  std_msgs::String msg;
  std::stringstream ss;
  ss << data.toStdString();
  ros_publisher.publish(msg);
  ros::spinOnce();
  //loop_rate.sleep();
}

void Publisher::run() {
	ros::spin();
}

}  // namespace dianamessenger

