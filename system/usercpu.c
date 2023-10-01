/* usercpu.c - usercpu */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  usercpu  - the time (in unit of millisecond) that it has spent executing user code
 *------------------------------------------------------------------------
 */
syscall	usercpu(
    pid32 pid
)
{
    intmask	mask;			/* Saved interrupt mask		*/
    mask = disable();
    if (isbadpid(pid)) {
		restore(mask);
		return SYSERR;
	}

    uint32 usertime = proctab[pid].prusercpu;
    restore(mask);
	return usertime;
}