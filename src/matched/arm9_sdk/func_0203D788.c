/*
 * function: GFL_NET_GetSession
 * address:  0x0203D788
 * packet:   pkt_0203D788
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
 * Returns the net context pointer the manager keeps at +8 of 0x021469E0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_GetSession.c \
 *       --func GFL_NET_GetSession --addr 0x0203D788 --arm --cc 1.1p1
 */

#include "../include/G_Singleton.h"

typedef unsigned char u8;

extern struct Singleton gGFLNetMain;

void *GFL_NET_GetSession(void)
{
    return *(void **)(((u8 *)&gGFLNetMain) + 8);
}
