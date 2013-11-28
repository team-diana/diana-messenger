#ifndef listener_PANTILT_H
#define listener_PANTILT_H

#include "./qnode.hpp"
#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
#include <sensor_msgs/JointState.h>
#include <QObject>

/**
 * Diana listener implementation
 */

namespace dianamessager {

/**
 * Struct che serve per scambiare con la gui i parametri del pantilt.
 * la gui manda e riceve i parametri tramite questa struct.
 */
struct PantiltState {
  float x, y;
  float speedX,  speedY;
};

/* Vedi la classe QNode in questa libreria */
class Pantilt : public QNode {
Q_OBJECT

public:
  /**
   * argc, argv presi dal main
   * pantiltStateName e` il nodo del pantilt /ptu/state (vedi main in /test)
  */
	Pantilt(int argc, char** argv, const QString& pantiltStateName);

	virtual ~Pantilt();
	void run();
	void ros_comms_init();

  // TODO: Funzione che restituisce l'ultimo stato del pantilt disponibile. Da implementare
	//  PantiltState getState();

  // TODO: funzione che setta lo stato, da implementare:
  // questa funzione converte lo state passato come parametro in un 
  // sensor_msgs::JointState::ConstPtr  da inviare al pantilt al topic /ptu/cmd
  // Per vedere come inviare oggetti ad un nodo vedere qui:
  //
  // http://wiki.ros.org/roscpp/Overview/Publishers%20and%20Subscribers#Publishing_to_a_Topic
  //
  // il tipo di messaggio da inviare e` quindi un sensor_msgs::JointState

  	bool setState(PantiltState state);

private:
  // Funzione di callback che viene chiamata ogni volta che il pantilt
  // cambia posizione. Lo stato del pantilt e` contenuto in msg
	void chatterCallback(const sensor_msgs::JointState::ConstPtr &msg);
  // oggetto di una classe che permette di ricevere i messaggi di
  // un altro nodo
	ros::Subscriber chatter_subscriber;
  // Ultimo stato del pantilt disponibile
	PantiltState pantiltState;

Q_SIGNALS:
  // segnale da emettere quando il pantilt cambia stato (da fare in futuro)
  void newState(const PantiltState& state);

private:
  // stringa che contiene il nome del nodo del pantilt
  QString pantiltStateName;

};

}  // namespace dianamessager

#endif
