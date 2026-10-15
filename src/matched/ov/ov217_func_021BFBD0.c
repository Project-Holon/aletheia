/*
 * function: RESEARCH_GRAPH_DeleteWordSet
 * address:  0x021BFBD0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 24)) to func_0201ED04.
 *
 * symbols:
 *   func_0201ED04  0x0201ED04  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25954.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct WordSet;
extern u32 func_0201ED04(struct WordSet *p);

void RESEARCH_GRAPH_DeleteWordSet(u8 *a0)
{
    func_0201ED04((struct WordSet *)((u32)(((struct Obj25954 *)a0)->f18)));
}

