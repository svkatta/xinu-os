#include <xinu.h>

unsigned short cpuutil(void){

    uint32 usertime = usercpu(NULLPROC);
    uint32 cpuutil = 100 - usertime*100 /vfineclkcounter ;
    unsigned short retval = (short)(cpuutil);
    return retval;
}