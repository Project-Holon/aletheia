/*
 * function: func_021DC90C
 * address: 0x021DC90C
 * packet: pkt_ov137_021DC90C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCB90 0x021DCB90 thumb ov137
 *   func_021DCB60 0x021DCB60 thumb ov137
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj14201.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021DCB90(void *);
extern void func_021DCB60(u8 *p);
extern u32 func_020307B0(void *p);
void func_021DC90C(u8 *p) {func_021DCB90(((struct Obj14201 *)p)->f18);func_021DCB60(((struct Obj14201 *)p)->f18);func_020307B0(p);}
