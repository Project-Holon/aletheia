/*
 * function: func_02166714
 * address: 0x02166714
 * packet: pkt_ov010_02166714
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj07308.h"
typedef signed short s16;
typedef unsigned char u8;
void func_02166714(u8 *p, int n) {
    int q;
    ((struct Obj07308 *)p)->f4 = n;
    q = ((struct Obj07308 *)p)->f4 / 1350;
    if (((struct Obj07308 *)p)->f8 <= q) ((struct Obj07308 *)p)->f8 = q;
}
