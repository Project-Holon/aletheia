/*
 * function: GFL_NET_SetErrorCheckEnabled
 * address:  0x0203D8C4
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gGFLNetMain  0x021469E0  data
 *
 * Writes 1 or 0 to the net context's +0x352 byte depending on whether the
 * argument is 1; a null context is a no-op.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SetErrorCheckEnabled.c \
 *       --func GFL_NET_SetErrorCheckEnabled --addr 0x0203D8C4 --arm --cc 1.1p1
 */

#include "../include/G_Singleton.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Singleton gGFLNetMain;

void GFL_NET_SetErrorCheckEnabled(u32 a)
{
    u8 *p = *(u8 **)(((u8 *)&gGFLNetMain) + 8);

    if (p == 0) {
        return;
    }
    if (a == 1) {
        p[0x352] = 1;
    } else {
        p[0x352] = 0;
    }
}
