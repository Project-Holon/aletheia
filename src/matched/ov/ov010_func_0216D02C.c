/*
 * function: func_0216D02C
 * address: 0x0216D02C
 * packet: pkt_ov010_0216D02C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216D0F8 0x0216D0F8 thumb ov010
 *   func_021642F8 0x021642F8 thumb ov010
 */
#include "../include/Obj19118.h"
typedef unsigned char u8;
extern void func_0216D0F8(void *obj, const u8 *a1);
extern void func_021642F8(void *a0);
void func_0216D02C(int a, u8 *p) {
    if (((struct Obj19118 *)p)->f18 == 0) func_0216D0F8((void *)a, p);
    else func_021642F8((void *)a);
}
