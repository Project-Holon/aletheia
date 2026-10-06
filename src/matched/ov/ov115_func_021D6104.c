/*
 * function: func_021D6104
 * address: 0x021D6104
 * packet: pkt_ov115_021D6104
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5E48 0x021D5E48 thumb ov115
 *   func_021D4DF4 0x021D4DF4 thumb ov115
 *   func_021D5A88 0x021D5A88 thumb ov115
 *   func_021D613C 0x021D613C thumb ov115
 */
#include "../include/Obj06415.h"
typedef unsigned char u8;typedef unsigned int u32;
extern void func_021D5E48(u8 *p);
extern void func_021D4DF4(u8 *p);
extern void func_021D5A88(u8 *p);extern int func_021D613C(u8 *);
int func_021D6104(int a,int b,int c,u8 *p) { int result;if(((struct Obj06415 *)p)->f0)func_021D5E48(((struct Obj06415 *)p)->f0);func_021D4DF4(((struct Obj06415 *)p)->f4);func_021D5A88(((struct Obj06415 *)p)->f8);result=0;if(func_021D613C(p))result=1;return result; }
