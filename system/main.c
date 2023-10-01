/*  main.c  - main */

#include <xinu.h>

void process1(void);
void process2(void);
void process3(void);
void process4(void);
int counter1=0;
int counter2=0;
int counter3=0;
int counter4=0;

process	main(void)
{
    
    	kprintf("\nHello World!\n");
    	kprintf("\nI'm the first XINU app and running function main() in system/main.c.\n");
    	kprintf("\nI was created by nulluser() in system/initialize.c using create().\n");
    	kprintf("\nMy creator will turn itself into the do-nothing null process.\n");
    	kprintf("\nI will create a second XINU app that runs shell() in shell/shell.c as an example.\n");
    	kprintf("\nYou can do something else, or do nothing; it's completely up to you.\n");
    	kprintf("\n...creating a shell\n");

	/* lab2.p4 part1 test */

	/* create 4 equal priority process are in suspended state */
	pid32 pid1 = create(process1, 1024, 15, "test process 1", 0);
	pid32 pid2 = create(process2, 1024, 15, "test process 2", 0);
	pid32 pid3 = create(process3, 1024, 15, "test process 3", 0);
	pid32 pid4 = create(process4, 1024, 15, "test process 4", 0);

	/* resume all process */
	/* unless main quantum runsout all process more or less have same time to run */
	resume(pid1);
	resume(pid2);
	resume(pid3);
	resume(pid4);

	sleep(20);


	kprintf("\ncpuutil of process 1 %d, counter: %d\n",proctab[pid1].prusercpu,counter1);
	kprintf("\ncpuutil of process 2 %d, counter: %d\n",proctab[pid2].prusercpu,counter2);
	kprintf("\ncpuutil of process 3 %d, counter: %d\n",proctab[pid3].prusercpu,counter3);
	kprintf("\ncpuutil of process 4 %d, counter: %d\n",proctab[pid4].prusercpu,counter4);
	sleep(1);
	
	/* Run the Xinu shell */


	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	return OK;
    
}

void process1(void){
	int timecounter = vfineclkcounter;
	while( vfineclkcounter - timecounter <5000 ){
		counter1=counter1+1;
	}
}

void process2(void){
	int timecounter = vfineclkcounter;
	while( vfineclkcounter - timecounter <5000 ){
		counter2=counter2+1;
	}
}

void process3(void){
	int timecounter = vfineclkcounter;
	while( vfineclkcounter - timecounter <5000 ){
		getprio(currpid);
		counter3=counter3+1;
	}
}

void process4(void){
	int timecounter = vfineclkcounter;
	while( vfineclkcounter - timecounter <5000 ){
		getprio(currpid);
		counter4=counter4+1;
	}
}
