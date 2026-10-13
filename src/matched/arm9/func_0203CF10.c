/*
 * function: func_0203CF10
 * address:  0x0203CF10
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
 * Dispatches through the vtable at +0x340 of the state object: the entry at
 * +0x28 takes the single argument and its result is returned.  A missing state
 * object is the `moveq`/`popeq` pair that answers 0.  The vtable pointer
 * itself is not checked - src/matched/GFL_NET_SetLinkTimeout.c is the neighbouring
 * hook that does check it.
 *
 * The indirect call is a register `blx` with an ordinary `pop {r4, pc}`
 * epilogue: not the ARMv4T-style return that would name a 1.2-built function,
 * so it is compiled C like any other.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CF10.c \
 *       --func func_0203CF10 --addr 0x0203CF10 --cc 1.1p1 --arm
 */
#include "../include/Obj15974.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef u32 (*Fn)(u32);

extern void *GFL_NET_GetSession(void);

u32 func_0203CF10(u32 a)
{
    u8  *p;
    Fn   f;

    p = GFL_NET_GetSession();
    if (p == 0)
        return 0;
    f = *(Fn *)(((struct Obj15974 *)p)->f340 + 0x28);
    return f(a);
}
