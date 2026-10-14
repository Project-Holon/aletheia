/*
 * function: GURU2_MAIN_StateDelayRole
 * address: 0x021DEF14
 * packet: pkt_ov137_021DEF14
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj08216.h"
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
int GURU2_MAIN_StateDelayRole(char *p) {if(++((struct Obj08216 *)p)->fC>30){((struct Obj08216 *)p)->fC=0;if(GFL_NET_SYSTEM_GetCurrentAid()==0)((struct Obj08216 *)p)->f0=20;else ((struct Obj08216 *)p)->f0=21;}return 0;}
