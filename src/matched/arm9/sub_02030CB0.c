/*
 * unit:     no
 * address:  0x02030CB0
 * packet:   pkt_02030BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030CB0
 *
 * Index-to-offset arithmetic: a fixed 0x38-byte header plus 0x20 bytes per
 * element. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030CB0.c \
 *       --func sub_02030CB0 --addr 0x02030CB0 --cc 1.1p1
 */

typedef unsigned int u32;

u32 sub_02030CB0(u32 idx)
{
    return (idx << 5) + 0x38;
}
