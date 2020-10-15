#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main()
{
  int maxpid = getmaxpid();
  if(maxpid!=-1)
  printf(1 , "Maximum PID among all PID's is %d\n" , maxpid);
  else
  printf(1,"No running process\n");
  exit();
}