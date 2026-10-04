/*
 * function: func_021BF79C
 * address:  0x021BF79C
 * packet:   pkt_021BF79C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE9E8 0x021BE9E8 thumb
 */
#include "../include/Obj14599.h"

extern void func_021BE9E8(int);

void func_021BF79C(char *a)
{
    func_021BE9E8(((struct Obj14599 *)a)->f2C);
    ((struct Obj14599 *)a)->f2C = 0;
}
