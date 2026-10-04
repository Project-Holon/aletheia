/*
 * function: func_021EF310
 * address:  0x021EF310
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CA0C  0x0202CA0C  thumb  ov170
 *
 * Forward the word at +0x74.
 */
#include "../include/Obj18533.h"

struct WinMgr;
extern void func_0202CA0C(struct WinMgr *mgr);

void func_021EF310(char *p)
{
    func_0202CA0C(*(struct WinMgr * *)&((struct Obj18533 *)p)->f74);
}

