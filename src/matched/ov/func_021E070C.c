/*
 * function: func_021E070C
 * address:  0x021E070C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E066C  0x021E066C  thumb  ov170
 *   func_021EF5C4  0x021EF5C4  thumb  ov170
 *
 * 1 unless both queries come back zero.
 */
#include "../include/Obj18462.h"


struct WinMgr;
extern int func_021E066C(char *);
extern int func_021EF5C4(struct WinMgr *mgr);
int func_021E070C(char *p)
{
    if (func_021E066C(p) == 0 && func_021EF5C4(*(struct WinMgr **)(((struct Obj18462 *)p)->f2C + 0x74)) == 0)
        return 0;
    return 1;
}
