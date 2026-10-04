/*
 * function: func_021650BC
 * address:  0x021650BC
 * packet:   pkt_021650BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:   wild=4
 *
 * Stamp the fixed id halfword and the caller's value on the two
 * record fields, then jump to the shared submitter.
 *
 * symbols:
 *   func_020273C4   0x020273C4  thumb
 */
#include "../include/Obj12050.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020273C4(void *, unsigned);

void func_021650BC(void *a0, unsigned a1)
{
    ((struct Obj12050 *)a0)->f30 = 0x2;
    ((struct Obj12050 *)a0)->f32 = a1;
    func_020273C4(a0, a1);
}

