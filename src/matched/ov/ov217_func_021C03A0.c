/*
 * function: RESEARCH_GRAPH_CreateUnits
 * address:  0x021C03A0
 * packet:   pkt_ov217_021C03A0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C3620  0x021C3620  data  a2
 *   d_021C3618  0x021C3618  data  a1
 *   CLACT_CreateUnit  0x0204B100  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25960.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern const u16 d_021C3620[];
extern const u8 d_021C3618[];
typedef unsigned int   u32;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

void RESEARCH_GRAPH_CreateUnits(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(int *)(p + i * 4 + 0x384) = (int)CLACT_CreateUnit(d_021C3620[i], d_021C3618[i], ((struct Obj25960 *)p)->f4);
}
