/*
 * function: WORLDTRADE_ENTER_SendProfile
 * address: 0x021F8BBC
 * packet: pkt_ov135_021F8BBC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NHTTP_RAP_InitTrainerInfo 0x021B9B00 thumb ov114
 *   DPW_TR_SetProfileAsync 0x021C8E18 arm ov114
 */
#include "../include/Obj14167.h"
#include "../include/Obj23400.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void NHTTP_RAP_InitTrainerInfo(u8 *,int);
extern void DPW_TR_SetProfileAsync(u8 *,u32);
int WORLDTRADE_ENTER_SendProfile(u8 *p) { NHTTP_RAP_InitTrainerInfo(p+0xf18,((struct Obj23400 *)(*(u8 * *)&((struct Obj14167 *)p)->f0))->f1C);DPW_TR_SetProfileAsync(p+0xf18,(u32)(p+0xf7c));((struct Obj14167 *)p)->fF8C=0;return 1; }
