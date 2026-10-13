/*
 * function: GFL_NET_GetFriendList
 * address:  0x0203D610
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the net context's +0x40 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_GetFriendList.c \
 *       --func GFL_NET_GetFriendList --addr 0x0203D610 --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 */
#include "../include/Obj11375.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);

u32 GFL_NET_GetFriendList(void)
{
    u8 *p = GFL_NET_GetSession();

    if (((struct Obj11375 *)p)->f40 == 0) {
        return 0;
    }
    return ((u32 (*)(u32)) * (u32 *)(p + 0x40))(((struct Obj11375 *)p)->f34C);
}
