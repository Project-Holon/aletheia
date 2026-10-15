/*
 * function: RESEARCH_GRAPH_SetStateChanged
 * address:  0x021BE448
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Set the u32 at +0x3dc to 1.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25898.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_GRAPH_SetStateChanged(void *p)
{
    ((struct Obj25898 *)p)->f3DC = 1;
}
