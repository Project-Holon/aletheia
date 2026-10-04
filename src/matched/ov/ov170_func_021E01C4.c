/*
 * function: func_021E01C4
 * address:  0x021E01C4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED918  0x021ED918  thumb  ov170
 *
 * Query entry 9, then flag state 8.
 */
#include "../include/Obj03849.h"



typedef unsigned int u32;
struct WinMgr;
extern u32 func_0202CDD4(struct WinMgr *mgr, u32 idx);
extern void func_021ED918(char *, int);
int func_021E01C4(char *p)
{
    int v = func_0202CDD4(*(struct WinMgr **)(*(int *)&((struct Obj03849 *)p)->f2C + 0x74), 9);
    func_021ED918(p, 8);
    return v;
}
