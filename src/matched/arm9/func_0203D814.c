/*
 * function: GFL_NET_SetIrcParams
 * address:  0x0203D814
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
 * Stores the two net_irc_wireless context words at +0xc and +4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SetIrcParams.c \
 *       --func GFL_NET_SetIrcParams --addr 0x0203D814 --arm --cc 1.1p1
 */

#include "../include/G_Singleton.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Singleton gGFLNetMain;

void GFL_NET_SetIrcParams(u32 a, u32 b)
{
    *(u32 *)(((u8 *)&gGFLNetMain) + 0xc) = a;
    *(u32 *)(((u8 *)&gGFLNetMain) + 4) = b;
}
