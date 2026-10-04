/*
 * function: func_021FAD84
 * address:  0x021FAD84
 * packet:   pkt_021FAD84
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
 * Drain the queue then flush the shadowed value, always answering -1.
 */
#include "../include/Obj07245.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct WinMgr;
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);

int func_021FAD84(u8 *p)
{
    if (func_0202CE40(*(struct WinMgr * *)&((struct Obj07245 *)p)->f18, 0) == 0) {
        func_0202CC70(*(struct WinMgr * *)&((struct Obj07245 *)p)->f18, 0);
        ((struct Obj07245 *)p)->f48 = ((struct Obj07245 *)p)->f4C;
    }
    return -1;
}
