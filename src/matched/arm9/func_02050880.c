/*
 * function: BILLBOARD_ACT_GetEntryCursor
 * address:  0x02050880
 * packet:   pkt_02050880
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Leaf witness for ov021 0x0219F058 and siblings (lane wA1-06).
 */
#include "../include/Obj11455.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 BILLBOARD_ACT_GetEntryCursor(u8 *p, int i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj11455 *)p)->f18 + i * 40 + 0x10);
}
