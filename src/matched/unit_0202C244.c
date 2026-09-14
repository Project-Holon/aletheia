/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C244
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202C244, sub_0202C24C
 *
 * Two plain accessors on the same object, no relocations. sub_0202C244
 * indexes a pointer table held at offset 8 (unchecked, `lsls #2` then
 * `ldr`); sub_0202C24C reads back the word at offset 0xc. Both are called
 * repeatedly through the rest of this file's own packet.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C244.c \
 *       --addr 0x0202C244 --thumb
 */

typedef unsigned int u32;

struct Obj0202C244 {
    u32 unk00;
    u32 unk04;
    u32 *unk08;
    u32 unk0c;
};

u32 sub_0202C244(struct Obj0202C244 *p, u32 idx)
{
    return p->unk08[idx];
}

u32 sub_0202C24C(struct Obj0202C244 *p)
{
    return p->unk0c;
}
