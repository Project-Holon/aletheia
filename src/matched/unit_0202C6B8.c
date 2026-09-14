/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C6B8
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202C6B8, sub_0202C6BC
 *
 * Two plain functions, no relocations. sub_0202C6B8 reads the object's
 * first word; sub_0202C6BC sets it and clears the u16 field at offset 4.
 * sub_0202C6BC is the target of func_0202C6A0/func_0202C6AC
 * (src/matched/unit_0202C6A0.c) and of eight direct callers elsewhere in
 * the image.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C6B8.c \
 *       --addr 0x0202C6B8 --thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Obj0202C6B8 {
    u32 unk00;
    u16 unk04;
};

u32 sub_0202C6B8(struct Obj0202C6B8 *p)
{
    return p->unk00;
}

void sub_0202C6BC(struct Obj0202C6B8 *p, u32 v)
{
    p->unk00 = v;
    p->unk04 = 0;
}
