
#include "../include/diana_listener.hpp"
#include "../include/listener.hpp"

#include <iostream>
#include <QDebug>

namespace dianamessenger {

using namespace Qt;

DianaListener::DianaListener(QObject* parent, const QString& publisherName) :
  QObject(parent),
  publisherName(publisherName)
{
  listener = new Listener(0, 0, publisherName);
  connect(listener, SIGNAL(newData(QString)), this, SIGNAL(newMessage(QString)));
}

DianaListener::~DianaListener() {
  delete listener;
}

void DianaListener::init(const QString& master, const QString& host) {
  listener->on_init(master.toStdString(), host.toStdString());
}

}  // namespace dianamessenger

