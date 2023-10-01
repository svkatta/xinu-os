/* chpriox.c - chpriox */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  chprio  -  Change the scheduling priority of a process
 *------------------------------------------------------------------------
 */
pri16	chpriox(
	pid32		pid,		/* ID of process to change	*/
	pri16		newprio		/* New priority			*/
	)
{   
	pri16	oldprio;		/* Priority to return*/
    __asm__("pushw %2;"
        "pushl %3;"
        "movl %1, %%eax;"
        "int $46;"
        "movw %%ax, %0;"
        "addl $6 ,%%esp;"
        : "=r"(oldprio)
        : "r"(SYSCHPRIO) , "r"(newprio) , "r"(pid)
        : "%eax"  );

	return oldprio;
}