/*
 * function: func_021BB5A4
 * address: 0x021BB5A4
 * packet: pkt_ov070_021BB5A4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_021B61C8 0x021B61C8 thumb ov070
 */
#include "../include/Obj00002.h"
typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021B61C8(void *);
void func_021BB5A4(char *p) { if (((struct Obj00002 *)p)->f80C == 2 || ((struct Obj00002 *)p)->f80C == 3 || func_021B61C8(p) <= 1) func_0204B878(((struct Obj00002 *)p)->f72C, 4); else func_0204B878(((struct Obj00002 *)p)->f72C, 0); }
