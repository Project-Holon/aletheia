/*
 * function: sub_02014264
 * address:  0x02014264
 * packet:   pkt_02014264
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02014204  0x02014204  thumb
 *
 * A one-line forwarder: func_02014204 with its second argument pinned to
 * 0x187.  This IS compiled C, not a linker veneer: an ARM long-branch
 * veneer never materialises an argument, and the four-byte-ARM-veneer shape
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md)
 * does not apply -- this is six bytes of Thumb plus two pool words, the
 * ordinary tail-call form
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The constant lands in
 * a pool rather than a `movs` because 0x187 is out of the Thumb immediate
 * range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02014264.c \
 *       --func sub_02014264 --addr 0x02014264 --cc 1.1p1 --thumb
 */

extern void func_02014204(void *p, int id);

void sub_02014264(void *p)
{
    func_02014204(p, 0x187);
}
