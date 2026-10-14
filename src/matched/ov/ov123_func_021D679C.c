/*
 * unit: no
 * function: GSYNC_DISP_HideParticle
 * address: 0x021D679C
 * packet: pkt_ov123_021D679C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj10441.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
void GSYNC_DISP_HideParticle(u8 *p){if(*(struct Obj * *)&((struct Obj10441 *)p)->f0)CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj10441 *)p)->f0,0);((struct Obj10441 *)p)->f0=0;}
