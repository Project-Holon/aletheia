/*
 * function: ARROW_Init
 * address:  0x021C256C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialise the container and clear its 0x1a 0x18-byte records.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03378.h"
#include "../include/Obj04643.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void ARROW_Init(void *p, u16 v)
{
    int i;
    ((struct Obj03378 *)p)->f0 = v;
    ((struct Obj03378 *)p)->f20 = 0;
    ((struct Obj03378 *)p)->f24 = 0;
    ((struct Obj03378 *)p)->f298 = 0;
    ((struct Obj03378 *)p)->f4 = 0;
    for (i = 0; i < 0x1a; i++) {
        u8 *e = (u8 *)p + i * 0x18;
        ((struct Obj04643 *)e)->f28 = 0;
        ((struct Obj04643 *)e)->f2C = 0;
        ((struct Obj04643 *)e)->f30 = 0;
        ((struct Obj04643 *)e)->f34 = 0;
        ((struct Obj04643 *)e)->f36 = 0;
        ((struct Obj04643 *)e)->f37 = 0;
        ((struct Obj04643 *)e)->f3C = 0;
    }
}
