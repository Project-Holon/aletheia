/*
 * function: func_021BA004
 * address: 0x021BA004
 * packet: pkt_ov071_021BA004
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9FF8 0x021B9FF8 thumb ov071
 */
#include "../include/Obj00044.h"

extern void func_021B9FF8(void *, int);
void func_021BA004(char *p) { if (((struct Obj00044 *)p)->f304 == 1) func_021B9FF8(p, ((struct Obj00044 *)p)->f2F8); }
