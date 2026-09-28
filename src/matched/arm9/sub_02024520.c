/*
 * function: sub_02024520
 * address:  0x02024520
 * packet:   pkt_02024344
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain bitmask, `& 0x7FF`. Immediately followed by two unlabelled
 * one-argument halfword accessors (`ldrh r0,[r0]`/`bx lr` and
 * `ldrh r0,[r0,#2]`/`bx lr`) that carry no push prologue and so are
 * invisible to disasm.py's sweep; not reproduced here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02024520.c \
 *       --func sub_02024520 --addr 0x02024520 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

u32 sub_02024520(u32 x)
{
    return x & 0x7FF;
}
