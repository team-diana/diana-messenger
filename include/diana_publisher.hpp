#ifndef listener_DIANALISTENER_H
#define listener_DIANALISTENER_H

#include <QString>
#include <QObject>

/**
 * Diana publisher public class.
 * */

namespace dianamessager {

  class Publisher;

  class DianaPublisher : public QObject {
  Q_OBJECT
    friend class DianaFactory;
  public:

    QString getPublisherName() { return publisherName; };
    ~DianaPublisher();


  private:
    DianaPublisher(QObject* parent, const QString& publisherName);
    void init(const QString& master, const QString& host);

  Q_SIGNALS:
    void newMessage(const QString& data);

  private:
    QString publisherName;
    Publisher* publisher;

  };

}  // namespace dianamessager

#endif
