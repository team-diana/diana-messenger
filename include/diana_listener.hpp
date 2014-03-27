#ifndef DIANAPUBLISHER_H
#define DIANAPUBLISHER_H

#include <QString>
#include <QObject>

/**
 * Diana listener public class.
 * */

namespace dianamessenger {

class Listener;

/**
 * Classe che gestisce un nodo listener.
 *
 * istanze di questa classe sono create da DianaFactory.
 */
class DianaListener : public QObject {
Q_OBJECT
  friend class DianaFactory;
public:

  QString getPublisherName() { return publisherName; };
  ~DianaListener();


private:
  DianaListener(QObject* parent, const QString& publisherName);
  // Inizializza il nodo con i due indirizzi master e host.
  void init(const QString& master, const QString& host);

  // Questo segnale viene emesso ogni volta che un nuovo messaggio viene ricevuto.
Q_SIGNALS:
  void newMessage(const QString& data);

private:
  QString publisherName;
  // Instanza del nodo listener.
  Listener* listener;

};

}  // namespace dianamessenger

#endif
