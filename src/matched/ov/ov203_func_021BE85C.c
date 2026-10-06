/*
 * function: func_021BE85C
 * address:  0x021BE85C
 * packet:   pkt_021BE85C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj14590.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021BE85C(char *a)
{
    func_020307B0((void *)((struct Obj14590 *)a)->f8);
    func_020307B0((void *)((struct Obj14590 *)a)->f0);
    func_020307B0(a);
}