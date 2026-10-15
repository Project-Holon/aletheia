/*
 * unit: no
 * function: BTL_REC_SEL_InitBgGfx3
 * address: 0x021BACCC
 * packet: pkt_ov214_021BACCC
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204989C 0x0204989C arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 */
#include "../include/Obj14702.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);extern void func_02041B6C(u32);extern void BG_SYS_FillScrollArea(u32,u32,u32);
void BTL_REC_SEL_InitBgGfx3(int unused,u8 *p){enum{K=3}k;func_0204989C(188,4,2,(u16)(((struct Obj14702 *)p)->f2C0),0,0,((struct Obj14702 *)p)->f0);func_02041B6C(2);k=K;BG_SYS_FillScrollArea(3,3,k-11);}
