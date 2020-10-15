#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(int argc,char *argv[])
{
  int pid = 0;
  if(argc<2){
  	printf(1,"-1, Please provide PID: getProcInfo <PID>\n");
	exit();
  }
  struct processInfo *processinfo = (struct processInfo*)malloc(sizeof(struct processInfo));
  pid = atoi(argv[1]);
  int flag = getprocinfo(pid,processinfo);
  if(flag!=-1){
  printf(1,"Parent ID of process with ID %d is %d\n",pid ,processinfo->ppid);
  printf(1,"Size of process with ID %d is %d bytes\n",pid ,processinfo->psize);
  printf(1,"Number of context switches for process with ID %d is %d\n",pid ,processinfo->numberContextSwitches);
  }
  else
  printf(1,"-1, No running process with id %d\n",pid);
  exit();
}