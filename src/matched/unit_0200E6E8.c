/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E6E8
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200E6E8, sub_0200E6F0
 *
 * symbols:
 *   sub_020071CC  0x020071CC  thumb
 *
 * alias: a two-hop tail-call chain. sub_0200E6E8 is a pure forwarder to
 * sub_0200E6F0, which itself tail calls sub_020071CC with a fixed id of
 * 0x3e; both pass their argument through unchanged. Neither carries a
 * register-saving prologue, so disasm.py's sweep does not label
 * sub_0200E6F0 and it prints as data between the two literal pools; see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md and
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E6E8.c \
 *       --addr 0x0200E6E8 --thumb
 */

typedef unsigned int u32;

extern void *sub_0200E6F0(u32 a);
extern void *sub_020071CC(u32 a, u32 id);

void *sub_0200E6E8(u32 a)
{
    return sub_0200E6F0(a);
}

void *sub_0200E6F0(u32 a)
{
    return sub_020071CC(a, 0x3e);
}
