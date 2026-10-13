/*
 * function: GFL_NET_STATE_IsExitReady
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
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *
 * "If the state is non-zero, park the card interface."  The result of the
 * test is kept in a local and returned, so the zero path is the `popeq` that
 * gives back r0 == 0 and the busy path returns whatever GFL_NET_Exit leaves
 * in r0 - no second `mov r0, #0` anywhere.
 *
 * The local is load-bearing: spelling it `if (GFL_NET_SYSTEM_GetCurrentAid() == 0) return 0;
 * return GFL_NET_Exit(0);` hoists the `mov r0, #0` that sets up the call's
 * argument above the conditional return and lands two instructions late.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_IsExitReady.c \
 *       --func GFL_NET_STATE_IsExitReady --addr 0x0203BEAC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int GFL_NET_Exit(int a0);

u32 GFL_NET_STATE_IsExitReady(void)
{
    u32 r;

    r = GFL_NET_SYSTEM_GetCurrentAid();
    if (r != 0)
        r = GFL_NET_Exit(0);
    return r;
}
