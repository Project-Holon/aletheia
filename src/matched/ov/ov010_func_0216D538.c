/*
 * function: func_0216D538
 * address:  0x0216D538
 * packet:   pkt_ov010_0216D538
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (no lr push): returns the halfword at the pointer held at +0x40, or 0.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19122.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_0216D538(u8 *p)
{
    u16 *q = *(u16 * *)&((struct Obj19122 *)p)->f40;
    if (q != 0)
        return *q;
    return 0;
}
