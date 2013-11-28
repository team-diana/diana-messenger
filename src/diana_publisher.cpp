
#include "../include/diana_publisher.hpp"
#include "../include/listener.hpp"
#include "../include/publisher.hpp"

#include <iostream>
#include <QDebug>

namespace dianamessager {

using namespace Qt;

DianaPublisher::DianaPublisher(QObject* parent, const QString& publisherName) :
  QObject(parent),
  publisherName(publisherName)
{
  //publisher = new Publisher(0, 0, publisherName);
}

DianaPublisher::~DianaPublisher() {
  //delete publisher;
}

void DianaPublisher::init(const QString& master, const QString& host) {
  //publisher->on_init(master.toStdString(), host.toStdString());
}

}  // namespace dianamessager

