#ifndef RESOURCE_RELEASE_H
#define RESOURCE_RELEASE_H
#include "Task.h"
#include "Resource.h"
void initializeTask(Task &task, int id,int cpu, int ram, int storage);
bool completeTask(Task &task);
bool releaseResources(Resource &server, const Task &task);
void displayResources(const Resource &server);
#endif