/*
 * function: func_0203BEAC
 * address:  0x0203BEAC
 * packet:   pkt_0203B6EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *
 * "If the state is non-zero, park the card interface."  The result of the
 * test is kept in a local and returned, so the zero path is the `popeq` that
 * gives back r0 == 0 and the busy path returns whatever func_0203CEAC leaves
 * in r0 - no second `mov r0, #0` anywhere.
 *
 * The local is load-bearing: spelling it `if (func_02039338() == 0) return 0;
 * return func_0203CEAC(0);` hoists the `mov r0, #0` that sets up the call's
 * argument above the conditional return and lands two instructions late.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BEAC.c \
 *       --func func_0203BEAC --addr 0x0203BEAC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 func_02039338(void);
extern int func_0203CEAC(int a0);

u32 func_0203BEAC(void)
{
    u32 r;

    r = func_02039338();
    if (r != 0)
        r = func_0203CEAC(0);
    return r;
}
