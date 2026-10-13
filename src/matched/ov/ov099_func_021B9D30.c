/*
 * function: WIFICLUBACTOR_InitSpriteManager
 * address: 0x021B9D30
 * packet: pkt_ov099_021B9D30
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C5590 0x021C5590 thumb ov127
 *   func_021C5664 0x021C5664 thumb ov127
 */
#include "../include/Obj13679.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021C5590(void *,void *,u32,void *,int,u32,u32); extern void func_021C5664(char *,int,int);
void WIFICLUBACTOR_InitSpriteManager(u8 *p,void *q,u32 heap) { void *r; r=func_021C5590(((struct Obj13679 *)p)->f14,0,48,q,0,0,heap); ((struct Obj13679 *)p)->f590=r; func_021C5664(r,2,heap); }
