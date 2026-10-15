/*
 * function: STA_ACT_LIGHT_StepModelAnim
 * address: 0x021F6F64
 * packet: pkt_ov112_021F6F64
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow code.
 * symbols:
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 */
#include "../include/Obj13837.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *,int,int);
void STA_ACT_LIGHT_StepModelAnim(u8 *p) { u8 i; if(((struct Obj13837 *)p)->f1C) { for(i=0;i<3;i++) G3D_SYSTEM_LoopObjectAnimeFrame(((struct Obj13837 *)p)->f3C,i,4096); } }
