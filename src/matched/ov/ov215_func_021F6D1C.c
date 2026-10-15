/*
 * function: EGG_DEMO_VIEW_UpdateAlpha
 * address: 0x021F6D1C
 * packet: pkt_ov215_021F6D1C
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_GetAlpha 0x02015FAC thumb
 *   MCSS_SetAlpha 0x02015FBC thumb
 */
#include "../include/Obj05551.h"
typedef unsigned char u8;
struct Data;
extern u8 MCSS_GetAlpha(struct Data *);
extern void MCSS_SetAlpha(char *,int);
void EGG_DEMO_VIEW_UpdateAlpha(char *p){u8 n;if(((struct Obj05551 *)p)->f3C){n=MCSS_GetAlpha(*(struct Data * *)&((struct Obj05551 *)p)->f34);if(n>((struct Obj05551 *)p)->f40)n--;else n++;MCSS_SetAlpha(*(char * *)&((struct Obj05551 *)p)->f34,n);if(n==((struct Obj05551 *)p)->f40)((struct Obj05551 *)p)->f3C=0;}}
