/*
 * function: func_0216519C
 * address:  0x0216519C
 * packet:   pkt_0216519C
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
 *   func_020273F8   0x020273F8  thumb
 */
#include "../include/Obj05718.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020273F8(void *, unsigned);

void func_0216519C(void *a0, unsigned a1)
{
    ((struct Obj05718 *)a0)->f30 = 0x6;
    ((struct Obj05718 *)a0)->f34 = a1;
    func_020273F8(a0, a1);
}

