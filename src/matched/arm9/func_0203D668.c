/*
 * function: GFL_NET_SetUserArg
 * address:  0x0203D668
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the argument at +0x34c of the net context, when there is one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SetUserArg.c \
 *       --func GFL_NET_SetUserArg --addr 0x0203D668 --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 */
#include "../include/Obj15990.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);

void GFL_NET_SetUserArg(u32 v)
{
    u8 *p = GFL_NET_GetSession();

    if (p != 0) {
        ((struct Obj15990 *)p)->f34C = v;
    }
}
