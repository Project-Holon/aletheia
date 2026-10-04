/*
 * function: func_02039414
 * address:  0x02039414
 * packet:   pkt_02039414
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *
 * Asks the transport's +0x88 virtual whether the link is up, falling back to
 * the +0x1E9 flag of the object at 0x021469D0 when the virtual is missing or
 * answers zero.  Both re-tests are conditional-execution chains (`cmpne`), so
 * the source is the `!= 0 && ...` spelling in each place.  The result local
 * is declared after the context refresh and assigned at its first use: with
 * `u32 r = 0;` ahead of the refresh the value is live across func_0203D788
 * and the allocator spends a callee-saved register on it (`push {r4, lr}`
 * instead of the original's `push {r3, lr}`).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039414.c  *       --func func_02039414 --addr 0x02039414 --cc 1.1p1 --arm
 */
#include "../include/Obj15941.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void *func_0203D798(void);

u32 func_02039414(void)
{
    u8 *p = func_0203D788();
    u32 r = 0;

    if (p != 0 && ((struct Obj15941 *)p)->f340 != 0)
        r = ((u32 (*)(void))*(u32 *)(*(u32 *)(p + 0x340) + 0x88))();
    if (r == 0) {
        u8 *q = *(u8 **)(0x21469D0);

        if (q != 0 && q[0x1E9] != 0)
            r = 1;
    }
    return r;
}
