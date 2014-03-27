
#include "../include/listener.hpp"

#include <iostream>

#include <QDebug>

namespace dianamessenger {

using namespace Qt;

Listener::Listener(int argc, char** argv, const QString& publisherName)
	: QNode(argc,argv, (publisherName + QString("Listener")).toStdString().c_str()),
  publisherName(publisherName)
{
}

Listener::~Listener() {
}

void Listener::ros_comms_init() {
  ros::NodeHandle n;
	chatter_subscriber = n.subscribe(publisherName.toStdString(), 1000, &Listener::chatterCallback, this);
}

void Listener::chatterCallback(const std_msgs::String::ConstPtr &msg) {
  QString data(msg->data.c_str()); 
  Q_EMIT newData(data);
}

void Listener::run() {
	ros::spin();
    //Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}  // namespace dianamessenger

