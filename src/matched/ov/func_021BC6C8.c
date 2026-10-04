/*
 * function: func_021BC6C8
 * address:  0x021BC6C8
 * packet:   pkt_021BC6C8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * True when the word at +0x10, less two, is 0 or 1.
 */
#include "../include/Obj18186.h"


int func_021BC6C8(char *p)
{
    unsigned int v = ((struct Obj18186 *)p)->f10;

    v -= 2;
    return v <= 1;
}

