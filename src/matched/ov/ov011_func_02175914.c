/*
 * unit:     yes
 * function: func_02175914, func_02175920, func_0217592C
 * address:  0x02175914
 * packet:   pkt_02175914
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three one-byte flag setters at fixed offsets.
 */
#include "../include/Obj12430.h"
#include "../include/Obj12431.h"

void func_02175914(int a, int b)
{
    *(unsigned char *)(a + b + 0x194) = 1;
}

void func_02175920(int a)
{
    ((struct Obj12430 *)a)->f19A = 1;
}

void func_0217592C(int a)
{
    ((struct Obj12431 *)a)->f19B = 1;
}
