/*
 * function: GFL_NET_IRC_WIRELESS_GetBeaconData
 * address:  0x0203E420
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * net_irc_wireless.c.  Runs the context's +0x78 method on the caller's
 * argument, copies 0x4C bytes of its result to +0xB4 and returns the +0x90
 * buffer.  The earlier notes (GFL_NET_IRC_WIRELESS_GetBeaconData.c.txt, pkt_0203E420.c.txt) read
 * the function as taking no argument; the image keeps r0 untouched through
 * the global load (`ldr r1, =g`), which is the argument being forwarded to
 * the method, the same shape as GFL_NET_IRC_WIRELESS_GetBeaconCompare.
 *
 * symbols:
 *   gNetIrcWirelessLink     0x021469F0  data
 *   MI_CpuCopy8  0x02082D44  arm
 */

#include "../include/G_Ctx.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Ctx *gNetIrcWirelessLink;
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

void *GFL_NET_IRC_WIRELESS_GetBeaconData(void *arg)
{
    struct Ctx *p = gNetIrcWirelessLink;
    void *r;

    if (p == 0)
        return 0;
    r = p->fn_18(arg);
    MI_CpuCopy8(r, (u8 *)p + 0xB4, 0x4C);
    return (u8 *)p + 0x90;
}
