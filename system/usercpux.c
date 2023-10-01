* usercpux.c - usercpux */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  usercpu  - the time (in unit of millisecond) that it has spent executing user code
 *------------------------------------------------------------------------
 */

syscall	usercpux(pid32 pid)
{  
    // kprintf("usercpux : input : %d\n",pid);
    int retval=1;
    __asm__(
        "pushl %2;"
        "movl %1, %%eax;"
        "int $46;"
        "movl %%eax, %0;"
        "addl $4 ,%%esp;"
        : "=r"(retval)
        : "r"(SYSUSERCPU) , "r"(pid)
        : "%eax"  );
    // kprintf("usercpux : output : %d\n",retval);
	return retval;
}