/*
 * function: func_02202054
 * address:  0x02202054
 * packet:   pkt_02202054
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Latch state 0x23 and publish the +2 tick of the 0x3c query into +0xdfc.
 */
#include "../include/Obj09248.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012DAC(int a0);
extern u32 func_020056EC(u32 v);

int func_02202054(u8 *p)
{
    func_02012DAC((int)func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj09248 *)p)->f0 + 0x40))));
    ((struct Obj09248 *)p)->f28 = 0x23;
    ((struct Obj09248 *)p)->fDFC = func_020056EC(0x3c) + 2;
    return 2;
}
