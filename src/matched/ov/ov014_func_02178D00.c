/*
 * function: func_02178D00
 * address: 0x02178D00
 * packet: pkt_ov014_02178D00
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02178138 0x02178138 thumb ov014
 *   func_0217814C 0x0217814C thumb ov014
 */
#include "../include/Obj12475.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02178138(int);
extern void func_0217814C(int);
void func_02178D00(u8 *p) { if (((struct Obj12475 *)p)->f2 != 0) { func_02178138(9); func_0217814C(((struct Obj12475 *)p)->f2); } else { func_02178138(1); } }
