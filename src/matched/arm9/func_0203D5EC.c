/*
 * function: GFL_NET_GetWifiUserData
 * address:  0x0203D5EC
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the net context's +0x44 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_GetWifiUserData.c \
 *       --func GFL_NET_GetWifiUserData --addr 0x0203D5EC --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 */
#include "../include/Obj11374.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);

u32 GFL_NET_GetWifiUserData(void)
{
    u8 *p = GFL_NET_GetSession();

    if (((struct Obj11374 *)p)->f44 == 0) {
        return 0;
    }
    return ((u32 (*)(u32)) * (u32 *)(p + 0x44))(((struct Obj11374 *)p)->f34C);
}
