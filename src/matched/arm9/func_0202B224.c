/*
 * function: ISS_ROAD_SYS_Deactivate
 * address:  0x0202B224
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the object's state word when it is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_Deactivate.c \
 *       --func ISS_ROAD_SYS_Deactivate --addr 0x0202B224 --thumb --cc 1.1p1
 */
#include "../include/Obj11313.h"

typedef unsigned char u8;
typedef unsigned int  u32;

void ISS_ROAD_SYS_Deactivate(u8 *p)
{
    if (((struct Obj11313 *)p)->f0 != 0) {
        ((struct Obj11313 *)p)->f0 = 0;
    }
}
