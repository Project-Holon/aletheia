/*
 * unit: no
 * function: GSYNC_DISP_DeleteMainActor
 * address: 0x021D63E4
 * packet: pkt_ov123_021D63E4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj10440.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *);
void GSYNC_DISP_DeleteMainActor(u8 *p){int i;for(i=0;i<16;i++){u8 *q=p+i*4;if(*(struct Obj * *)&((struct Obj10440 *)q)->f74){CLACT_DeleteActor(*(struct Obj * *)&((struct Obj10440 *)q)->f74);((struct Obj10440 *)q)->f74=0;}}}
