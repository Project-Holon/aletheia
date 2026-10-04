/*
 * function: func_021EF69C
 * address:  0x021EF69C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CC70  0x0202CC70  thumb  ov170
 *
 * Forward the word at +0x74 with index 11.
 */
#include "../include/Obj18537.h"

typedef unsigned int u32;
struct WinMgr;
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);

void func_021EF69C(char *p)
{
    func_0202CC70(*(struct WinMgr * *)&((struct Obj18537 *)p)->f74, 0xb);
}

