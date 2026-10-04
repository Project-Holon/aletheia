/*
 * function: func_021BA1DC
 * address: 0x021BA1DC
 * packet: pkt_ov071_021BA1DC
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj13187.h"

typedef unsigned char u8;
int func_021BA1DC(char *p, unsigned a) { int x = ((((struct Obj13187 *)p)->f2D8 >> 8) + a) >> 5; if (x >= ((struct Obj13187 *)p)->f27C) x = 0xffff; return x; }
