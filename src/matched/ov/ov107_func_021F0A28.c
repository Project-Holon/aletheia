/*
 * function: MB_PARENT_SYS_AllBootable
 * address: 0x021F0A28
 * packet: pkt_ov107_021F0A28
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gMbParentSys 0x021F6EAC data a4
 *   MB_CommIsBootable 0x021F1BE0 arm ov107
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern struct Masks gMbParentSys;extern int MB_CommIsBootable(u16);
int MB_PARENT_SYS_AllBootable(void) { u16 i; if(!*(u16 *)(((u8 *)&gMbParentSys)+10))return 0;for(i=1;i<16;i++){if(*(u16 *)(((u8 *)&gMbParentSys)+10)&(1<<i)){if(!MB_CommIsBootable(i))return 0;}}return 1; }
