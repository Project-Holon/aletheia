/*
 * function: GFL_NET_HANDLE_IsNegotiationDone
 * address:  0x020399B8
 * packet:   pkt_020399B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *
 * A null-tolerant predicate on a slot's +0x4A state.  This is the if/else
 * spelling rather than if-return-then-return: the null arm branches to an
 * epilogue of its own at the end, and the tested arm is the fall-through, so
 * the source condition is the `!= 0` one.  The `? ==5 : 0` shape is the
 * `moveq r0, #1` / `movne r0, #0` pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_IsNegotiationDone.c \
 *       --func GFL_NET_HANDLE_IsNegotiationDone --addr 0x020399B8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p)
{
    if (p != 0)
        return p[0x4A] == 5;
    else
        return 0;
}
