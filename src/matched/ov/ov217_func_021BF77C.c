/*
 * function: RESEARCH_GRAPH_GetRightCircle
 * address:  0x021BF77C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed u32 read: table at +0x2c4, index from the u32 at +0x2cc.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25940.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u8 *RESEARCH_GRAPH_GetRightCircle(void *p)
{
    u32 i = ((struct Obj25940 *)p)->f2CC;
    return *(u8 **)((char *)p + i * 4 + 0x2c4);

}
