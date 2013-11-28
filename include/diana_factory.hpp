#ifndef listener_DIANAFACTORY_H
#define listener_DIANAFACTORY_H

#include <QString>
#include "diana_listener.hpp"
#include "diana_publisher.hpp"


namespace dianamessager {

/**
 *
 * Factory for creating listeners. Since we have to address the problem of the
 * multiple threads in the future, we use a factory for creating each listener.
 * In the future, many listener will live in the same thread.
 *
 * I nodi devono essere creati con parametri uguali quali l'indirizzo del master e dell'host,
 * per evitare errori la creazione di listener e publisher e` affidata a questa classe.
 * Quando si vuole creare un publisher o listener,  si chiama una funzione di questa classe.
 * */
class DianaFactory  {

public:
  /**
   * Crea una factory con l'indirizzo del master e dell'host.
   */
  DianaFactory(const QString& master, const QString& host);
  /**
   * Crea un listener che si sottoscrivere al nodo con nome 'publisherName'
   */
  DianaListener* createListener(const QString& publisherName);
  /**
   * Crea un publisher.
   */
  DianaPublisher* createPublisher(const QString& listenerName);



private:
  // Indirizzi del master e dell'host:
  // master_url e` l'indirizzo del ros e.g.  http://rover.teamdiana.org:11311
  // host_url e` l'host del ros e.g. http://rover.teamdiana.org
  QString master;
  QString host;

};

}  // namespace dianamessager

#endif
