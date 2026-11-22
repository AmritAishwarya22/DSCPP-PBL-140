#include <iostream>
#include"TaskProcessing.h"
using namespace std;
void processTask(Task &t)
{
 if(t.status==0)
 {
  t.status=1;
  cout<<"Task "<<t.id<<" is now in progress\n";
 }
}
