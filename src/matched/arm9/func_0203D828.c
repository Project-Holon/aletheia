/*
 * function: GFL_NET_GetIrcParams
 * address:  0x0203D828
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
 * Reads back the two net_irc_wireless context words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_GetIrcParams.c \
 *       --func GFL_NET_GetIrcParams --addr 0x0203D828 --arm --cc 1.1p1
 */

#include "../include/G_Singleton.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Singleton gGFLNetMain;

void GFL_NET_GetIrcParams(u32 *a, u32 *b)
{
    *a = *(u32 *)(((u8 *)&gGFLNetMain) + 0xc);
    *b = *(u32 *)(((u8 *)&gGFLNetMain) + 4);
}
