/*
 * function: func_022020E0
 * address:  0x022020E0
 * packet:   pkt_022020E0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Run the sub-object init, stamp 0x27 and report 2.
 */
#include "../include/Obj12245.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012DAC(int a0);

int func_022020E0(u8 *p)
{
    func_02012DAC((int)func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj12245 *)p)->f0 + 0x40))));
    ((struct Obj12245 *)p)->f28 = 0x27;
    return 2;
}
