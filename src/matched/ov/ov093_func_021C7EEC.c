/*
 * function: func_021C7EEC
 * address: 0x021C7EEC
 * packet: pkt_ov093_021C7EEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 */
#include "../include/Obj21111.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 func_021B8DDC(u32 x);
extern u8 *func_021BB85C(u8 *, unsigned int);
int func_021C7EEC(u8 *p, int i) { return func_021BB85C(*(u8 * *)&((struct Obj21111 *)p)->f0, func_021B8DDC(i))[9]; }
