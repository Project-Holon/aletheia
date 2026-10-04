/*
 * function: func_02179188
 * address: 0x02179188
 * packet: pkt_ov014_02179188
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0217919E precede labelled 021791A0.
 * symbols:
 *   func_02178138 0x02178138 thumb ov014
 *   func_0217814C 0x0217814C thumb ov014
 */
#include "../include/Obj19343.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02178138(int);
extern void func_0217814C(int);
void func_02179188(u8 *p) { if (((struct Obj19343 *)p)->f2 == 8) { func_02178138(9); func_0217814C(25); } }
