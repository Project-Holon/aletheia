/*
 * function: sub_02022AC4
 * address:  0x02022AC4
 * packet:   pkt_02022AC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  label/matched. 0x020202CC is an unlabelled leaf (disasm.py traces
 *           no func_ there because it saves no lr), and the pool word at
 *           0x02022ACC is the only reference to it anywhere in the image, so
 *           it is inside this function's own compared range.  Every concrete
 *           byte is correct; decompiling 0x020202CC to EXACT, or a second
 *           caller of it, unsticks this.
 *
 * symbols:
 *   sub_020202CC  0x020202CC  thumb
 *
 * An unlabelled leaf forwarder: it drops its own first argument and calls
 * sub_020202CC with the two pointer fields at +0x18 and +0x1c of its
 * second.  The ordinary tail-call form, a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02022AC4.c \
 *       --func sub_02022AC4 --addr 0x02022AC4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

extern void sub_020202CC(void *a, void *b);

void sub_02022AC4(void *unused, u8 *o)
{
    sub_020202CC(*(void **)(o + 0x18), *(void **)(o + 0x1c));
}
