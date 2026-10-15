/*
 * function: STA_ACT_LIGHT_DeleteModel
 * address: 0x021F6F4C
 * packet: pkt_ov112_021F6F4C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow code.
 * symbols:
 *   STA_ACT_LIGHT_FreeModel 0x021F7048 thumb ov112
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00670.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void STA_ACT_LIGHT_FreeModel(u8 *,u32);
extern u32 func_020307B0(void *p);
void STA_ACT_LIGHT_DeleteModel(u8 *p) { if(*(u32 *)&((struct Obj00670 *)p)->f1C) STA_ACT_LIGHT_FreeModel(p,*(u32 *)&((struct Obj00670 *)p)->f1C); func_020307B0(p); }
