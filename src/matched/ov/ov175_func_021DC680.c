/*
 * function: func_021DC680
 * address: 0x021DC680
 * packet: pkt_ov175_021DC680
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unlabelled asynchronous state setter blocking matched caller021DC338.
 * symbols:
 *   d_021E4B80 0x021E4B80 data a4
 */
#include "../include/Obj10690.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 d_021E4B80[];
void func_021DC680(u8 *p,int state)
{
    d_021E4B80[0]=0;
    *(u32 *)(d_021E4B80+4)=0;
    ((struct Obj10690 *)p)->f130=state;
    ((struct Obj10690 *)p)->f12C=100;
    ((struct Obj10690 *)p)->f1A0=0;
}
