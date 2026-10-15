/*
 * function: func_021F6F8C
 * address: 0x021F6F8C
 * packet: pkt_ov112_021F6F8C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   d_021F8430 0x021F8430 data a4
 *   d_021F8418 0x021F8418 data a4
 */
#include "../include/Obj13838.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Arg;
extern void MTX_Identity33_(void *);
extern void G3D_SYSTEM_DrawObject(void *,struct Arg *);
extern u32 d_021F8430[];
extern struct Arg d_021F8418;
void func_021F6F8C(u8 *p) { if(((struct Obj13838 *)p)->f1C) { MTX_Identity33_(d_021F8430); G3D_SYSTEM_DrawObject(((struct Obj13838 *)p)->f3C,&d_021F8418); } }
