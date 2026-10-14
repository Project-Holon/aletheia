/*
 * function: loadbit
 * address:  0x021BF610
 * packet:   pkt_021C2AD0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Bit reader: when the state block at g_021C88F0 has no bits left it fetches
 * the next byte from a0 at the cursor a1, records it plus a 0/1 escape flag
 * (0xff marks an escape and skips one padding byte) and reloads 8 bits; then
 * it returns the top bit, decrementing the counter.
 *
 * symbols:
 *   g_021C88F0  0x021C88F0  data
 *
 * Addresses are Black-image addresses.
 */

#include "../include/G_BCode2.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern struct BCode2 g_021C88F0[];

int loadbit(u8 *a0, int *a1)
{
    if (g_021C88F0[0].bits == 0) {
        int i = *a1;
        u32 v;

        *a1 = i + 1;
        v = a0[i];
        g_021C88F0[0].byte = v;
        g_021C88F0[0].esc = 0;
        if (v == 0xff) {
            (*a1)++;
            g_021C88F0[0].byte = 0xff;
            g_021C88F0[0].esc = 1;
        }
        g_021C88F0[0].bits = 8;
    }
    g_021C88F0[0].bits--;
    return (g_021C88F0[0].byte >> g_021C88F0[0].bits) & 1;
}
