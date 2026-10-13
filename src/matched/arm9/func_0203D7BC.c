/*
 * function: func_0203D7BC
 * address:  0x0203D7BC
 * packet:   pkt_0203D7B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A long-branch veneer pair with GFL_NET_SetAutoExit: the image spells both as
 * `ldr ip, [pc]; bx ip; .word target`, which this compiler emits for a
 * tail call to an ARM callee whose address must come from a pool.
 *
 * The ABS32 at +0008 resolves through sole-ref/code: 0x0203C900 is a
 * traced ARM function start (its prologue saves lr, so disasm.py labelled
 * it), and sole-ref/code accepts an exact label start without requiring a
 * second referrer.  Its neighbour GFL_NET_SetAutoExit is NOT filable the same
 * way -- 0x0203C8E8 opens with a bare `ldr` and saves no lr, so disasm.py
 * never labelled it and no class can carry the site.  That is why these
 * two 12-byte twins are in different directories.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0203D7BC.c \
 *       --func func_0203D7BC --addr 0x0203D7BC --cc 1.1p1 --arm
 *
 * symbols:
 *   GFL_NET_STATE_SetLoginOption  0x0203C900  arm
 */

typedef unsigned char  u8;
extern void GFL_NET_STATE_SetLoginOption(u8 v);

void func_0203D7BC(u8 a0)
{
    GFL_NET_STATE_SetLoginOption(a0);
}
