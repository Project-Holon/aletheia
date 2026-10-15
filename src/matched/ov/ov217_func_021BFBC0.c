/*
 * function: RESEARCH_GRAPH_CreateWordSet
 * address:  0x021BFBC0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   RESEARCH_GRAPH_CreateWordSet  0x021BFBC0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14745.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
void RESEARCH_GRAPH_CreateWordSet(u32 a0)
{
    ((struct Obj14745 *)(((u8*)a0 + 0)))->f18 = (u32)func_0201EC64(((struct Obj14745 *)(((u8*)a0 + 0)))->f4);
}

