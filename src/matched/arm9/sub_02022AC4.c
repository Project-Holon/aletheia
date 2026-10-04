/*
 * function: sub_02022AC4
 * address:  0x02022AC4
 * packet:   pkt_02022AC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Re-verified 2026-09-23: the MATCH park had turned DIFF (one byte) under
 * the new extents because its header named the callee 0x020202CC.  The
 * pool word at 0x02022ACC is 0x020222CD: the callee is 0x020222CC
 * (src/matched/func_020222CC.c, labelled with sixteen outside branches),
 * so the old "unlabelled leaf, sole reference" blocker was a digit slip.
 * With the address corrected the site resolves `label` and the file is
 * EXACT.
 *
 * symbols:
 *   sub_020222CC  0x020222CC  thumb
 *
 * An unlabelled leaf forwarder: it drops its own first argument and calls
 * sub_020222CC with the two pointer fields at +0x18 and +0x1c of its
 * second.  The ordinary tail-call form, a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02022AC4.c \
 *       --func sub_02022AC4 --addr 0x02022AC4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void sub_020222CC(u32 which, int brightness);

void sub_02022AC4(void *unused, u8 *o)
{
    sub_020222CC((u32)(*(void **)(o + 0x18)), (int)(*(void **)(o + 0x1c)));
}
