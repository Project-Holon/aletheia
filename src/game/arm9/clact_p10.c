/*
 * file:     clact_p10.c
 * unit:     yes
 * function: func_0204CF74, func_0204CFA4, func_0204CFDC
 * address:  0x0204CF74
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0204B0C8  0x0204B0C8  arm
 *   sub_0204C8E4  0x0204C8E4  arm
 *   sub_0204D0C4  0x0204D0C4  arm
 *   sub_0204CED8  0x0204CED8  arm
 *   sub_0204CF40  0x0204CF40  arm
 *   sub_0204C98C  0x0204C98C  arm
 *   sub_0204B3DC  0x0204B3DC  arm
 */
struct Owner;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Pt {
    signed short x;
    signed short y;
};

struct Inner {
    u8    pad_00[8];
    void *unk_08;
};

struct Obj_0204CF74 {
    u8            pad_00[8];
    struct Inner *unk_08;
};

struct Req_0204CFA4 {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
};

struct Sub {
    u8 unk_00[1];
};

struct Obj_0204CFDC {
    u8          pad_00[8];
    void       *owner;
    u8          pad_0c[0x5c];
    struct Sub  unk_68;
};

struct Req_0204CFDC {
    u8 unk_00[1];
};

extern void sub_0204B0C8(struct Owner *src, u32 id, struct Pt *out);
extern struct Obj_0204CFDC *sub_0204C8E4(struct Owner *ow);
extern void sub_0204D0C4(struct Sub *s, void *c, u32 e);
extern void sub_0204CED8(struct Obj_0204CFDC *o, const struct Req_0204CFDC *r, u32 space);
extern void sub_0204CF40(struct Obj_0204CFDC *o, const struct Req_0204CFDC *r);
extern void sub_0204C98C(void *owner, struct Obj_0204CFDC *o);
extern void sub_0204B3DC(struct Obj_0204CFDC *o, u32 enable);


/*
 * Measure entry `id`, writing the two halfwords of the answer through
 * `out`.  The sentinel id 0xFFFF means "nothing", and zeroes both.
 *
 * 0xFFFF costs a pool word because it is not an ARM rotated immediate
 * (docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md is the
 * same constraint on the other side of the comparison).  The whole early
 * return is predicated: one `moveq` feeding two `strheq` and a `popeq`,
 * with no branch anywhere.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CF74.c \
 *       --func sub_0204CF74 --addr 0x0204CF74 --cc 1.1p1 --arm
 */
void sub_0204CF74(struct Obj_0204CF74 *o, u32 id, u16 *out)
{
    if (id == 0xFFFF) {
        out[0] = 0;
        out[1] = 0;
        return;
    }
    sub_0204B0C8((struct Owner *)o->unk_08->unk_08, id, (struct Pt *)out);
}


/*
 * The seven-argument initialiser for the 0x20-byte request record: four
 * arguments arrive in registers, three more off the caller's stack, and the
 * last three words of the record are cleared.
 *
 * The four-register push is not about callee-saved state, it is the cost of
 * having three stack arguments to stage; [sp, #0x10] is the first of them,
 * sixteen bytes past the pushed frame.  `stmib r0, {r3, r5}` is the
 * compiler folding the +4 and +8 stores once both values happen to sit in
 * ascending registers, not a struct copy
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md describes the other case).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CFA4.c \
 *       --func sub_0204CFA4 --addr 0x0204CFA4 --cc 1.1p1 --arm
 */
void sub_0204CFA4(struct Req_0204CFA4 *r, u16 a, u16 b, u32 c, u32 d, u32 e, u32 f)
{
    r->unk_00 = a;
    r->unk_02 = b;
    r->unk_04 = c;
    r->unk_08 = d;
    r->unk_0c = e;
    r->unk_10 = f;
    r->unk_14 = 0;
    r->unk_18 = 0;
    r->unk_1c = 0;
}


/*
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
struct Obj_0204CFDC *sub_0204CFDC(void *owner, const struct Req_0204CFDC *r, void *c, u32 space, u16 e)
{
    struct Obj_0204CFDC *o = sub_0204C8E4(owner);

    o->owner = owner;
    sub_0204D0C4(&o->unk_68, c, e);
    sub_0204CED8(o, r, space);
    sub_0204CF40(o, c);
    sub_0204C98C(owner, o);
    sub_0204B3DC(o, 1);
    return o;
}
