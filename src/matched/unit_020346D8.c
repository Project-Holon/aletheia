/*
 * function: sub_020346D8
 * address:  0x020346D8
 * packet:   pkt_020345F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A plain multiply-add accessor: two u16 fields of `a` combine with one
 * u32 read through `b` (itself dereferenced once) as `*b * a->unk04 +
 * a->unk06`. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_020346D8.c \
 *       --func sub_020346D8 --addr 0x020346D8 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Item020346D8 {
    u16 pad0;
    u16 pad2;
    u16 unk04;
    u16 unk06;
};

u32 sub_020346D8(struct Item020346D8 *a, u32 *b)
{
    return *b * a->unk04 + a->unk06;
}
