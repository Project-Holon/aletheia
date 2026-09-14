/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_020124E4, sub_020124E8, sub_020124EC, sub_020124F0
 * address:  0x020124E4
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four two-byte leaf accessors in a row on the same object.  None of them
 * saves lr, so disasm.py labels none of them and the whole run prints as a
 * `.byte` blob between two pools; they are only reachable by sweeping
 * addresses.  sub_020124EC returns the address of the embedded sub-object
 * at +8 rather than a stored pointer.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020124E4.c \
 *       --addr 0x020124E4 --thumb
 */

typedef unsigned int u32;

struct Obj {
    void *unk_00;
    u32  unk_04;
    u32  unk_08;
    void *unk_0c;
    void *unk_10;
};

void *sub_020124E4(struct Obj *p)
{
    return p->unk_10;
}

void *sub_020124E8(struct Obj *p)
{
    return p->unk_0c;
}

u32 *sub_020124EC(struct Obj *p)
{
    return &p->unk_08;
}

void *sub_020124F0(struct Obj *p)
{
    return p->unk_00;
}
