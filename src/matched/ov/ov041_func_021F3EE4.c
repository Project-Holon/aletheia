/*
 * function: GIMMICK41_FindCannonAt
 * address:  0x021F3EE4
 * packet:   pkt_ov041_021F3EE4
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GIMMICK41_FindCannonAt  0x021F3EE4  thumb
 *   gGimmick41CannonCells     0x021F40F0  data  a2
 */

#include "../include/G__anon_E.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern struct _anon_E gGimmick41CannonCells[];

u8 GIMMICK41_FindCannonAt(int a, int b)
{
    u8 i;

    for (i = 0; i < 10; i++) {
        if (a == gGimmick41CannonCells[i].a && b == gGimmick41CannonCells[i].b) {
            return i;
        }
    }
    return i;
}
