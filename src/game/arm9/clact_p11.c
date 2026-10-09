/*
 * file:     clact_p11.c
 * unit:     yes
 * function: sub_0204D478, func_0204D494, func_0204D4A4, sub_0204D4B4, sub_0204D4C4, sub_0204D500, func_0204D510, func_0204D52C, func_0204D53C, func_0204D54C
 * address:  0x0204D478
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
 *   gUnk_020A1394  0x020A1394  data
 *   func_02064384  0x02064384  arm
 *   sub_02064AB4  0x02064AB4  arm
 *   gUnk_020A7F3C  0x020A7F3C  data
 *   sub_020643C4   0x020643C4  arm
 *   sub_02064B68  0x02064B68  arm
 *   g_DispatchTable_0204D510  0x020A7F48  data
 *   func_020643A4  0x020643A4  arm
 */
struct CellAnim;
struct MultiCellAnim;
struct Obj02064C10;
typedef unsigned int u32;

struct Obj0204D478 {
    u32 kind;
};

typedef void *(*DispatchFn_0204D478)(struct Obj0204D478 *o, u32 arg);

typedef unsigned char  u8;

struct Obj0204D4B4 {
    u32 kind;
    u8  pad_04[8];
    u8  unk_0c;
};

struct Obj {
    u32 type;
    u8  pad_04[8];
    u8  unk_0c;
};

typedef void (*DispatchFn_0204D4C4)(struct Obj *o, u32 arg);

struct Ctl {
    u32 mode;  /* 0x00 */
};

typedef void (*Handler)(struct Ctl *c);

extern void func_02064384(struct CellAnim *anim, u32 i);
extern void sub_02064AB4(char *self, unsigned int i);
extern void sub_020643C4(struct MultiCellAnim *mca, u32 value);
extern void sub_02064B68(struct Obj *o, void *arg);
extern void func_020643A4(struct CellAnim *anim);
extern void func_02064C10(struct Obj02064C10 *x);
void *sub_0204D478(struct Obj0204D478 *o, u32 arg);
void func_0204D494(u8 *a0, u32 i);
void func_0204D4A4(u8 *a0, u32 i);
void sub_0204D4B4(struct Obj0204D4B4 *o, u32 i);
void sub_0204D4C4(struct Obj *o, u32 arg);
void sub_0204D4E0(struct Obj *o, u32 arg);
void sub_0204D4F0(struct Obj *o, u32 arg);
void sub_0204D500(struct Obj *o, u32 arg);
void func_0204D510(struct Ctl *c);
void func_0204D52C(void *p);
void func_0204D53C(u8 *a0);
void func_0204D54C(void *p);
extern DispatchFn_0204D478 const gUnk_020A1394[][3];
extern DispatchFn_0204D4C4 const gUnk_020A7F3C[];
extern Handler g_DispatchTable_0204D510[];








/*
 * Row 0 of the eight-by-three handler table at 0x020A1394, the same shape as
 * src/matched/unit_0204D410.c (row 7), src/matched/unit_0204D444.c (row 1)
 * and src/matched/func_0204D324.c (row 3, and the row map).  Every concrete
 * byte is reproduced; the single unresolved site is the ABS32 in the pool.
 *
 * Blocked on: evidence class `literal`, and it can never be satisfied.  For
 * rows 1, 3, 5, 6 and 7 the pool word is base+0x0c..base+0x54, so some other
 * row's thunk holds a different word and the base is witnessed from outside.
 * Row 0's pool word *is* the array base, 0x020A1394, and `--suggest-split`
 * reports exactly one witness image-wide: this function's own relocation site
 * at 0x0204D490.  Self-reference is refused, so no cut can free it.  It would
 * become EXACT only if some future matched entry defines the table data at
 * 0x020A1394, or if a caller elsewhere is found that pools the bare base.
 *
 * The arity comes from the register pair, not from the call: the original
 * takes the kind in r3 and the table base in r2, which is the two-parameter
 * allocation (compare src/matched/func_0204D324.c).  The one-parameter
 * spelling allocates r2 then r1 and is a four-instruction diff.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D478.c \
 *       --func sub_0204D478 --addr 0x0204D478 --cc 1.1p1 --arm
 */
void *sub_0204D478(struct Obj0204D478 *o, u32 arg)
{
    return gUnk_020A1394[0][o->kind](o, arg);
}








/*
 * Two identical tail calls to the same callee with the argument biased by
 * 0xc.  Unlabelled leaves; the range 0x0204D494..0x0204D4B4 is contiguous.
 */
void func_0204D494(u8 *a0, u32 i)
{
    func_02064384((struct CellAnim *)(a0 + 0xc), i);
}








void func_0204D4A4(u8 *a0, u32 i)
{
    func_02064384((struct CellAnim *)(a0 + 0xc), i);
}







/*
 * note:     promoted 2026-09-21: the blocker named below, 0x02064AB4, was
 *           filed EXACT as src/matched/func_02064AB4.c (pin ../2.0/sp2) by the
 *           pkt_02064934 lane, so the sole ABS32 site now resolves `matched`.
 *
 * The third row-0 handler of the table at 0x020A1394 (row map in
 * src/matched/func_0204D324.c).  Same shape as the two in
 * src/matched/unit_0204D494.c, tail calling the +0xc subobject through a pool
 * word, but to a different target.  It saves nothing, so disasm.py gives it
 * no label.
 *
 * Was blocked on: no evidence class at all.  `--suggest-split` reported zero
 * witnesses image-wide for 0x02064AB4: nothing branches to it (so no `label`),
 * no other pool holds the word (so no `literal`), and it is inside the G2D
 * block that has no matched entry yet.  The address is reachable only through
 * this table row, which is why it never appears as a branch target.  It will
 * resolve as `matched` once the G2D function at 0x02064AB4 is decompiled, or
 * as `label` if an overlay turns out to call it directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D4B4.c \
 *       --func sub_0204D4B4 --addr 0x0204D4B4 --cc 1.1p1 --arm
 */
void sub_0204D4B4(struct Obj0204D4B4 *o, u32 i)
{
    sub_02064AB4((char *)(&o->unk_0c), i);
}






/*
 * A dispatch thunk and the first two of the three handlers its table row
 * names, 60 bytes end to end.  Each handler steps the pointer past the
 * object's 0xc-byte header and tail-calls into the G2D layer; a tail call
 * is always a pool word and a `bx`, never a displacement branch, because
 * every function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The handlers save
 * nothing, so disasm.py gives them no labels; they are folded in here
 * rather than left as this thunk's `EXACT*` tail.
 *
 * The thunk forwards two arguments, not one: it allocates r3 then r2 for
 * the table load, leaving r1 alone, where the one-argument form in
 * src/matched/unit_0204D410.c allocates r2 then r1
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * The third handler, sub_0204D500 at 0x0204D500, is deliberately left out
 * of the range: its tail-call target 0x02064B68 is named only by its own
 * pool word, so including it caps the whole unit at MATCH.  It is parked
 * byte-correct in src/pending/sub_0204D500.c, and it graduates when
 * 0x02064B68 does (docs/notes/sub_02064B68.c.txt).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D4C4.c \
 *       --addr 0x0204D4C4 --arm
 */
void sub_0204D4C4(struct Obj *o, u32 arg)
{
    gUnk_020A7F3C[o->type](o, arg);
}






void sub_0204D4E0(struct Obj *o, u32 arg)
{
    sub_020643C4((struct MultiCellAnim *)(&o->unk_0c), arg);
}






void sub_0204D4F0(struct Obj *o, u32 arg)
{
    sub_020643C4((struct MultiCellAnim *)(&o->unk_0c), arg);
}





/*
 * The third handler of the row that src/matched/unit_0204D4C4.c dispatches
 * through: step the pointer past the object's 0xc-byte header and tail-call
 * into the G2D layer, forwarding the second argument untouched.
 *
 * Byte-correct, capped at MATCH.  The tail call is a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), so the site is an ABS32
 * naming 0x02064B68, and that address is named by no other pool word and by
 * no branch anywhere in the image: `label`, `literal` and `veneer` all have
 * nothing outside this range.  The one route left is an EXACT entry for
 * 0x02064B68 itself acting as a `matched` witness; that function is a
 * 168-byte two-armed cell/node walk which is four transposed instructions
 * away from matching, recorded in docs/notes/sub_02064B68.c.txt.
 *
 * Kept out of unit_0204D4C4.c for exactly this reason: folding it back in
 * would cap that whole range at MATCH for one unattestable word.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D500.c \
 *       --func sub_0204D500 --addr 0x0204D500 --cc 1.1p1 --arm
 */
void sub_0204D500(struct Obj *o, u32 arg)
{
    sub_02064B68((struct Obj *)(&o->unk_0c), (void *)arg);
}





/*
 * Closes the clact.c fan-in-1 blocker documented in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt: func_0204B9A0 (its only
 * caller image wide) forwards its argument unchanged.
 *
 * Dispatch through a function-pointer table indexed by the mode word at
 * +0x00 of the argument; the call itself is an indirect `blx` (no PC24
 * relocation to attest), but the table base at 0x020A7F48 is an ABS32
 * literal with no second reference anywhere in the ARM9 image, so this
 * stays MATCH regardless of the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204D510.c \
 *       --func func_0204D510 --addr 0x0204D510 --cc 1.1p1 --arm
 */
void func_0204D510(struct Ctl *c)
{
    g_DispatchTable_0204D510[c->mode](c);
}




void func_0204D52C(void *p){ func_020643A4((struct CellAnim *)((char *)p + 0xc)); }



/*
 * The same 0xc-biased tail call to the other callee of the pair.
 */
void func_0204D53C(u8 *a0)
{
    func_020643A4((struct CellAnim *)(a0 + 0xc));
}


/*
 * Tear the actor down and release the sub-object at +0x40: func_0204D52C on
 * the actor itself, then func_02064C10 on the tail.
 *
 * Both call sites resolve from `matched` witnesses, which is what this file
 * waited for while it sat parked in src/pending/ with both PC24s wildcarded.
 * The trailing star is the listing extent only: the next func_ label after
 * 0x0204D54C is 540 bytes away, so the harness compares the 32 bytes this
 * body compiles to and reports the disagreement rather than a concrete diff.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D54C.c \
 *       --func func_0204D54C --addr 0x0204D54C --cc 1.1p1 --arm
 */
void func_0204D54C(void *p)
{
    func_0204D52C(p);
    func_02064C10((struct Obj02064C10 *)((u8 *)p + 0x40));
}
