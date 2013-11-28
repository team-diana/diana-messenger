
#include <iostream>

#include "pantilt.hpp"
#include <stdlib.h>

using namespace std;
using namespace dianamessager;

int main(int argc, char* argv[]) {
  if (argc != 4) {
    cout <<  "USAGE: " <<  argv[0] <<  " master_address hostname topic_name" ;
    cout <<  "\nE.G. ./ros_messager_test http://rover.teamdiana.org:11311 http://rover.teamdiana.org /ptu/state";
    exit(-1);
  }

  cout <<  "Start!";

  Pantilt pantilt(argc,  argv,  argv[3]);
  pantilt.on_init(argv[1],  argv[2]);

  while (true) {
    ;
  }
}
