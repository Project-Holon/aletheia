/*
 * function: PMS_INPUT_HitScrollBarDrag
 * address: 0x021BF08C
 * packet: pkt_ov110_021BF08C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   PMS_INPUT_VIEW_SetWordwinScrollOffset 0x021BAD14 thumb ov110
 */
#include "../include/Obj00493.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void PMS_INPUT_VIEW_SetWordwinScrollOffset(u8 *,unsigned);
int PMS_INPUT_HitScrollBarDrag(u8 *p) {
 unsigned x,y;
 if(TOUCHPANEL_GetPointCont(&x,&y)==1 && p[0x6a]==1) { PMS_INPUT_VIEW_SetWordwinScrollOffset(*(u8 * *)&((struct Obj00493 *)p)->f14,y); return 1; }
 p[0x6a]=0;
 return 0;
}
