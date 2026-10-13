/*
 * function: PMSIV_BGSCROLL_Task
 * address: 0x021BC828
 * packet: pkt_ov110_021BC828
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj02818.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
void PMSIV_BGSCROLL_Task(void *unused, u8 *p)
{
    if (((struct Obj02818 *)p)->f14) {
        ((struct Obj02818 *)p)->f8 += ((struct Obj02818 *)p)->f10;
        func_02040618((u8)(((struct Obj02818 *)p)->f0), (u8)(((struct Obj02818 *)p)->f4), (int)(((struct Obj02818 *)p)->f8>>12));
        --((struct Obj02818 *)p)->f14;
    } else {
        func_02040618((u8)(((struct Obj02818 *)p)->f0), (u8)(((struct Obj02818 *)p)->f4), (int)(((struct Obj02818 *)p)->fC));
    }
}
