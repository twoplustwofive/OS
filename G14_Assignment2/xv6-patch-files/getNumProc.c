#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main()
{
  printf(1 , "Number of Processes are %d\n" , getnumproc());
  exit();
}