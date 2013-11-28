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

/**
 * Nodo listener
 */
class Listener : public QNode {
Q_OBJECT

public:
	Listener(int argc, char** argv, const QString& publisherName);

	virtual ~Listener();
	void run();
	void ros_comms_init();

private:
	void chatterCallback(const std_msgs::String::ConstPtr &msg);
	ros::Subscriber chatter_subscriber;

Q_SIGNALS:
  void newData(const QString& data);

private:
  QString publisherName;

};

}  // namespace dianamessager

#endif
