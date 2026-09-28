/*
 * A whole translation unit range, matched as one byte range.
 *
 * unit:     yes
 * function: sub_0204B898, sub_0204B8A0
 * address:  0x0204B898
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0204B878   0x0204B878  arm
 *   sub_0204B95C   0x0204B95C  arm
 *
 * Two members of the interface of the object whose flag word sits at
 * +0x60 (see src/matched/unit_0204B3DC.c and unit_0204B92C.c).  The state
 * this corner of the file owns is the u16 at +0x5a:
 *
 *   sub_0204B898  read it.  Saves no lr, so disasm.py never labels it.
 *   sub_0204B8A0  the guarded write: do nothing when the value is
 *                 unchanged, otherwise hand it to sub_0204B878 (which
 *                 stores it and pushes it down into the 0x0204Dxxx layer)
 *                 and re-run sub_0204B95C on top.
 *
 * The `cmp r1, r2` operand order is the tell that the incoming value is
 * the left operand of the comparison and the field the right one
 * (docs/idioms/cmp-operand-order-names-the-temporary.md), so the guard is
 * written `v == p->unk_5a`, not the other way round.
 *
 * This is a cut out of a larger file: the neighbouring functions
 * 0x0204B8C4, 0x0204B8D4, 0x0204B908 and 0x0204B918 are all byte-correct
 * but each calls a 0x0204Dxxx (or, for 0x0204B918, an 0x02062F1C) entry
 * point that has no caller anywhere else in the image, so they are capped
 * at MATCH and parked in src/pending/, next to the 0x0204B878 that an
 * earlier wave parked there for the same reason.  0x0204B8F4,
 * the other clean one, is in src/matched/sub_0204B8F4.c; it is not
 * contiguous with this pair.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B898.c \
 *       --addr 0x0204B898 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Sub {
    u8 unk_00[1];
};

struct Obj {
    u8         pad_00[0x5a];
    u16        unk_5a;
    u8         pad_5c[0xc];
    struct Sub unk_68;
};

extern void sub_0204B878(struct Obj *p, u16 v);
extern void sub_0204B95C(struct Obj *p);

u16 sub_0204B898(struct Obj *p)
{
    return p->unk_5a;
}

void sub_0204B8A0(struct Obj *p, u16 v)
{
    if (v == p->unk_5a) {
        return;
    }
    sub_0204B878(p, v);
    sub_0204B95C(p);
}
