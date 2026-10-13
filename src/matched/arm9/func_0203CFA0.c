/*
 * function: GFL_NET_RequestDisconnect
 * address:  0x0203CFA0
 * packet:   pkt_0203CF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_Main  0x0203B1D8  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_RequestDisconnect.c \
 *       --func GFL_NET_RequestDisconnect --addr 0x0203CFA0 --cc 1.1p1 --arm
 */
#include "../include/Obj15976.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
extern void *GFL_NET_GetInitParam(void);
extern u32 GFL_NET_STATE_Main(void);

void GFL_NET_RequestDisconnect(void)
{
    u8 *s = GFL_NET_GetSession();
    u8 *p;

    if (GFL_NET_STATE_Main() != 0)
        return;
    if (s == 0 || ((struct Obj15976 *)s)->f340 == 0)
        return;

    p = GFL_NET_GetInitParam();
    switch (p[0x65]) {
    case 1:
    case 2:
        return;
    }

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(0);
}
