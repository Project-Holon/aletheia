/*
 * function: func_021C5420
 * address: 0x021C5420
 * packet: pkt_ov136_021C5420
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0203D34C 0x0203D34C arm
 *   d_020A1448 0x020A1448 data a4
 *   d_021C77C4 0x021C77C4 data a4
 */
#include "../include/Obj06526.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_020A1448[],d_021C77C4[];
extern void func_0204A48C(void *,void *,u16);
extern void *func_0204B100(int,int,u16);
typedef unsigned int   u32;
struct Bank;
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0203D34C(int,u16);
void func_021C5420(u8 *p)
{
    func_0204A48C(d_020A1448,d_021C77C4,((struct Obj06526 *)p)->f0);
    ((struct Obj06526 *)p)->fA0 = func_0204B100(4,0,((struct Obj06526 *)p)->f0);
    func_0204B270(((struct Obj06526 *)p)->fA0);
    func_020434DC(16,1);
    func_02043598(16,1);
    func_0203D34C(0,((struct Obj06526 *)p)->f0);
}
