/*
 * function: func_021BA1B0
 * address: 0x021BA1B0
 * packet: pkt_ov071_021BA1B0
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020257D0 0x020257D0 thumb
 */
#include "../include/Obj13186.h"

struct Obj;
extern void func_020257D0(struct Obj *o);
void func_021BA1B0(void *unused, char *p) { int i; if (((struct Obj13186 *)p)->f2F0 == 1) { for (i = 0; i < 7; i++) func_020257D0(*(void **)(p + i * 4 + 0x2a0)); ((struct Obj13186 *)p)->f2F0 = 0; } }
