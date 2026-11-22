#include <iostream>
#include "ResourceRelease.h"
using namespace std;
bool releaseResources(Resource &server, const Task &task)
{
 if (!task.completed)
 {
  cout << " Task is not completed \n";
  return false;
 }
 if (task.cpu > server.usedCPU ||task.ram > server.usedRAM ||task.storage > server.usedStorage)
 {
  cout << "Invalid resources \n";
  return false;
 }
 server.usedCPU -= task.cpu;
 server.usedRAM -= task.ram;
 server.usedStorage -= task.storage;
 cout << "Resources released for Task \n"<< task.id ;
 return true;
}