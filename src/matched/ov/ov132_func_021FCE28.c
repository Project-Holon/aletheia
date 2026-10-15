/*
 * function: MUS_COMM_FUNC_GetSlotValueA
 * address: 0x021FCE28
 * packet: pkt_ov132_021FCE28
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj23273.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int MUS_COMM_FUNC_GetSlotValueA(char *p,u32 index) {if(((struct Obj23273 *)p)->f4C!=0 && *(int *)((u32)p+index*0x30+0x68)==1)return *(int *)((u32)p+index*0x30+0x84);return 0;}
