#ifndef listener_LISTENER_H
#define listener_LISTENER_H

#include "./qnode.hpp"
#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
#include <QObject>

/**
 * Diana listener implementation
 */

namespace dianamessager {

class Publisher : public QNode {
Q_OBJECT

public:
	Publisher(int argc, char** argv, const QString& receiverName);

	virtual ~Publisher();
	void run();
	void ros_comms_init();

private:
	//void chatterCallback(const std_msgs::String::ConstPtr &msg);
	ros::Publisher ros_publisher;

public Q_SLOTS:
  void publishData(const QString& data);

private:
  QString publisherName;

};

}  // namespace dianamessager

#endif 
