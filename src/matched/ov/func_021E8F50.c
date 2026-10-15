/*
 * function: BOX2_SEQ_ReturnAfterClear
 * address:  0x021E8F50
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Clear the pooled-offset word and return the argument.
 */
#include "../include/Obj00000.h"
#include "../include/Obj18468.h"


int BOX2_SEQ_ReturnAfterClear(char *p, int v)
{
    ((struct Obj18468 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA194 = 0;
    return v;
}

