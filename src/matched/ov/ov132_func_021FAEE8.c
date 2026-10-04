/*
 * function: func_021FAEE8, func_021FAF10
 * unit: yes
 * follower: func_021FAF10 at 0x021FAF10
 * address: 0x021FAEE8
 * packet: pkt_ov132_021FAEE8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj05400.h"
#include "../include/Obj14098.h"
typedef unsigned char u8;
typedef unsigned short u16;

int func_021FAEE8(char *p)
{
    ((struct Obj05400 *)p)->f4 += 1;
    if (((struct Obj05400 *)p)->f4 >= ((struct Obj05400 *)p)->f8) {
        ((struct Obj05400 *)p)->fC -= 1;
        ((struct Obj05400 *)p)->f4 = 0;
        if (((struct Obj05400 *)p)->fC == 0) return 2;
        return 1;
    }
    return 0;
}

int func_021FAF10(void *unused, char *p)
{
    ((struct Obj14098 *)p)->f16 = 1 | ((struct Obj14098 *)p)->f16;
    return 1;
}
