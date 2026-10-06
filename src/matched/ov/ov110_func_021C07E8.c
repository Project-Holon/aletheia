/*
 * function: func_021C07E8
 * address: 0x021C07E8
 * packet: pkt_ov110_021C07E8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj08011.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020307B0(void *p);
void func_021C07E8(u8 *p) { func_020452E8(((struct Obj08011 *)p)->f24); func_0203FB44(3,(u16)(((struct Obj08011 *)p)->f0),(u16)(((struct Obj08011 *)p)->f0>>16)); func_020307B0(((struct Obj08011 *)p)->f4); }
