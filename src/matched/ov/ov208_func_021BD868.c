/*
 * function: ZKND_TBAR_GetButtonSound
 * address:  0x021BD868
 * packet:   pkt_021BD868
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj14647.h"

typedef unsigned int   u32;
typedef unsigned short u16;

int ZKND_TBAR_GetButtonSound(const void *p)
{
    u32 r1 = ((struct Obj14647 *)p)->f8;
    u32 r0 = ((struct Obj14647 *)p)->f28;
    return r1 == r0;
}
