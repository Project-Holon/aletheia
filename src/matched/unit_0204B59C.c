/*
 * unit:     yes
 * function: sub_0204B59C
 * address:  0x0204B59C
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0204B59C  0x0204B59C  arm
 *   sub_0204B5AC  0x0204B5AC  arm
 *   sub_0204B5C0  0x0204B5C0  arm
 *
 * Three leaf accessors on the display object, 56 bytes end to end with no
 * padding.  Only the first carries a label in the listing: the other two
 * save nothing and so are invisible to disasm.py's prologue rule
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They are
 * folded into one unit here rather than three files, which also makes the
 * range self-contained: the unit has no relocation sites at all.
 *
 * sub_0204B59C selects between the +0x10 and +0x12 halfwords on a flag; the
 * front end if-converts it to a `strheq`/`strhne` pair with no branch, and
 * the `eq` arm being first is the source order of the `if`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0204B5AC and sub_0204B5C0 are the setter and getter for the 8-byte
 * pair at +0x14.  Both words are loaded before either is stored, which is
 * what two independent field assignments give when neither store can be
 * proved to feed the following load; writing them as one 8-byte struct
 * assignment is the same code.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B59C.c \
 *       --addr 0x0204B59C --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u8  pad_00[0x10];
    u16 unk_10;
    u16 unk_12;
    u32 unk_14;
    u32 unk_18;
};

struct Pair {
    u32 x;
    u32 y;
};

void sub_0204B59C(struct Obj *o, u16 v, u32 sel)
{
    if (sel == 0) {
        o->unk_10 = v;
    } else {
        o->unk_12 = v;
    }
}

void sub_0204B5AC(struct Obj *o, const struct Pair *p)
{
    o->unk_14 = p->x;
    o->unk_18 = p->y;
}

void sub_0204B5C0(const struct Obj *o, struct Pair *p)
{
    p->x = o->unk_14;
    p->y = o->unk_18;
}
