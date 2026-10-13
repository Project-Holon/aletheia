/*
 * function: GFL_NET_CallDeviceReadyFunc
 * address:  0x0203D700
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the net context's +0x30 callback with its +0x34c argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_CallDeviceReadyFunc.c \
 *       --func GFL_NET_CallDeviceReadyFunc --addr 0x0203D700 --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 */
#include "../include/Obj11377.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);

void GFL_NET_CallDeviceReadyFunc(void)
{
    u8 *p = GFL_NET_GetSession();

    if (((struct Obj11377 *)p)->f30 != 0) {
        ((void (*)(u32)) * (u32 *)(p + 0x30))(((struct Obj11377 *)p)->f34C);
    }
}
