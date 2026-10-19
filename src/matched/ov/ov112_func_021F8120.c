/*
 * function: STA_ACT_LIGHT_IsRenderVisible
 * address: 0x021F8120
 * packet: pkt_ov112_021F8120
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Existing matched follower STA_ACT_LIGHT_SetActorFlagB.c follows.
 * symbols:
 *   MUSICAL_MCSS_IsRenderVisible 0x021F5388 thumb ov112
 */
#include "../include/Obj22568.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int MUSICAL_MCSS_IsRenderVisible(u8 **p);
int STA_ACT_LIGHT_IsRenderVisible(int a,u8 *p) { return MUSICAL_MCSS_IsRenderVisible(((struct Obj22568 *)p)->f58); }
