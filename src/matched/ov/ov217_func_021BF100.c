/*
 * function: RESEARCH_GRAPH_PrintTitle
 * address:  0x021BF100
 * packet:   pkt_021BF100
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call through a pool word: bx r3 spends r3 on the target, so only the
 * two argument registers are live (see docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * symbols:
 *   BgTextLabel_PrintMessage  0x021C0F5C  thumb  ov217
 *   d_021C3628     0x021C3628  data   ov217  a4
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14738.h"

extern unsigned char d_021C3628[];
typedef unsigned int   u32;
extern u32 BgTextLabel_PrintMessage(u32 a0, u32 a1);

void RESEARCH_GRAPH_PrintTitle(char *p)
{
    BgTextLabel_PrintMessage(((struct Obj14738 *)p)->f348, d_021C3628[((struct Obj14738 *)p)->f38]);
}
