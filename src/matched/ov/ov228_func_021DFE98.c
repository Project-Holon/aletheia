/*
 * function: func_021DFE98
 * address:  0x021DFE98
 * packet:   pkt_021DFC20
 * region:   ov228
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf in ov228: 1 when the word at +0x374 of the work object
 * is 3, else 0.  Integrator: seed ov228 0x021DFE98.
 */
#include "../include/Obj26327.h"

typedef unsigned char u8;
typedef unsigned int  u32;

int func_021DFE98(u8 *p)
{
    if (((struct Obj26327 *)p)->f374 == 3)
        return 1;
    return 0;
}
