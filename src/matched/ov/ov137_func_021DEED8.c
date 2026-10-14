/*
 * function: GURU2_MAIN_StateWaitAllSlotsReady
 * address: 0x021DEED8
 * packet: pkt_ov137_021DEED8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: follower in owned 021DEE4C extent.
 */
#include "../include/Obj14222.h"
int GURU2_MAIN_StateWaitAllSlotsReady(char *p)
{
    char *q=p+0x1a0;
    int i,n,count;
    count=((struct Obj14222 *)p)->f30;
    i=0;
    n=0;
    do {
        if (*(int *)(q+i*0xb4+0x148)==1) n++;
        i++;
    } while(i<count);
    if (n==count) {((struct Obj14222 *)p)->f0=19;return 1;}
    return 0;
}
