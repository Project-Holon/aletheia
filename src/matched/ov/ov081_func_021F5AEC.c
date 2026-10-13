/*
 * function: ENCEFF_InitGridSpread
 * address:  0x021F5AEC
 * packet:   pkt_ov081_021F5AEC
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03673.h"

typedef unsigned char u8;
typedef unsigned short u16;

void ENCEFF_InitGridSpread(u8 *w)
{
    u8 *t = w + 0x300C;

    ((struct Obj03673 *)t)->f182 = 0;
    ((struct Obj03673 *)t)->f180 = 0;
    ((struct Obj03673 *)t)->fC0 = 0x33;
    (((struct Obj03673 *)t)->f182)++;
    ((struct Obj03673 *)t)->fC2 = 0x95;
    (((struct Obj03673 *)t)->f182)++;
    ((struct Obj03673 *)t)->fC4 = 0x5B;
    (((struct Obj03673 *)t)->f182)++;
}
