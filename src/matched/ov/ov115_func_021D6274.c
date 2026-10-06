/*
 * function: func_021D6274
 * address: 0x021D6274
 * packet: pkt_ov115_021D6274
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5C24 0x021D5C24 thumb ov115
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D6294 0x021D6294 thumb ov115
 */
#include "../include/Obj22609.h"
typedef unsigned char u8;typedef unsigned int u32;
extern void func_021D5C24(void *,int);
extern void func_021D6134(void *a0, int a1, int a2);
extern void func_021D6294(u8 *);
void func_021D6274(u8 *p) { func_021D5C24(((struct Obj22609 *)p)->f8,27);func_021D6134(p,(int)func_021D6294,0x1e6); }
