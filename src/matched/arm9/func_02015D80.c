/*
 * function: MCSS_SetShadowRotateX
 * address:  0x02015D80
 * packet:   pkt_02015D80
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: halfword setter at +0x178; called from ov131 P_STA_SUB_CreateMcss (bl at
 *   +0x78 and +0xB6) with the pooled full-width value 0xD555.
 */
#include "../include/Obj15659.h"

typedef unsigned char u8;
typedef unsigned short u16;

void MCSS_SetShadowRotateX(u8 *p, u16 v)
{
    ((struct Obj15659 *)p)->f178 = v;
}
