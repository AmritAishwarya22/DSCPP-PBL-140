#ifndef TASK_H
#define TASK_H
struct Task
{
 int id;
 int priority;
 int cpu;
 int ram;
 int storage;
 int status;
 bool completed;
};
#define MAX_TASKS 100
#endif