#include <iostream>
#include "Task.h"
#include "TaskGenerator.h"
#include "TaskQueue.h"
#include "Loadbalancer.h"
#include "Server.h"
using namespace std;
int main() 
{
 int numTasks;
 cout << "How many tasks per sec \n";
 cin >> numTasks;
 TaskQueue q;
 initializeQueue(&q, numTasks + 5);
 int i = 1;
while (i <= numTasks)  
{
 Task t = generateTask(i);
 enqueue(&q, t);
 i++;
}
int numServers;
cout << "Enter number of servers\n ";
cin >> numServers;
Server* servers = new Server[numServers];
int j = 0;
while (j < numServers) 
{
 servers[j].setServer(j + 1, 16, 32, 500);
 j++;
}
Task myTask;
while (!isEmpty(&q)) 
{
 if (dequeue(&q, &myTask))  
 {
  int index = selectServer1(servers, numServers, myTask);
  if (index != -1)  
  {
   if (checkEligibility1(servers[index], myTask)) 
   {
    assignTask1(servers[index], myTask);
   }
  }
 }
}
cout << "Load Balancer and Server Details\n";
j = 0;
while (j < numServers) 
{
 if (servers[j].usedCPU > 0 || servers[j].usedRAM > 0 || servers[j].usedStorage > 0) 
 {
  cout << "Server ID \n " << servers[j].serverId ;
 } else 
 {
  cout << "Server ID \n " << servers[j].serverId ;
 }
 double util = calculateUtilization1(servers[j]);
 cout << "\nUtilization \n" << util << "%\n";
 servers[j].displayServer();
 j++;
 }
 delete[] servers;
 clearQueue(&q);
 return 0;
}