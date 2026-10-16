/*
 * function: STA_ACT_LIGHT_StartRenderAnim
 * address: 0x021F80A0
 * packet: pkt_ov112_021F80A0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_GetRenderFieldA 0x021F539C thumb ov112
 */
#include "../include/Obj13844.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void MUSICAL_MCSS_GetRenderFieldA(void **p);
void STA_ACT_LIGHT_StartRenderAnim(int a,u8 *p) { MUSICAL_MCSS_GetRenderFieldA(((struct Obj13844 *)p)->f58); ((struct Obj13844 *)p)->f4C=1; }
