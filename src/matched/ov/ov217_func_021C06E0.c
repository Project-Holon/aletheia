/*
 * function: RESEARCH_GRAPH_DeleteOamSys
 * address:  0x021C06E0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 932)), 932 to BMP_OAM_DeleteSys.
 *
 * symbols:
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25966.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void BMP_OAM_DeleteSys(void *p);

void RESEARCH_GRAPH_DeleteOamSys(u8 *a0)
{
    BMP_OAM_DeleteSys((void *)((u32)(((struct Obj25966 *)a0)->f3A4)));
}

