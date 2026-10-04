/*
 * function: func_021B6920
 * address: 0x021B6920
 * packet: pkt_ov101_021B6920
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02039338 0x02039338 arm
 */
#include "../include/Obj13716.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_02039338(void);
u32 func_021B6920(u32 a,u8 *p) {
 if(a==func_02039338()) return ((struct Obj13716 *)p)->f2C;
 return ((struct Obj13716 *)p)->f30;
}
