/*
 * function: ZKND_TBAR_GetButtonCount
 * address:  0x021BD878
 * packet:   pkt_021BD878
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)

 * Clears the word at +0x34.
 */
#include "../include/Obj18243.h"


void ZKND_TBAR_GetButtonCount(char *p)
{
    ((struct Obj18243 *)p)->f34 = 0;
}

