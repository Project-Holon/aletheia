/*
 * function: func_0203D788
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
 *   g_021469E0  0x021469E0  data
 *
 * Returns the net context pointer the manager keeps at +8 of 0x021469E0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D788.c \
 *       --func func_0203D788 --addr 0x0203D788 --arm --cc 1.1p1
 */

#include "../include/G_Singleton.h"

typedef unsigned char u8;

extern struct Singleton g_021469E0;

void *func_0203D788(void)
{
    return *(void **)(((u8 *)&g_021469E0) + 8);
}
