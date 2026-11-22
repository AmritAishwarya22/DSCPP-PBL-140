#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Task.h"
#include "Server.h"
#include "TaskGenerator.h"
#include "TaskQueue.h"
#include "TaskProcessing.h"
#include "Loadbalancer.h"
using namespace std;
int main() 
{
 srand(time(0));
 Server servers[5000];
 int serverCount = 3;
 int nextServerId = 1;
 for (int i = 0; i < serverCount; i++) 
 {
  servers[i].setServer(nextServerId, 64, 128, 1000);
  nextServerId++;
 }
 TaskQueue queue;
 initializeQueue(&queue, 1000);
 int nextTaskId = 1;
 int totalTasks = 0;
 int secondCount = 0;
 while (totalTasks < 100000) 
 {
  secondCount++;
  for (int i = 0; i < 1000 && totalTasks < 100000; i++) 
  {
   Task task = generateTask(nextTaskId + rand() % 1000);
   task.id = nextTaskId;
   nextTaskId++;
   task.priority = rand() % 10 + 1;
   task.cpu = rand() % 4 + 1;
   task.ram = rand() % 8 + 2;
   task.storage = rand() % 20 + 5;
   task.status = 0;
   task.completed = false;
   enqueue(&queue, task);
  }
  Task currentTask;
  while (dequeue(&queue, &currentTask)) 
  {
   processTask(currentTask);
   int selectedIndex = -1;
   for (int i = 0; i < serverCount; i++) 
   {
    if (checkEligibility1(servers[i], currentTask)) 
    {
     selectedIndex = i;
     break;
    }
   }
   if (selectedIndex == -1) 
   {
    if (serverCount < 5000) 
    {
     selectedIndex = serverCount;
     servers[selectedIndex].setServer(nextServerId, 64, 128, 1000);
     nextServerId++;
     serverCount++;
    } 
    else 
    {
     continue;
    }
   }
   assignTask1(servers[selectedIndex], currentTask);
   totalTasks++;
  }
  cout << "\nSecond " << secondCount << " | Total Tasks: " << totalTasks << " | Servers: " << serverCount << "\n";
  for (int i = 0; i < serverCount; i++) 
  {
   cout << "Server ID = " << servers[i].serverId<< " | CPU = " << servers[i].usedCPU << "/" << servers[i].totalCPU << " Cores"<< " | RAM = " << servers[i].usedRAM << "/" << servers[i].totalRAM << " GB"<< " | Storage = " << servers[i].usedStorage << "/" << servers[i].totalStorage << " GB"<< " | Utilization = " << calculateUtilization1(servers[i]) << "%\n";
  }
 }
 clearQueue(&queue);
 cout << "\nCompleted! Total tasks: " << totalTasks << ", Servers: " << serverCount << "\n";
 return 0;
}