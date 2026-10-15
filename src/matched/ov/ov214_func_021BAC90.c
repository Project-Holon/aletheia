/*
 * unit: no
 * function: BTL_REC_SEL_InitBgGfx2
 * address: 0x021BAC90
 * packet: pkt_ov214_021BAC90
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204989C 0x0204989C arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 */
#include "../include/Obj14701.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);extern void func_02041B6C(u32);extern void BG_SYS_FillScrollArea(u32,u32,u32);
void BTL_REC_SEL_InitBgGfx2(int unused,u8 *p){enum{K=2}k=K;func_0204989C(188,3,k,(u16)(((struct Obj14701 *)p)->f2C0),0,0,((struct Obj14701 *)p)->f0);func_02041B6C(2);k-=10;BG_SYS_FillScrollArea(3,3,k);}
