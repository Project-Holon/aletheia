/*
 * function: PMSIV_CATEGORY_ApplyBgOffset
 * address: 0x021BB8B8
 * packet: pkt_ov110_021BB8B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after return.
 * symbols:
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   func_02041EE4 0x02041EE4 arm
 */
#include "../include/Obj22368.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void func_02041EE4(u32,u32,u32);
void PMSIV_CATEGORY_ApplyBgOffset(u8 *p) { int v; if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj22368 *)p)->f4)==0) v=-4; else v=0; func_02041EE4(1,0,v); }
