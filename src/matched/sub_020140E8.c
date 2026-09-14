/*
 * function: sub_020140E8
 * address:  0x020140E8
 * packet:   pkt_02013ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain range test on the raw id, called by sub_0201407C
 * (unit_02013ED8.c is a sibling file, not this one; the call there is
 * attested by this function's own definition living outside its range).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020140E8.c \
 *       --func sub_020140E8 --addr 0x020140E8 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

u32 sub_020140E8(u32 x)
{
    return x >= 2 && x < 0xD2;
}
