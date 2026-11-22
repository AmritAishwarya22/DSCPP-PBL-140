#include <iostream>
#include "Server.h"
using namespace std;
void Server::displayServer()
{
 int remainingCPU = totalCPU - usedCPU;
 int remainingRAM = totalRAM - usedRAM;
 int remainingStorage = totalStorage - usedStorage;
 double cpuUtil = (totalCPU > 0) ? ((double)usedCPU / totalCPU) * 100 : 0;
 double ramUtil = (totalRAM > 0) ? ((double)usedRAM / totalRAM) * 100 : 0;                                                  
 double storageUtil = (totalStorage > 0) ? ((double)usedStorage / totalStorage) * 100 : 0;
 double overallUtil = (cpuUtil + ramUtil + storageUtil) / 3.0;
 cout << "\nSERVER ID = " << serverId << "\n";
 cout << "\nCPU = Used/Total " << usedCPU << "/" << totalCPU << " in Cores , Remaining in cores = " << remainingCPU << "  Utilization = " << cpuUtil << "%\n";
 cout << "\nRAM = Used/Total " << usedRAM << "/" << totalRAM << " in GB, Remaining in GB = " << remainingRAM << " Utilization = " << ramUtil << "%\n";
 cout << "\nStorage = Used/Total " << usedStorage << "/" << totalStorage << " in GB, Remaining in GB = " << remainingStorage << " Utilization = " << storageUtil << "%\n";
 cout << "\nTotal Server Utilization = " << overallUtil << "%\n";
}