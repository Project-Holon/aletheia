/*
 * function: func_021CA40C
 * address: 0x021CA40C
 * packet: pkt_ov128_021CA40C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj00179.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Obj;
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021CA40C(char *p, int n) {func_0204B8C4(((struct Obj00179 *)p)->f1A4,0);func_0204B878(((struct Obj00179 *)p)->f1A4,n+2);}
