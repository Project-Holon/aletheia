/*
 * function: ZKND_TBAR_GetTouchEnable
 * address:  0x021BD35C
 * packet:   pkt_021BD35C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Returns the word at +0xC (the two words after it are untraced continuations).
 */
#include "../include/Obj18230.h"


int ZKND_TBAR_GetTouchEnable(char *p)
{
    return ((struct Obj18230 *)p)->fC;
}

