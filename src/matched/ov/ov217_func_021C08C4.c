/*
 * function: RESEARCH_GRAPH_RestartNetwork
 * address:  0x021C08C4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   RESEARCH_GRAPH_RestartNetwork  0x021C08C4  thumb  ov217
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25973.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);
void RESEARCH_GRAPH_RestartNetwork(u32 a0)
{
    GFL_NET_RefreshWmIconAtTopRight(1, ((struct Obj25973 *)(((u8*)a0 + 0)))->f4);
}

