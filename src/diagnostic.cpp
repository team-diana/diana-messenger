/*We have added the file diagnostic.cpp, which parses and analyzes the diagnostics
msg sent to the diagnostics topic and saves its key-values pairs in a hashTable.*/

#include "../include/diagnostic.hpp"

#include <iostream>

#include <QDebug>
//#include <QDebug>

namespace dianamessager {

using namespace Qt;


Diagnostic::Diagnostic(int argc, char** argv)
	: QNode(argc,argv, QString("DiagnosticMessager").toStdString().c_str()) //A cosa si riferisce il terzo argomento?
  
{
  std::cout << "\n<diagnostic constructor>";
  QHash<QString , QVariant> table;
  
 /***Just to try if it works***/
  table.insert("one" , QVariant(166)); //int
  table.insert("two" , QVariant(QString::fromStdString("Second"))); //QString doesn't work
  table.insert("three" , QVariant(false)); //bool
  table.insert("four" , QVariant(1.5)); //float
  table.insert("one" , QVariant(55));  //Updates a value
std::cout << "\none: " << table["one"].toInt() << "\tthree: " << table["three"].toBool() << "\tfour: " << table["four"].toFloat();
//std::cout << "\n" << "\ntwo: " << table["due"].toString().toLatin1();
qDebug() << "two\t" << table["two"].toString();
}

Diagnostic::~Diagnostic() {
}

// In questa funzione il nodo della nostra libreria si sottoscrive al nodo diagnostics_agg per 
// ricevere ogni messaggio pubblicato. chatterCallback e` la funzione che verra` 
// chiamata ogni volta.
void Diagnostic::ros_comms_init() {
  ros::NodeHandle n;
  std::cout << "\n<ros_comms_init>";
	chatter_subscriber = n.subscribe("diagnostics", 1000, &Diagnostic::chatterCallback, this);
}

void Diagnostic::chatterCallback(const diagnostic_msgs::DiagnosticArray::ConstPtr &msg) {  //Perchè ConstPtr?

 int n_status = msg->status.size(); 

 std::cout << "\n" << n_status << "\n";
 
  //std::cout << "\nchatterCallback\n";
  
  //All tha data will be together or there will be many tables (e.g. One for each node)?
  //In the following lines we use only a table for all

  //Whe should know how many items there are in the array, otherwise we cannot iterate over it 
		//We need a double cycle (one to iterate over all the diagnosticStatusMsg in the array and one over all the keyValues
		//for each diagnosticStatusMsg)

  for(int i=0; i<n_status; i++)  //N is the number of diagnosticStatus for each disgnosticArray
  {
     std::cout << "We are in a new StatusMsg:\t" << msg->status[i].name << "\n";
     int n_pairs=msg->status[i].values.size();
     for(int j=0; j<n_pairs; j++)  //M is the number of KeyValue pairs for each diagnosticStatus
     {
        std::cout << "We are in a new key-value pair with key:\t" << msg->status[i].values[j].key << "\n";
	table.insert(QString::fromStdString(msg->status[i].values[j].key) , QVariant(QString::fromStdString(msg->status[i].values[j].value)));
     }
  }
  //Q_EMIT newData(data);
}

// Questa funzione viene chiamata dal nostro nodo ogni ciclo. Per ora non ci serve.
void Diagnostic::run() {
	ros::spin();
        std::cout << "\ndiagnostic_run";
    //Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}  // namespace dianamessager
