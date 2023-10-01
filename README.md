# XINU OS
This Project is part of CS503 operating system course. 
# Milestone 1
Branch Lab2

Objective is to extend XINU system calls, which are regular C function calls into trapped system calls using x86 hardware support.

Trapped system calls implemented 
* `getmemx` : similar to malloc() in that it returns a pointer to the start of a requested contiguous memory block.
* `getpidx` : return current pid of process
* `chpriox` : changes priority of process

Created kernel stack for each process and when system call is made system traps from user mode to kernel mode and it switches from user stack to kernel stack. 
Then system call is executed in kernel mode and finally traps back to User mode also switches back to user stack.

