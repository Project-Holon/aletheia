/*
 * function: func_021FAD08
 * address:  0x021FAD08
 * packet:   pkt_021FAD08
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 *
 * Flush the queued value when the probe reports empty, then answer -1.
 */
#include "../include/Obj09234.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct WinMgr;
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);

int func_021FAD08(u8 *p)
{
    if (func_0202CE40(*(struct WinMgr * *)&((struct Obj09234 *)p)->f18, 0) == 0) {
        ((struct Obj09234 *)p)->f48 = ((struct Obj09234 *)p)->f4C;
    }
    return -1;
}
