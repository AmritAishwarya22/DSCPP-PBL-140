#include "Loadbalancer.h"
void assignTask1(Server &s, Task t) 
{
 if (checkEligibility1(s, t)) 
 {
  s.usedCPU = s.usedCPU + t.cpu;
  s.usedRAM = s.usedRAM + t.ram;
  s.usedStorage = s.usedStorage + t.storage;
 }
}