/*
 * function: GFL_NET_GetScanResultMac
 * address:  0x0203CF3C
 * packet:   pkt_0203CDD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * The same vtable dispatch as src/matched/func_0203CF10.c, one slot further
 * on (+0x2C) and without the null test: the state object is assumed live and
 * the hook's pointer result is returned to the caller.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_GetScanResultMac.c \
 *       --func GFL_NET_GetScanResultMac --addr 0x0203CF3C --cc 1.1p1 --arm
 */
#include "../include/Obj15975.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef void *(*Fn)(u32);

extern void *GFL_NET_GetSession(void);

void *GFL_NET_GetScanResultMac(u32 a)
{
    u8  *p;
    Fn   f;

    p = GFL_NET_GetSession();
    f = *(Fn *)(((struct Obj15975 *)p)->f340 + 0x2C);
    return f(a);
}
