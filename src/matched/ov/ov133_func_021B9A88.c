/*
 * function: func_021B9A88
 * address: 0x021B9A88
 * packet: pkt_ov133_021B9A88
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00228.h"
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void func_021B9A88(unsigned char *p,unsigned int limit) {*(unsigned int *)&((struct Obj00228 *)p)->f18=0;*(unsigned int *)&((struct Obj00228 *)p)->f14=0;(((struct Obj00228 *)p)->f1844)++;CLACT_SetActorDrawEnable(((struct Obj00228 *)p)->f1854,0);if(((struct Obj00228 *)p)->f1844>limit){((struct Obj00228 *)p)->f1844=0;(((struct Obj00228 *)p)->f1846)++;}}
