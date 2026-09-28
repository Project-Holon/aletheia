/*
 * unit:     no
 * function: sub_0202E794
 * address:  0x0202E794
 * packet:   pkt_0202E770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * A pool-word-and-bx tail call into the ARM deallocator
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): eight bytes, no
 * prologue, no label in the listing. The destructor half of the
 * constructor at 0x0202E770, which allocates the same object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202E794.c \
 *       --func sub_0202E794 --addr 0x0202E794 --cc 1.1p1 --thumb
 */

extern void func_020307B0(void *p);

void sub_0202E794(void *p)
{
    func_020307B0(p);
}
