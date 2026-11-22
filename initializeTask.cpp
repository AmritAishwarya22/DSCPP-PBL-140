#include "ResourceRelease.h"
void initializeTask(Task &task, int id,int cpu, int ram, int storage)
{
 task.id = id;
 task.cpu = cpu;
 task.ram = ram;
 task.storage = storage;
 task.completed = false;
}