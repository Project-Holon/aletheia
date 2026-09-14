/*
 * unit:     no
 * function: sub_0202C510
 * address:  0x0202C510
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A single accessor: indexes a u32 array at offset 0x18, unchecked. Sits
 * isolated between two branchy neighbours (sub_0202C504 before,
 * sub_0202C518 after), so it is its own file rather than part of a unit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_0202C510.c \
 *       --func sub_0202C510 --addr 0x0202C510 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Arr0202C510 {
    u8 pad[0x18];
    u32 unk18[1];
};

u32 sub_0202C510(struct Arr0202C510 *p, u32 idx)
{
    return p->unk18[idx];
}
