/*
 * function: BOX2_SEQ_InitIconSlots
 * address:  0x021ECCA4
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
 * candidate BOX2_SEQ_InitIconSlots: clear six ints
 */
#include "../include/Obj02214.h"


void BOX2_SEQ_InitIconSlots(char *p)
{
    ((struct Obj02214 *)p)->fA088 = -1;
    ((struct Obj02214 *)p)->fA10C = -1;
    ((struct Obj02214 *)p)->fA138 = -1;
    ((struct Obj02214 *)p)->fA08C = -1;
    ((struct Obj02214 *)p)->fA110 = -1;
    ((struct Obj02214 *)p)->fA13C = -1;
}

