/*
 * function: STA_ACT_LIGHT_SetElemB
 * address: 0x021F6F1C
 * packet: pkt_ov112_021F6F1C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj08025.h"
typedef unsigned int u32;
void STA_ACT_LIGHT_SetElemB(void *a,char *p,u32 b,u32 c)
{
    ((struct Obj08025 *)p)->f14=b;
    ((struct Obj08025 *)p)->f18=c;
}
