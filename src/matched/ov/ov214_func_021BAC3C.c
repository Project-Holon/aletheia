/*
 * unit: no
 * function: BTL_REC_SEL_DeleteBgRun
 * address: 0x021BAC3C
 * packet: pkt_ov214_021BAC3C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 */
#include "../include/Obj25728.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
void BTL_REC_SEL_DeleteBgRun(int unused,u8 *p){u32 v=((struct Obj25728 *)p)->f2C0;BG_SYS_DeleteHalf(2,(u16)v,(u16)(v>>16));}
