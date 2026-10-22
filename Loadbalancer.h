#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include "Task.h"
#include "Server.h"
bool checkEligibility1(Server s, Task t);
double calculateUtilization1(Server s);
int selectServer1(Server s[], int n, Task t);
void assignTask1(Server &s, Task t);
#endif