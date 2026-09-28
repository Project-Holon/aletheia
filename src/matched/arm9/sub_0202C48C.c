/*
 * unit:     no
 * function: sub_0202C48C
 * address:  0x0202C48C
 * packet:   pkt_0202C3A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202C510  0x0202C510  thumb
 *   sub_0202C560  0x0202C560  thumb
 *
 * One of the six blocked callers of the trampoline run at 0x0202C548, and
 * the single-slot form of src/matched/unit_0202C470.c: both arguments are
 * forwarded untouched, so nothing sets r1 and the prologue saves only lr
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * read the other way round: here the untouched r1 really is the second
 * argument, because the `bl` result is the next call's only argument).
 *
 * What closed it: sub_0202C560 is one of the seven trampolines of
 * src/matched/unit_0202C558.c, so the `matched` class witnesses the site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C48C.c \
 *       --func sub_0202C48C --addr 0x0202C48C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void *sub_0202C510(void *p, u32 idx);
extern void sub_0202C560(void *w);

void sub_0202C48C(void *p, u32 idx)
{
    sub_0202C560(sub_0202C510(p, idx));
}
