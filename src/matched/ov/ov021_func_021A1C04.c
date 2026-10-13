/*
 * function: WEATHER_UnloadOverlay
 * address:  0x021A1C04
 * packet:   pkt_ov021_021A1C04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02034A5C  0x02034A5C  arm
 */
#include "../include/Obj00755.h"

typedef unsigned char u8;

void func_02034A5C(int x);

void WEATHER_UnloadOverlay(u8 *p)
{
    if (((struct Obj00755 *)p)->f28 != -1) {
        func_02034A5C(((struct Obj00755 *)p)->f28);
        ((struct Obj00755 *)p)->f28 = -1;
    }
}
