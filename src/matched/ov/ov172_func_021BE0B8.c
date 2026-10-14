/*
 * function: COMM_TVT_SYS_ToggleViewSwapped
 * address:  0x021BE0B8
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Invert the flag at +0x24.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14311.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void COMM_TVT_SYS_ToggleViewSwapped(void *p)
{
    u32 v = ((struct Obj14311 *)p)->f24;
    if (v == 0) {
        v = 1;
    } else {
        v = 0;
    }
    ((struct Obj14311 *)p)->f24 = v;
}
