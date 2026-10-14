/*
 * function: ZKND_TBAR_GetButtonActorBase
 * address:  0x021BD7F8
 * packet:   pkt_021BD7F8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Returns the word at +0x14.
 */
#include "../include/Obj18238.h"


int ZKND_TBAR_GetButtonActorBase(char *p)
{
    return ((struct Obj18238 *)p)->f14;
}

