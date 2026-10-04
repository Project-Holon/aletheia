/*
 * function: func_021BAD58
 * address:  0x021BAD58
 * packet:   pkt_ov068_021BAD58
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Shift the word field at 0x3c left by one.
 */
#include "../include/Obj20647.h"

void func_021BAD58(void *p)
{
    ((struct Obj20647 *)p)->f3C <<= 1;
}
