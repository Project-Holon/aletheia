/*
 * function: MUSICAL_MCSS_ResetRender2
 * address: 0x021F5414
 * packet: pkt_ov112_021F5414
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MUSICAL_MCSS_ResetRender 0x021F53D8 thumb ov112
 */
#include "../include/Obj01717.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void MUSICAL_MCSS_ResetRender(int);
void MUSICAL_MCSS_ResetRender2(int a,int b) { if(b!=((struct Obj01717 *)a)->f4)MUSICAL_MCSS_ResetRender(a); }
