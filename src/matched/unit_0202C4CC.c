/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C4CC
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202C4CC, sub_0202C4D0
 *
 * Two accessors, no relocations. sub_0202C4CC reads a byte at offset 0x16;
 * sub_0202C4D0 indexes a u16 array at offset 4 (unchecked).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C4CC.c \
 *       --addr 0x0202C4CC --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj0202C4CC {
    u8 pad[0x16];
    u8 unk16;
};

u32 sub_0202C4CC(struct Obj0202C4CC *p)
{
    return p->unk16;
}

struct Arr0202C4D0 {
    u8 pad[4];
    u16 unk04[1];
};

u32 sub_0202C4D0(struct Arr0202C4D0 *p, u32 idx)
{
    return p->unk04[idx];
}
