/*
 * function: POKETRADE_DEMO_UP_DeleteSlide
 * address:  0x021D572C
 * packet:   pkt_ov118_021D572C
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10351.h"

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 func_020307B0(void *p);

void POKETRADE_DEMO_UP_DeleteSlide(u8 *p, int idx)
{
    if (((struct Obj10351 *)p)->f85C != 0) {
        func_020307B0((void *)(((struct Obj10351 *)p)->f85C));
        ((struct Obj10351 *)p)->f85C = 0;
    }
}
