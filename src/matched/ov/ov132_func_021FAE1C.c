/*
 * function: func_021FAE1C
 * address: 0x021FAE1C
 * packet: pkt_ov132_021FAE1C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj03818.h"
typedef unsigned char u8;
typedef unsigned short u16;

int func_021FAE1C(char *p, int *out)
{
    int start;
    int delta;
    ((struct Obj03818 *)p)->fE += 1;
    if (((struct Obj03818 *)p)->fE >= ((struct Obj03818 *)p)->fC) {
        *out = ((struct Obj03818 *)p)->f8;
        return 1;
    }
    start = ((struct Obj03818 *)p)->f4;
    delta = ((struct Obj03818 *)p)->f8 - start;
    *out = start + (delta * ((struct Obj03818 *)p)->fE) / ((struct Obj03818 *)p)->fC;
    return 0;
}
