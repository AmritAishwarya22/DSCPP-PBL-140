#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include "Task.h"
#include "Server.h"
#include <cstdint>
#include <vector>
struct HashNode 
{
 uint32_t hash;
 int serverIndex;
};
uint32_t hashValue(uint32_t x);
std::vector<HashNode> buildHashRing(Server s[], int n, int replicas = 3);
bool checkEligibility1(Server s, Task t);
int selectServer1(Server s[], int n, Task t);
void assignTask1(Server &s, Task t);
double calculateUtilization1(Server s);
#endif