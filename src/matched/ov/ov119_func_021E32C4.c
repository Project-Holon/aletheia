/*
 * function: POKETRADE_3D_RemoveUnit
 * address:  0x021E32C4
 * packet:   pkt_ov119_021E32C4
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 */
#include "../include/Obj10375.h"

typedef unsigned short u16;

typedef unsigned int   u32;
struct Ctx;
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);

void POKETRADE_3D_RemoveUnit(char *p)
{
    u16 v;

    v = ((struct Obj10375 *)p)->f824;
    if (v != 0xFFFF)
        G3D_UTIL_RemoveUnit(((struct Obj10375 *)p)->f820, v);
    ((struct Obj10375 *)p)->f824 = 0xFFFF;
}
