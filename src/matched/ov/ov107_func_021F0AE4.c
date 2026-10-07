/*
 * function: func_021F0AE4
 * address: 0x021F0AE4
 * packet: pkt_ov107_021F0AE4
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6EAC 0x021F6EAC data a4
 *   func_021F0D1C 0x021F0D1C thumb ov107
 *   func_021F5F74 0x021F5F74 arm ov107
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern struct Masks d_021F6EAC;extern void func_021F0D1C(u16),func_021F5F74(void);
void func_021F0AE4(void) { func_021F0D1C(6);if(*(int *)(((u8 *)&d_021F6EAC)+24)==1){*(int *)(((u8 *)&d_021F6EAC)+24)=0;func_021F5F74();} }
