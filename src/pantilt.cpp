
#include "../include/pantilt.hpp"

#include <iostream>

#include <QDebug>

namespace dianamessenger {

using namespace Qt;


Pantilt::Pantilt(int argc, char** argv, const QString& pantiltStateName)
	: QNode(argc,argv, QString("PantiltMessager").toStdString().c_str()),
  pantiltStateName(pantiltStateName)
{
}

Pantilt::~Pantilt() {
}

// In questa funzione il nodo della nostra libreria si sottoscrive al nodo del pantilt per 
// ricevere lo stato ogni volta che questo cambia. chatterCallback e` la funzione che verra` 
// chiamata ogni volta.
void Pantilt::ros_comms_init() { 
 	ros::NodeHandle n;
	chatter_subscriber = n.subscribe(pantiltStateName.toStdString(), 1000, &Pantilt::chatterCallback, this);
}

bool setState(PantiltState state){
 	ros::NodeHandle  n;
	ros::Publisher pub = n.advertise<sensor_msgs::JointState>("/ptu/cmd",5);
	sensor_msgs::JointState::Ptr msg(new sensor_msgs::JointState);
	msg->position.push_back(state.x);
	msg->position.push_back(state.y);// = state.y;
	msg->velocity.push_back(state.speedX);
	msg->velocity.push_back(state.speedY);

	pub.publish(msg);
}

// questa funzione viene chiamata ogni volta che lo stato cambia, msg contiene le posizione.
// i parametri di msg sono listati qui http://docs.ros.org/api/sensor_msgs/html/msg/JointState.html
void Pantilt::chatterCallback(const sensor_msgs::JointState::ConstPtr &msg) {
  // per testing printa il primo valore della posizione. Ogni vettore contiene due parametri, x e y
  qDebug() <<  msg->position[0];

  //Q_EMIT newData(data);
}

// Questa funzione viene chiamata dal nostro nodo ogni ciclo. Per ora non ci serve.
void Pantilt::run() {
	ros::spin();
    //Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}  // namespace dianamessenger

