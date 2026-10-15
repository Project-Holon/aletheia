/*
 * function: RESEARCH_LIST_UnregisterVBlank
 * address:  0x021BD5E0
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
 *   RESEARCH_LIST_UnregisterVBlank  0x021BD5E0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14735.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Node;
extern void func_02030EAC(struct Node *n);
void RESEARCH_LIST_UnregisterVBlank(u32 a0)
{
    func_02030EAC((struct Node *)(((struct Obj14735 *)(((u8*)a0)))->f154));
    ((struct Obj14735 *)(((u8*)a0)))->f154 = 0;
}

