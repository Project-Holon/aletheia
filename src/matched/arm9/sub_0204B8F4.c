/*
 * function: sub_0204B8F4
 * address:  0x0204B8F4
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0204D444   0x0204D444  arm
 *
 * Read +0x10 of the record sub_0204D444 hands back for the sub-object
 * embedded at +0x68 of the 0x0204Bxxx object (see
 * src/matched/unit_0204B898.c for the family).  The call result is
 * dereferenced in place, so no register is spent copying it
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * EXACT*: the byte comparison passes, but the follower at 0x0204B908
 * saves no lr, so disasm.py never labelled it and the inferred extent
 * runs past the end of this function.  0x0204B908 wants seeding into
 * layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B8F4.c \
 *       --func sub_0204B8F4 --addr 0x0204B8F4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u8 unk_00[1];
};

struct Node {
    u8  pad_00[0xc];
    u32 unk_0c;
    u32 unk_10;
};

struct Obj {
    u8         pad_00[0x68];
    struct Sub unk_68;
};

extern struct Node *sub_0204D444(struct Obj *o);

u32 sub_0204B8F4(struct Obj *p)
{
    return sub_0204D444((struct Obj *)(&p->unk_68))->unk_10;
}
