/*
 * function: sub_0200F7B8
 * address:  0x0200F7B8
 * packet:   pkt_0200F6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0200FC0C  0x0200FC0C  thumb
 *
 * A four-byte tail call: no prologue at all, just a pool word and bx. See
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md. func_0200FC0C is called
 * from exactly this one site in the whole ROM, so the relocation stays
 * unresolved under the honesty rule; the byte match is exact.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F7B8.c \
 *       --func sub_0200F7B8 --addr 0x0200F7B8 --cc 1.1p1
 *
 * The `matched` class does not reach it: func_0200FC0C is not matched, so no
 * EXACT entry covers that address.
 */

extern void func_0200FC0C(unsigned int arg);

void sub_0200F7B8(unsigned int arg)
{
    func_0200FC0C(arg);
}
