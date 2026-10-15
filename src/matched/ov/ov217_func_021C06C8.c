/*
 * function: RESEARCH_GRAPH_CreateOamSys
 * address:  0x021C06C8
 * packet:   pkt_ov217_021C06C8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_OAM_CreateSys  0x02025538  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10961.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int BMP_OAM_CreateSys(u16 heap, int a);

void RESEARCH_GRAPH_CreateOamSys(u8 *p)
{
    ((struct Obj10961 *)p)->f3A4 = BMP_OAM_CreateSys(((struct Obj10961 *)p)->f4, ((struct Obj10961 *)p)->f38C);
}
