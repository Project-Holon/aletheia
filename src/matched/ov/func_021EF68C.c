/*
 * function: func_021EF68C
 * address:  0x021EF68C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Forward the word at +0x74 plus constants to func_0202CB4C.
 */
#include "../include/Obj18536.h"

typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);

void func_021EF68C(char *p)
{
    func_0202CB4C(*(struct WinMgr * *)&((struct Obj18536 *)p)->f74, 0xb, 0, 0x15);
}

