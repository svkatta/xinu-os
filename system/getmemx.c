/* getmemx.c - getmemx */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  getmem  -  Allocate heap storage, returning lowest word address
 *------------------------------------------------------------------------
 */
char  	*getmemx(
	  uint32	nbytes		/* Size of memory requested	*/
	)
{
    char * retval;
    __asm__(
        "pushl %2;"
        "movl %1, %%eax;"
        "int $46;"
        "movl %%eax, %0;"
        "addl $4 ,%%esp;"
        : "=r"(retval)
        : "r"(SYSMEMGET) , "r"(nbytes)
        : "%eax"  );
	return retval;
}