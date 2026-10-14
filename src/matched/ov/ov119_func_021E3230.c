/*
 * function: POKETRADE_3D_RemoveCurrentUnit
 * address:  0x021E3230
 * packet:   pkt_021E3230
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_3D_RemoveUnit  0x021E32C4  thumb  ov119
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;

extern void POKETRADE_3D_RemoveUnit(char *p);

void POKETRADE_3D_RemoveCurrentUnit(void *p)
{
    if (((struct Obj00001 *)p)->f109C != 0xFFFFFFFF) {
        POKETRADE_3D_RemoveUnit(p);
        ((struct Obj00001 *)p)->f109C = 0xFFFFFFFF;
    }
}
