#include "../include/diana_factory.hpp"

#include <iostream>
#include <QDebug>

namespace dianamessager {

using namespace Qt;

DianaFactory::DianaFactory(const QString& master, const QString& host) :
  master(master), host(host)
  {}

DianaListener* DianaFactory::createListener(const QString& publisherName) {
  DianaListener* listener = new DianaListener(0, publisherName);
  listener->init(master, host);
  return listener;
}

DianaPublisher* DianaFactory::createPublisher(const QString& publisherName) {
  DianaPublisher* publisher = new DianaPublisher(0, publisherName);
  publisher->init(master, host);
  return publisher;
}

}  // namespace dianamessager

