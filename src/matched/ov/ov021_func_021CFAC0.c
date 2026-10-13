/*
 * function: INTRUDE_FindOfferSlotAt
 * address:  0x021CFAC0
 * packet:   pkt_ov021_021CFAC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Searches the 20 slots (stride 0x14, from +0x10) for one whose table row matches.
 *
 * symbols:
 *   gIntrudeOfferTilePositions  0x021DB834  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12992.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 a0;
    s16 a2;
    s16 a4;
    u16 a6;
} Row;

extern const Row gIntrudeOfferTilePositions[];

int INTRUDE_FindOfferSlotAt(u8 *base, int a, int b, int c, int d)
{
    int i;
    u8 *p = base + 0x10;

    for (i = 0; i < 20; i++, p += 0x14) {
        const Row *r;
        if (((struct Obj12992 *)p)->f10 == 0) {
            return 0xff;
        }
        r = &gIntrudeOfferTilePositions[p[0x12]];
        if (r->a6 == a && r->a0 == b && r->a4 == d && r->a2 - 1 <= c && c <= r->a2 + 1) {
            return i;
        }
    }
    return 0xff;
}
