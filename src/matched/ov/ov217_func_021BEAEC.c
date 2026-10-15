/*
 * function: RESEARCH_GRAPH_ClearEntryIndex
 * address:  0x021BEAEC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_GRAPH_ClearEntryIndex  0x021BEAEC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25911.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;


void RESEARCH_GRAPH_ClearEntryIndex(u8 *a0)
{
    ((struct Obj25911 *)(((u8*)a0)))->f2B9 = 0;
}

