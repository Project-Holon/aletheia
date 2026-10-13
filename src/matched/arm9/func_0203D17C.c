/*
 * function: GFL_NET_SetLinkTimeout
 * address:  0x0203D17C
 * packet:   pkt_0203D12C
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
 * Vtable dispatch with the *vtable pointer* null-checked (the state object
 * itself is not): the entry at +0xC4 takes the argument, and the hook's value
 * is dropped.  Two loads separate the two tests, which is what makes this
 * shape distinct from src/matched/GFL_NET_GetScanResult.c and
 * src/matched/GFL_NET_GetScanResultMac.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SetLinkTimeout.c \
 *       --func GFL_NET_SetLinkTimeout --addr 0x0203D17C --cc 1.1p1 --arm
 */
#include "../include/Obj15981.h"
#include "../include/Obj15982.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef void (*Fn)(u32);

extern void *GFL_NET_GetSession(void);

void GFL_NET_SetLinkTimeout(u32 a)
{
    u8  *p;
    u32 *vt;
    Fn   f;

    p = GFL_NET_GetSession();
    vt = *(u32 * *)&((struct Obj15981 *)p)->f340;
    if (vt == 0)
        return;
    f = *(Fn *)&((struct Obj15982 *)vt)->fC4;
    f(a);
}
