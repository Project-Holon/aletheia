/*
 * function: BEACON_DETAIL_GRA_MoveActor
 * address: 0x021BD13C
 * packet: pkt_ov216_021BD13C
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * prototype: 021BCE8C coordinate parameters are signed short: original uses asrs #16 before each call; same-overlay matched caller 021BD448 declares s16.
 * symbols:
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   BEACON_DETAIL_GRA_SetActorPos 0x021BCE8C thumb ov216
 */
#include "../include/Obj10948.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_FillScrollArea(u32,u32,u32);
extern void BEACON_DETAIL_GRA_SetActorPos(void*,short,short,int);
void BEACON_DETAIL_GRA_MoveActor(u8*p,int a){BG_SYS_FillScrollArea(p[0x7e],3,-a);BEACON_DETAIL_GRA_SetActorPos(*(void* *)&((struct Obj10948 *)p)->f78,220,a+44,1);BEACON_DETAIL_GRA_SetActorPos(*(void* *)&((struct Obj10948 *)p)->f74,200,a+80,1);}
