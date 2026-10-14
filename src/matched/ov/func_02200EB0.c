/*
 * function: WORLDTRADE_SERVER_CreateStrings
 * address:  0x02200EB0
 * packet:   pkt_02200EB0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm  arm9
 *

 * Claim the 0xb4/0x48 resource and park it at +0xb88.
 */
#include "../include/Obj18610.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

void WORLDTRADE_SERVER_CreateStrings(u8 *p)
{
    ((struct Obj18610 *)p)->fB88 = (u32)STRBUF_Create(0xb4, 0x48);
}
