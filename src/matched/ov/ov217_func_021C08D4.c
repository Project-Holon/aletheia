/*
 * function: RESEARCH_GRAPH_RegisterVBlank
 * address:  0x021C08D4
 * packet:   pkt_021C08D4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   RESEARCH_GRAPH_TransferPalettes  0x021BF6BC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25974.h"

extern int func_020056A0(void (*)(void), void *, int);
typedef unsigned int   u32;
extern u32 RESEARCH_GRAPH_TransferPalettes(u32 a0, u32 a1);

void RESEARCH_GRAPH_RegisterVBlank(char *p)
{
    ((struct Obj25974 *)p)->f3C0 = func_020056A0((void (*)(void))RESEARCH_GRAPH_TransferPalettes, p, 0);
}
