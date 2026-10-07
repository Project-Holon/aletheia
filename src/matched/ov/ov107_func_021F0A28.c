/*
 * function: func_021F0A28
 * address: 0x021F0A28
 * packet: pkt_ov107_021F0A28
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6EAC 0x021F6EAC data a4
 *   func_021F1BE0 0x021F1BE0 arm ov107
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern struct Masks d_021F6EAC;extern int func_021F1BE0(u16);
int func_021F0A28(void) { u16 i; if(!*(u16 *)(((u8 *)&d_021F6EAC)+10))return 0;for(i=1;i<16;i++){if(*(u16 *)(((u8 *)&d_021F6EAC)+10)&(1<<i)){if(!func_021F1BE0(i))return 0;}}return 1; }
