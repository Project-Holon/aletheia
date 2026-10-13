/*
 * unit:     no
 * function: GFL_NET_IsHandleReady
 * address:  0x0203D394
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TU: net.c.
 *
 * Leaf predicate on the +0x4a byte of an entry: "is this entry in state 5".
 * No relocation and no frame; the same three-instruction body appears
 * inlined inside GFL_NET_HANDLE_IsNegotiationDone.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_IsHandleReady.c \
 *       --func GFL_NET_IsHandleReady --addr 0x0203D394 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct NetEntry {
    u8 pad_00[0x4a];
    u8 state;
};

u32 GFL_NET_IsHandleReady(struct NetEntry *e)
{
    return e->state == 5;
}
