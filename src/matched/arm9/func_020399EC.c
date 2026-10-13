/*
 * function: GFL_NET_HANDLE_GetNegotiationNum
 * address:  0x020399EC
 * packet:   pkt_020399EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Count how many of the eight slots answer non-zero to the probe: when
 * GFL_NET_GetSession() is null the count is zero, otherwise every slot is asked
 * through GFL_NET_HANDLE_GetNetHandle(i) and GFL_NET_HANDLE_IsNegotiationDone(), and each non-zero answer bumps
 * the counter (the `addne r5, r5, #1` after the loop's `add r4, r4, #1`).
 *
 * The counter is left uninitialised at its declaration and assigned `0` in
 * BOTH arms of the guard.  That is what puts `mov r5, #0` between the guard's
 * `cmp` and its `beq`, and what keeps the exit a single shared epilogue
 * instead of the predicated `moveq r0, r5; popeq` pair.  Declaring
 * `int c = 0;` up front instead hoists the zero above the call (4 bytes of
 * different scheduling), and `if (f() == 0) return c;` predicates the whole
 * early exit and grows the body to 68 bytes.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_GetNegotiationNum.c \
 *       --func GFL_NET_HANDLE_GetNegotiationNum --addr 0x020399EC --cc 1.1p1 --arm
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *GFL_NET_GetSession(void);
typedef signed int     s32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);

int GFL_NET_HANDLE_GetNegotiationNum(void)
{
    int i;
    int c;

    if (GFL_NET_GetSession() != 0) {
        c = 0;
        for (i = 0; i < 8; i++) {
            if (GFL_NET_HANDLE_IsNegotiationDone((u8 *)GFL_NET_HANDLE_GetNetHandle(i)) != 0)
                c++;
        }
    } else {
        c = 0;
    }
    return c;
}
