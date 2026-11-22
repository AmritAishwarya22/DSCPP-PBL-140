#include <iostream>
#include "ResourceRelease.h"
using namespace std;
void displayResources(const Resource &server)
{
 cout << "Server Status\n";
 cout << "CPU Used \n"<< server.usedCPU << "/" << server.totalCPU << endl;
 cout << "RAM Used \n "<< server.usedRAM << "/" << server.totalRAM << endl;
 cout << "Storage Used \n"<< server.usedStorage << "/" << server.totalStorage << endl;
}