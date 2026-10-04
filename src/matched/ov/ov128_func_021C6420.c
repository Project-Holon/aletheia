/*
 * function: func_021C6420
 * address: 0x021C6420
 * packet: pkt_ov128_021C6420
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020355D8 0x020355D8 arm
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj10482.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020355D8(int);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
void func_021C6420(u8 *p) { func_020355D8(((struct Obj10482 *)p)->f0); func_02045808(((struct Obj10482 *)p)->f58); func_02045808(((struct Obj10482 *)p)->f5C); }
