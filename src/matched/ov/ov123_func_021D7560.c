/*
 * function: func_021D7560
 * address: 0x021D7560
 * packet: pkt_ov123_021D7560
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D751C 0x021D751C thumb ov123
 */
#include "../include/Obj08110.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020307B0(void *);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D751C(int a);
void func_021D7560(u8 *p) { p[165]=0; func_020307B0(((struct Obj08110 *)p)->f40); p[174]=0; ((struct Obj08110 *)p)->f40=0; func_021D6EE0((u8 *)p,(int)func_021D751C,0x328); }
