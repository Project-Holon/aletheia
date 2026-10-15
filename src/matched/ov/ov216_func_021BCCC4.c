/*
 * function: BEACON_DETAIL_GRA_IsTouchOnActor
 * address: 0x021BCCC4
 * packet: pkt_ov216_021BCCC4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 */
#include "../include/Obj14718.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
int BEACON_DETAIL_GRA_IsTouchOnActor(u8*p){u32 x,y;if(TOUCHPANEL_GetPointTrg(&x,&y)){if((u32)(x-(((struct Obj14718 *)p)->f25C-12))<=24 && (u32)(y-(((struct Obj14718 *)p)->f25E-16))<=32)return 1;}return 0;}
