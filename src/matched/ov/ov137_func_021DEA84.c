/*
 * function: func_021DEA84
 * address: 0x021DEA84
 * packet: pkt_ov137_021DEA84
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02039338 0x02039338 arm
 */
#include "../include/Obj08214.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020221A4(void);
extern u16 func_02039338(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
int func_021DEA84(u8 *p)
{
    if (func_020221A4()) {
        ((struct Obj08214 *)p)->f0 = func_02039338() == 0 ? 2 : 8;
        ((struct Obj08214 *)p)->fDA8 = func_0202EE30(((struct Obj08214 *)p)->fD98, ((struct Obj08214 *)p)->fCF0, 15, 16, 114);
        return 1;
    }
    return 0;
}
