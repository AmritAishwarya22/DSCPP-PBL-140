#include<iostream>
#include "TaskProcessing.h"
#include "ResourceRelease.h"
using namespace std;    
bool completeTask(Task &task)
{
 if(task.status==1)
 {
  task.status=2;
  cout<<"Task "<<task.id<<" is now completed\n";
 }
 else
 {
  cout<<"Task "<<task.id<<" cannot be completed as it is not in progress\n";
 }
 if (task.completed)
 {
 cout << "Task " << task.id<< " is already completed.\n";
 return false;
 }
 task.completed = true;
 cout << "Task " << task.id<< " Task is now completed\n";
 return true;
}