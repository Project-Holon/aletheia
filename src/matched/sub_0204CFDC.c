/*
 * unit:     no
 * function: sub_0204CFDC
 * address:  0x0204CFDC
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0204C8E4  0x0204C8E4  arm
 *   sub_0204D0C4  0x0204D0C4  arm
 *   sub_0204CED8  0x0204CED8  arm
 *   sub_0204CF40  0x0204CF40  arm
 *   sub_0204C98C  0x0204C98C  arm
 *   sub_0204B3DC  0x0204B3DC  arm
 *
 * Allocate one object out of the owner's pool, back-link it, initialise its
 * embedded sub-object at +0x68 from the request, apply the two field
 * groups, register it with the owner and enable it.
 *
 * Five of the six callees want the object pointer and two want the owner,
 * so both are pinned for the whole body; that is what forces the
 * five-callee-saved push.  The fifth argument is only read once, straight
 * out of this function's own stack slot at [sp, #0x18] (five pushed
 * registers plus lr above it), and never spilled.
 *
 * Was parked at MATCH.  Three of the six sites name functions whose only
 * branch site image-wide is the one here, so each needed its own EXACT
 * entry to act as a `matched` witness; all three now have one and the C in
 * this file is unchanged.
 *
 *   0x0204C8E4, the allocator, is src/matched/sub_0204C8E4.c.  Its own
 *     blocker was the GF_ASSERT expression string, folded onto the
 *     file-name symbol
 *     (docs/idioms/an-assert-expression-string-rides-the-file-name-symbol.md).
 *   0x0204D0C4, the sub-object initialiser, is src/matched/sub_0204D0C4.c.
 *     Its handler table 0x020A13DC is row 6 of the array based at
 *     0x020A1394, not a symbol of its own.
 *   0x0204CF40 is src/matched/sub_0204CF40.c, which unstuck once
 *     0x0204B728 landed (one `const` on a struct assignment's source).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CFDC.c \
 *       --func sub_0204CFDC --addr 0x0204CFDC --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub {
    u8 unk_00[1];
};

struct Obj {
    u8          pad_00[8];
    void       *owner;
    u8          pad_0c[0x5c];
    struct Sub  unk_68;
};

struct Req {
    u8 unk_00[1];
};

extern struct Obj *sub_0204C8E4(void *owner);
extern void sub_0204D0C4(struct Sub *s, void *c, u16 e);
extern void sub_0204CED8(struct Obj *o, struct Req *r, void *d);
extern void sub_0204CF40(struct Obj *o, void *c);
extern void sub_0204C98C(void *owner, struct Obj *o);
extern void sub_0204B3DC(struct Obj *o, u32 enable);

struct Obj *sub_0204CFDC(void *owner, struct Req *r, void *c, void *d, u16 e)
{
    struct Obj *o = sub_0204C8E4(owner);

    o->owner = owner;
    sub_0204D0C4(&o->unk_68, c, e);
    sub_0204CED8(o, r, d);
    sub_0204CF40(o, c);
    sub_0204C98C(owner, o);
    sub_0204B3DC(o, 1);
    return o;
}
