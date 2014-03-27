#ifndef NODE_HPP_
#define NODE_HPP_

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>

namespace dianamessenger {

// Un qnode e` di fatto un nodo del ros
// Noi usiamo pero` soltanto i nodi per prendere e inviare dati
class QNode : public QThread {
Q_OBJECT

public:
  // name: nome di questo nodo ros.
	QNode(int argc, char** argv, const std::string &name);
	virtual ~QNode();

	bool on_init();
  // Funzione da chiamare per avviare il nodo
  // master_url e` l'indirizzo del ros e.g.  http://rover.teamdiana.org:11311
  // host_url e` l'host del ros e.g. http://rover.teamdiana.org 
	bool on_init(const std::string &master_url, const std::string &host_url);
  // chiude il nodo
	void shutdown();
  // Funzione virtuale pura (ovvero una funzione che deve essere implementata per forza, vedi wikipedia)
	virtual void run() = 0;

	QStringListModel* loggingModel() { return &logging; }
	const std::string& nodeName() { return node_name; }

Q_SIGNALS:
	void loggingUpdated();
	void rosShutdown();

protected:
	virtual void ros_comms_init() = 0;
	int init_argc;
	char** init_argv;
    QStringListModel logging;
    const std::string node_name;
};

}

#endif /* NODE_HPP_ */

