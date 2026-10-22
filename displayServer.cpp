#include <iostream>
#include "Server.h"
using namespace std;
void Server::displayServer()
{
 cout << "\nServer ID \n " << serverId;
 cout << "\nCPU Used \n " << usedCPU << "/" << totalCPU;
 cout << "\nRAM Used in GB\n " << usedRAM << "/" << totalRAM;
 cout << "\nStorage Used in GB\n " << usedStorage << "/" << totalStorage << endl;
}