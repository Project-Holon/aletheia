/*
 * function: func_021DD4A4
 * address: 0x021DD4A4
 * packet: pkt_ov171_021DD4A4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj24053.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void*,u32,u32,u32,u32,u32,u32);
int func_021DD4A4(u8*p,int v){WIPE_SYS_Start(0,1,1,0,6,1,0x8c);((struct Obj24053 *)p)->fC74=v;return 2;}
