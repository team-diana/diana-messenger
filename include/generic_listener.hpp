// #ifndef listener_GENERIC_LISTENER_H
// #define listener_GENERIC_LISTENER_H
//
// #include "./qnode.hpp"
// #include <ros/ros.h>
// #include <string>
// #include <std_msgs/String.h>
// #include <QObject>
// 
// /**
//  * Diana listener implementation
//  */
//
// namespace dianamessager {
//
// template <class T>  class GenericListener {
//
// public:
// 	GenericListener(int argc, char** argv, const QString& listener)     : QNode(argc,argv, (publisherName + QString("Listener")).toStdString().c_str()),
//   publisherName(publisherName)
//
// 	virtual ~GenericListener();
// 	void run();
// 	void ros_comms_init();
//
// private:
// 	void chatterCallback(const typename T::ConstPtr &msg);
// 	ros::Subscriber chatter_subscriber;
// 	QNode qnode;
//
//   //void newData(const QString& data);
//
// private:
//   QString publisherName;
//
// };
//
// }  // namespace dianamessager
//
// GenericListener::GenericListener(int argc, char** argv, const QString& publisherName)
//
// {
// }
//
// GenericListener::~GenericListener() {
// }
//
// void GenericListener::ros_comms_init() {
//   ros::NodeHandle n;
//     chatter_subscriber = n.subscribe(publisherName.toStdString(), 1000, &Listener::chatterCallback, this);
// }
//
// void GenericListener::chatterCallback(const T::ConstPtr &msg) {
//  // override in subclasses
// }
//
// void GenericListener::run() {
//     qnode.spin();
// }
//
// #endif
