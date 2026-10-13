/*
 * function: GFL_NET_ClearBeaconCallbacks
 * address:  0x0203D864
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the net context's +0x2c and +0x1c words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_ClearBeaconCallbacks.c \
 *       --func GFL_NET_ClearBeaconCallbacks --addr 0x0203D864 --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 */
#include "../include/Obj11380.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);

void GFL_NET_ClearBeaconCallbacks(void)
{
    u8 *p = GFL_NET_GetSession();

    if (p != 0) {
        ((struct Obj11380 *)p)->f2C = 0;
        ((struct Obj11380 *)p)->f1C = 0;
    }
}
