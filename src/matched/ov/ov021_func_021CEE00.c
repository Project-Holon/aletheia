/*
 * function: COMM_ENTRY_TickParentTimeouts
 * address:  0x021CEE00
 * packet:   pkt_ov021_021CEE00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_ENTRY_ClearParentSlot  0x021CEF08  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09739.h"

typedef unsigned char  u8;
typedef short          s16;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void COMM_ENTRY_ClearParentSlot(u8 *p, int i);

void COMM_ENTRY_TickParentTimeouts(u8 *p)
{
    u8 *q = p + 0x13c;
    int i;

    for (i = 0; i < 16; i++) {
        u8 *e = q + i * 0x2c;

        if (e[0x2e] == 1) {
            ((struct Obj09739 *)e)->f30 -= 1;
            if (((struct Obj09739 *)e)->f30 <= 0) {
                COMM_ENTRY_ClearParentSlot(p, i);
                q[0x2d1] = 1;
            }
        }
    }
}
