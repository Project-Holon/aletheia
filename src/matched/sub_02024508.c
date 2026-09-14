/*
 * function: sub_02024508
 * address:  0x02024508
 * packet:   pkt_02024344
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A sentinel-guarded bit test: 0xFFFF is treated as "unset" and reads as
 * bit 0, everything else reads back bit 11.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02024508.c \
 *       --func sub_02024508 --addr 0x02024508 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef int           s32;

u32 sub_02024508(u32 x)
{
    if (x == 0xFFFF) {
        return 0;
    }
    return ((s32)x >> 11) & 1;
}
