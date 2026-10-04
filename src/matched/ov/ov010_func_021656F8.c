/*
 * function: func_021656F8
 * address: 0x021656F8
 * packet: pkt_ov010_021656F8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202744C 0x0202744C thumb
 */
#include "../include/Obj00121.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202744C(void *);
void func_021656F8(u8 *p, u8 v) { ((struct Obj00121 *)p)->f30=0x2c; p[0x34]=v; func_0202744C(p); }
