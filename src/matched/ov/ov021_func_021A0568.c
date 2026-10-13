/*
 * function: FIELD_LIGHT_Reflect
 * address:  0x021A0568
 * packet:   pkt_ov021_021A0568
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_LIGHT_Apply  0x021A066C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07487.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void FIELD_LIGHT_Apply(u8 *p, u32 a, u32 b);

void FIELD_LIGHT_Reflect(u8 *p, int force)
{
    if (((struct Obj07487 *)p)->f38C != 0 || force != 0) {
        FIELD_LIGHT_Apply(p, ((struct Obj07487 *)p)->f8, ((struct Obj07487 *)p)->f4);
        ((struct Obj07487 *)p)->f38C = 0;
    }
}
