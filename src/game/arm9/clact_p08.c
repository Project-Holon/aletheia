/*
 * file:     clact_p08.c
 * unit:     yes
 * function: func_0204D134, func_0204D158, func_0204D18C, func_0204D224, func_0204D2C8, func_0204D2DC, func_0204D300, func_0204D324, func_0204D340, func_0204D360, func_0204D380, sub_0204D3A0
 * address:  0x0204D134
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
 *   sub_020627D8  0x020627D8  arm
 *   sub_0206428C  0x0206428C  arm
 *   func_02066AE0  0x02066AE0  arm
 *   func_020627D8  0x020627D8  arm
 *   func_020637B4  0x020637B4  arm
 *   func_020642C8  0x020642C8  arm
 *   s_clact_c      0x020A7F74  data
 *   func_020648B4  0x020648B4  arm
 *   func_02030734  0x02030734  arm
 *   func_02064754  0x02064754  arm
 *   func_0206469C  0x0206469C  arm
 *   sub_02082BCC   0x02082BCC  arm
 *   sub_02066B38  0x02066B38  arm
 *   sub_020307B0  0x020307B0  arm
 *   gUnk_020A1394  0x020A1394  data
 *   sub_0206434C  0x0206434C  arm
 *   sub_0206469C  0x0206469C  arm
 *   sub_0204D410  0x0204D410  arm
 *   sub_0204D3C4  0x0204D3C4  arm
 */
struct AnimBank;
struct AnimSequence;
struct Obj0206469C;
typedef unsigned char u8;

typedef signed int    s32;

struct Req {
    u8    pad_00[0x14];
    void *unk_14;
    u8    pad_18[4];
    void *unk_1c;
};

typedef unsigned int  u32;

struct Rec_0204D134 {
    u8 unk_00[1];
};

struct Src {
    u8    pad_00[0xc];
    void *unk_0c;
    void *unk_10;
};

struct Obj_0204D158 {
    u8         pad_00[4];
    void      *unk_04;
    void      *unk_08;
    struct Rec_0204D134 unk_0c;
};

struct P_0204D18C {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad_0c[0x64 - 0x0c];
    u32 f64;
};

struct A_0204D18C {
    u32 f00;
    u32 f04;
    u8  pad_08[4];
    u32 f0c;
    u32 f10;
    u8  pad_14[8];
    u32 f1c;
};

struct R {
    u8  pad_00[0x10];
    u32 f10;
    u32 f14;
};

struct P_0204D224 {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad_0c[0x70 - 0x0c];
    u32 f70;
    u32 f74;
    u32 f78;
};

struct A_0204D224 {
    u8  pad_00[0x0c];
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
};

typedef unsigned short u16;

struct Obj_0204D2DC {
    u8    pad_00[0x64];
    void *unk_64;
};

struct Obj_0204D300 {
    u8    pad_00[0x78];
    void *unk_78;
};

struct Obj0204D324 {
    u32 kind;
};

struct Obj_0204D340 {
    u8         pad_00[8];
    void      *unk_08;
    struct Rec_0204D134 unk_0c;
};

struct Obj_0204D360 {
    u8         pad_00[8];
    void      *unk_08;
    struct Rec_0204D134 unk_0c;
};

struct Obj_0204D380 {
    u8         pad_00[0xc];
    struct Rec_0204D134 unk_0c;
    u8         pad_0d[0x74 - 0xd];
    void      *unk_74;
};

struct Rec_0204D3A0 {
    u8   pad_00[0x10];
    u32  unk_10;
};

struct Obj {
    u8 unk_00[1];
};

extern struct AnimSequence *sub_020627D8(struct AnimBank *bank, u32 idx);
extern void sub_0206428C(char *self, int a1, char *c);
extern int func_02066AE0(void);
extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx);
extern int func_020637B4(int *p, int i);
extern void func_020642C8(char *self, int a1, char *c, int d, int e, int f, int g, int h, int i, int j);
extern int func_020648B4(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02064754(char *o, char *buf, void *set, int a3, void *bank, int kind);
extern void func_0206469C(struct Obj0206469C *o, void *bank);
extern void sub_02082BCC(void *dst, int value, u32 len);
extern void sub_02066B38(u32 idx);
extern u32 sub_020307B0(void *p);
extern void  sub_0206434C(struct Rec_0204D134 *r, void *v);
extern void sub_0206469C(struct Obj0206469C *o, void *bank);
extern struct Rec_0204D3A0 *sub_0204D410(struct Obj *o);
extern void *sub_0204D3C4(struct Obj *o, u32 arg);
s32 sub_0204D134(const struct Req *r);
void sub_0204D158(struct Obj_0204D158 *o, const struct Src *s);
void func_0204D18C(struct P_0204D18C *p, const struct A_0204D18C *a);
void func_0204D224(struct P_0204D224 *p, const struct A_0204D224 *a1, u32 heap);
void func_0204D2C8(void *anim);
void sub_0204D2DC(struct Obj_0204D2DC *o);
void sub_0204D300(struct Obj_0204D300 *o);
void func_0204D324(struct Obj0204D324 *obj, u32 arg);
void sub_0204D340(struct Obj_0204D340 *o, u32 idx);
void sub_0204D360(struct Obj_0204D360 *o, u32 idx);
void sub_0204D380(struct Obj_0204D380 *o, u32 idx);
void sub_0204D3A0(struct Obj *o, u32 value);
extern char s_clact_c[];



/*
 * Classify a request into the small index the sibling sub_0204D0C4 uses to
 * pick a handler out of its table: 1 if the pointer at +0x1c is set, else 2
 * if the one at +0x14 is, else 0.  A leaf with no prologue at all, so
 * disasm.py never labelled it.
 *
 * The first arm gets its own `bxne lr` while the last two share one exit as
 * a `movne`/`moveq` pair: that is what an early `return` followed by a
 * two-way tail looks like once the compiler has run out of conditional
 * slots to fold the first test into
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md
 * read in reverse, the result here is not initialised first).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D134.c \
 *       --func sub_0204D134 --addr 0x0204D134 --cc 1.1p1 --arm
 */
s32 sub_0204D134(const struct Req *r)
{
    if (r->unk_1c != 0) {
        return 1;
    }
    if (r->unk_14 != 0) {
        return 2;
    }
    return 0;
}



/*
 * Copy the source's two handles into the object's +4/+8 pair, then bind the
 * record at +0xc to them.
 *
 * The +4 field is read back from memory for sub_0206428C's third argument
 * rather than reused out of r2: the intervening call to sub_020627D8 could
 * alias it, so the cached load does not survive
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md, the case
 * without the `const`).
 *
 * sub_020627D8 is called here with an explicit zero in r1, where
 * src/matched/sub_0204D340.c leaves r1 untouched: the two call sites
 * disagree about the arity, and the zero is written out only because this
 * one needs it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D158.c \
 *       --func sub_0204D158 --addr 0x0204D158 --cc 1.1p1 --arm
 */
void sub_0204D158(struct Obj_0204D158 *o, const struct Src *s)
{
    o->unk_04 = s->unk_0c;
    o->unk_08 = s->unk_10;
    sub_0206428C((char *)(&o->unk_0c), (int)sub_020627D8(o->unk_08, 0), o->unk_04);
}



/*
 * Record builder in clact.c.  Wave 15 (register-tie lane): the last 10
 * bytes (the image sinks `mov sb, r0` above the two a->f0c/a->f10 loads)
 * close with `const struct A *a`.  The read-only source pointer lets the
 * parameter copy of p be scheduled before the loads, freeing r0 for the
 * stmib pair {r0, r1}.  The rest is the 2026-09-22 source from
 * docs/notes/pkt_0204D18C.func_0204D224.c.txt: the nested t1/t0 block
 * (descending loads) for the stmib, and `two - 3` for the -1 argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D18C.c \
 *       --func func_0204D18C --addr 0x0204D18C --cc 1.1p1 --arm
 */
void func_0204D18C(struct P_0204D18C *p, const struct A_0204D18C *a)
{
    u32 zero = 0;
    u32 two;
    u32 h0, h1, h2;
    struct R *r;

    {
        u32 t1 = a->f10;
        u32 t0 = a->f0c;
        p->f04 = t0;
        p->f08 = t1;
    }
    p->f64 = func_02066AE0();
    r = (struct R *)a->f1c;
    h0 = (u32)func_020627D8((struct AnimBank *)p->f08, zero);
    h1 = func_020637B4((int *)a->f04, 1);
    two = 2;
    h2 = func_020637B4((int *)a->f04, two);
    func_020642C8((char *)((u8 *)p + 0xc), h0, (char *)p->f04, p->f64,
                  two - 3, h1, h2, r->f14, zero, r->f10);
}



/*
 * Record constructor in clact.c.  Wave 15 (register-tie lane): EXACT* (the
 * listing extent runs over the unlabelled fill leaf 0x0204D2C8, filed as
 * src/matched/func_0204D2C8.c).  Two facts closed it:
 *  - the older 2-byte "best source" in
 *    docs/notes/pkt_0204D18C.func_0204D224.c.txt stored a1->f14 into +0x04
 *    and a1->f0c into +0x70, which is NOT what the image does (image: +0x04
 *    gets f0c, +0x70 gets f14).  The honest residue with the image's
 *    pairing was 9 bytes.
 *  - `const struct A *a1` with the four stores written straight from a1 and
 *    func_020648B4 fed a fresh a1->f14: the const source lets mwcc keep all
 *    four loads above the stores in field order and CSE the f14 re-read.
 *    The `volatile` device on +0x04 is no longer needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D224.c \
 *       --func func_0204D224 --addr 0x0204D224 --cc 1.1p1 --arm
 */
void func_0204D224(struct P_0204D224 *p, const struct A_0204D224 *a1, u32 heap)
{
    p->f04 = a1->f0c;
    p->f08 = a1->f10;
    p->f70 = a1->f14;
    p->f74 = a1->f18;

    p->f78 = (u32)func_02030734(heap, func_020648B4(a1->f14, 1), 0, s_clact_c, 0x171d);
    func_02064754((char *)((u8 *)p + 0xc), (char *)p->f78, (void *)p->f08, p->f04, (void *)p->f70, 1);
    func_0206469C((struct Obj0206469C *)((u8 *)p + 0xc), func_020627D8((struct AnimBank *)p->f74, 0));
}



/*
 * Unlabelled leaf after func_0204D224 in clact.c: clears the 0x7c-byte
 * animation sub-object (the same fill sub_0204D2DC ends with), as a tail
 * call.  Filed as the witness that turns func_0204D224's EXACT* into EXACT
 * once 0x0204D2C8 is seeded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D2C8.c \
 *       --func func_0204D2C8 --addr 0x0204D2C8 --cc 1.1p1 --arm
 */
void func_0204D2C8(void *anim)
{
    sub_02082BCC(anim, 0, 0x7c);
}



/*
 * Destructor for one variant of the 0x7c-byte 0x0204Cxxx/0x0204Dxxx
 * object: release the sub-resource whose handle lives at +0x64, then wipe
 * the whole record.  0x02082BCC is the SDK's byte fill (dest, value,
 * length); the 0x7c length is the object's own size, which the sibling
 * sub_0204D300 repeats verbatim for the +0x78 variant.
 *
 * Was capped at MATCH: the PC24 site at +0x0c names 0x02066B38 and this is
 * that address's only branch site anywhere in the image, so `label` has
 * nothing to point at and no split can create one from a single function.
 * 0x02066B38 is now EXACT in src/matched/sub_02066B38.c and the site
 * resolves `matched` against it.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D2DC.c \
 *       --func sub_0204D2DC --addr 0x0204D2DC --cc 1.1p1 --arm
 */
void sub_0204D2DC(struct Obj_0204D2DC *o)
{
    sub_02066B38((u32)o->unk_64);
    sub_02082BCC(o, 0, 0x7c);
}



/*
 * The sibling of sub_0204D2DC: same destructor shape for the variant whose
 * owned resource hangs off +0x78 and is freed through the heap entry point
 * at 0x020307B0 rather than 0x02066B38.  The trailing wipe is the same
 * 0x7c-byte object fill.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D300.c \
 *       --func sub_0204D300 --addr 0x0204D300 --cc 1.1p1 --arm
 */
void sub_0204D300(struct Obj_0204D300 *o)
{
    sub_020307B0(o->unk_78);
    sub_02082BCC(o, 0, 0x7c);
}



extern void (*const gUnk_020A1394[][3])(struct Obj0204D324 *obj, u32 arg);



/*
 * Dispatch on the object's kind word, passing the object and one forwarded
 * argument.
 *
 * The second parameter is real, not a leftover: the original steps over r1
 * entirely (kind in r3, table base in r2) where the one-parameter spelling
 * uses r2 and r1.  A register that the body never touches and never
 * reallocates is a live argument being forwarded.
 *
 * This file was previously parked at MATCH on the theory that the pool word
 * 0x020A13B8 named a table object of its own, which left the ABS32 site
 * with no witness: 0x020A13B8 appears in exactly one pool image-wide, this
 * function's own, and self-reference is refused.  It is not a table of its
 * own.  The words from 0x020A1394 onward are one two-dimensional array of
 * at least eleven rows of three handlers, indexed [operation][kind], and
 * the functions of this family each pin a different row:
 *
 *   row 0  0x020A1394   pooled at 0x0204D490
 *   row 1  0x020A13A0   pooled at 0x0204D45C
 *   row 3  0x020A13B8   pooled here
 *   row 5  0x020A13D0   pooled at 0x0204D130  (sub_0204D104)
 *   row 6  0x020A13DC   pooled at 0x0204D100
 *   row 7  0x020A13E8   pooled at 0x0204D428  (sub_0204D410)
 *   row 10 0x020A140C   pooled at 0x0204D3C4  (unit_0204D3C4.c)
 *
 * Declared that way the relocation names the array's base, 0x020A1394, and
 * the +0x24 is the row index coming from the C rather than from the bytes
 * under test; the base is attested `literal` by the pool word at 0x0204D490,
 * well outside this range.  Same bytes, same pool word, an honest witness.
 * See docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D324.c \
 *       --func func_0204D324 --addr 0x0204D324 --cc 1.1p1 --arm
 */
void func_0204D324(struct Obj0204D324 *obj, u32 arg)
{
    gUnk_020A1394[3][obj->kind](obj, arg);
}



/*
 * One of this family's per-slot "apply" hooks: take the handle at +8,
 * resolve it through sub_020627D8, and feed the result to sub_0206434C
 * together with the embedded record at +0xc.  sub_0204D360 is a
 * byte-for-byte duplicate of this function at a different address (the two
 * differ only in their PC24 displacements), which is what a pair of
 * distinct table slots sharing one body looks like when neither was folded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D340.c \
 *       --func sub_0204D340 --addr 0x0204D340 --cc 1.1p1 --arm
 */
void sub_0204D340(struct Obj_0204D340 *o, u32 idx)
{
    sub_0206434C(&o->unk_0c, sub_020627D8(o->unk_08, idx));
}



/*
 * The second copy of sub_0204D340: same body, same two callees, emitted
 * again thirty-two bytes later.  Two adjacent dispatch-table slots each got
 * their own definition and nothing folded them, so the only difference
 * between the two functions in the image is the PC24 displacement.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D360.c \
 *       --func sub_0204D360 --addr 0x0204D360 --cc 1.1p1 --arm
 */
void sub_0204D360(struct Obj_0204D360 *o, u32 idx)
{
    sub_0206434C(&o->unk_0c, sub_020627D8(o->unk_08, idx));
}



/*
 * The third member of the sub_0204D340 / sub_0204D360 trio, reading the
 * handle from +0x74 instead of +8 and finishing in sub_0206469C instead of
 * sub_0206434C.  The shared middle step, sub_020627D8 on the handle, is
 * what says these three are the same operation over different slots.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D380.c \
 *       --func sub_0204D380 --addr 0x0204D380 --cc 1.1p1 --arm
 */
void sub_0204D380(struct Obj_0204D380 *o, u32 idx)
{
    sub_0206469C((struct Obj0206469C *)(&o->unk_0c), sub_020627D8(o->unk_74, idx));
}


/*
 * Set the +0x10 field of the record sub_0204D410 resolves for this object,
 * then re-run the object through the sub_0204D3C4 dispatcher with a zero
 * second argument.  Both callees are themselves index-dispatch thunks
 * (`ldr r3,[r0]; ldr r2,[table, r3 lsl 2]; blx r2`), so this function is
 * the C-visible half of a virtual pair.
 *
 * The object pointer is kept in r5 across the first call rather than
 * recomputed, which is what forces the four-register push: r4 holds the
 * incoming second argument over the same call.
 *
 * This is the missing witness for src/pending/sub_0204B8C4.c, whose only
 * unresolved site is the ABS32 pool word naming 0x0204D3A0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D3A0.c \
 *       --func sub_0204D3A0 --addr 0x0204D3A0 --cc 1.1p1 --arm
 */
void sub_0204D3A0(struct Obj *o, u32 value)
{
    sub_0204D410(o)->unk_10 = value;
    sub_0204D3C4(o, 0);
}
