/*
 * function: func_021F0B04
 * address: 0x021F0B04
 * packet: pkt_ov107_021F0B04
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6EAC 0x021F6EAC data a4
 *   func_021F5F74 0x021F5F74 arm ov107
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern struct Masks d_021F6EAC;extern void func_021F5F74(void);
void func_021F0B04(void) { if(*(u16 *)(((u8 *)&d_021F6EAC)+8)==4 && *(u16 *)(((u8 *)&d_021F6EAC)+10)==*(u16 *)(((u8 *)&d_021F6EAC)+20) && *(int *)(((u8 *)&d_021F6EAC)+24)==1){*(int *)(((u8 *)&d_021F6EAC)+24)=0;func_021F5F74();} }
