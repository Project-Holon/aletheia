/*
 * unit:     no
 * function: sub_0202C548
 * address:  0x0202C548
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_SWITCH_Free  0x0202C5AC  thumb
 *
 * The first of the nine pool-word-and-bx tail calls at 0x0202C548
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), 8 bytes each with no
 * gap. It stands alone rather than opening a unit because
 * src/matched/sub_0202C550.c was split out of the run ahead of it to
 * witness sub_0202C3E0's call site, and a unit is a contiguous byte
 * range; the remaining seven are src/matched/unit_0202C558.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C548.c \
 *       --func sub_0202C548 --addr 0x0202C548 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 ISS_SWITCH_Free(void *p);

u32 sub_0202C548(void *p)
{
    return ISS_SWITCH_Free(p);
}
