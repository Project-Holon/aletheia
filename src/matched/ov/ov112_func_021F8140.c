/*
 * function: STA_ACT_LIGHT_CallElemE
 * address: 0x021F8140
 * packet: pkt_ov112_021F8140
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_ResetRender2 0x021F5414 thumb ov112
 */
#include "../include/Obj10327.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void MUSICAL_MCSS_ResetRender2(int a, int b);
void STA_ACT_LIGHT_CallElemE(int a,u8 *p,int b) { ((struct Obj10327 *)p)->f8=b; MUSICAL_MCSS_ResetRender2((int)(((struct Obj10327 *)p)->f58),b); ((struct Obj10327 *)p)->f4=1; }
