/*
 * function: WORLDTRADE_ENTER_SetListRangeEntry
 * address:  0x021F89A8
 * packet:   pkt_021F89A8
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
 * Store a pair of u16 values at +4 and +0x18 of record i.
 */
#include "../include/Obj12204.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
void WORLDTRADE_ENTER_SetListRangeEntry(u8 *p, int i, u16 a, u16 b)
{
    u8 *q = p + i * 2;

    ((struct Obj12204 *)q)->f4 = a;
    ((struct Obj12204 *)q)->f18 = b;
}
