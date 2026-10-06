/*
 * function: func_021C4564
 * address: 0x021C4564
 * packet: pkt_ov127_021C4564
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204AC18 0x0204AC18 arm
 */
#include "../include/Obj10466.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
void func_021C4564(u8 *p,u32 a,u32 b,u32 heap) { ((struct Obj10466 *)p)->f2F4=func_0204AC18(((struct Obj10466 *)p)->f2FC,0,a,(u16)b,0,8,heap); }
