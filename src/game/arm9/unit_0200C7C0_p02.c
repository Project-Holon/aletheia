/*
 * file:     unit_0200C7C0_p02.c
 * unit:     yes
 * function: func_0200CC40, func_0200CDE0, func_0200CED4, func_0200CF08, func_0200CF28, func_0200CF54, func_0200CFA0, func_0200D064, func_0200D0AC, func_0200D0CC, func_0200D0F8, func_0200D144, func_0200D288, func_0200D298, func_0200D2B0, func_0200D2C4, func_0200D2D8, func_0200D310, func_0200D368, func_0200D3C0, func_0200D418, func_0200D424, func_0200D440, func_0200D454, func_0200D45C, func_0200D468, func_0200D470
 * address:  0x0200CC40
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200C7F4        0x0200C7F4  thumb
 *   func_0200C7C0        0x0200C7C0  thumb
 *   func_0200CA98_Table  0x0209DE4C  data
 *   func_0201ADE4        0x0201ADE4  thumb
 *   func_0201AE1C        0x0201AE1C  thumb
 *   func_0201AE14        0x0201AE14  thumb
 *   func_0200C720  0x0200C720  thumb
 *   sub_0200C7A0   0x0200C7A0  thumb
 *   sub_0200CED4   0x0200CED4  thumb
 *   sub_0201AF80   0x0201AF80  thumb
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */
struct Personal;
struct Sav;
struct Blk37;
struct Sub020071CCCtrl;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct FormCount {
    u16 id;
    u16 count;
};

struct Blk37 {
    u32 unk00;
    u32 f0  : 1;
    u32 f1  : 10;
    u32 f11 : 1;
    u32 f12 : 10;
    u32 f22 : 10;
    u8  unk008[0x54];
    u8  unk05C[4][0x54];
    u8  unk1AC[4][0x54];
    u8  unk2FC[4][9];
    u8  unk320[0x1B0];
    u32 unk4D0;
};

struct GdsEnt {
    u16 unk00;
    u8  unk02;
    u8  unk03;
    u32 unk04;
    u32 unk08;
    u16 unk0C;
    u16 unk0E;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
};

struct Blk38 {
    u16 unk00;
    u16 unk02;
    struct GdsEnt unk04[2];
    u8  unk2C[2];
    u8  unk2E[2];
    u8  unk30;
    volatile u8 unk31;
    u8  unk32[2];
};

extern u32 func_0200C7F4(u32 id);
extern u32 func_0200C7C0(u16 id);
extern void *func_0201ADE4(u32 a, int b, u32 c);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern u32   func_02017E1C(void *m, u32 field, u32 arg);
extern u8    func_02017F00(void *m);
extern u32   func_02017EAC(void *m);
extern u32 func_0200C720(u32 v);
extern u32   func_0200D064(struct Blk37 *p, u16 id);
extern void  func_0200CA98(struct Blk37 *p, u16 id, u32 c, u32 d, u32 e);
extern void func_0200C818(u8 *p, u32 idx, int sel, int half);
extern void func_0200C914(u8 *p, u32 id, u32 a2, u32 a3, u32 start);
extern void func_0200C738(u8 *p, u32 a1, u32 a2);
extern u32   func_0200CA38(struct Blk37 *p);
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern u32 func_020307B0(void *p);
u32 func_0200CED4(struct Blk37 *p, u16 id);
u16 func_0200CF28(struct Blk37 *p);
u16 func_0200CF54(struct Blk37 *p, u32 heap);
u16 func_0200D0CC(struct Blk37 *p);
u16 func_0200D0F8(struct Blk37 *p, u32 heap);
int func_0200D298(void *a0);
u32 func_0200D144(u8 *p, u16 id, u32 sel, u32 alt, u32 form);
extern int func_0200D310(void *a0, int a1);
extern u16 func_0200D368(struct Blk37 *p, u32 heap);
extern int func_0200C780(u32 v);
extern u32 sub_0200CED4(struct Blk37 *p, u16 id);
extern int sub_0200C7A0(u32 v);
extern u16 *sub_0201AF80(u32 heap, u16 *countOut);
extern int func_0200C7A0(u32 v);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32 func_02005728(u32 range);
u32 func_0200D414(void);
void *func_0200D418(void *sys);
void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
int func_0200D2B0(void *a0, int a1);
int func_0200D2C4(void *p, unsigned int heap);
u16 func_0200D2D8(void *a0);
int sub_0200D310(void *a0, int a1);
extern const struct FormCount func_0200CA98_Table[];






static inline u32 TestBit(const u8 *row, u16 x)
{
    return row[x >> 3] & (1 << (x & 7));
}






static inline u32 TestSpecies(const u8 *row, u32 id)
{
    u16 x = id - 1;
    return row[x >> 3] & (1 << (x & 7));
}






/*
 * The reader half of func_0200CA98: find which form bit (rows +0x30E /
 * +0x317) and which of the four per-species rows (+0x1AC/+0x200/+0x254/
 * +0x2A8) are set for species `id`, report them through out1/out2/outForm,
 * then look the result up through func_0201ADE4 (docs/notes/
 * pkt_0200CC40.c.txt has the decode and the wave-11 form-loop work).
 *
 * Closed in wave 13 by two declaration facts:
 *   - `id` is a u16 PARAMETER.  The image homes r1 to [sp] and then RELOADS
 *     it for the first call (`str r1, [sp] ... ldr r0, [sp]`), the
 *     narrow-parameter tell (docs/idioms/a-narrow-parameter-pins-its-home-
 *     store-to-the-front-of-the-prologue.md); a u32 id copies r1 instead.
 *   - the per-species row tests go through their OWN helper that takes the
 *     1-based species id and forms `u16 x = id - 1` inside.  Each inlined
 *     copy has its own `x`, so the subtraction is shared but `x & 7` and
 *     `x >> 3` are rebuilt at every test, exactly the "rebuild at every
 *     join" the wave-11 note could not reproduce with one shared index.
 *     The two tests of an `||` pair still share the mask, as in the image.
 */
void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5)
{
    u32 idx;
    u32 base;
    u32 form;
    void *h;

    idx = func_0200C7F4(id);
    if (idx != (u32)-1) {
        base = func_0200C7C0(id);
        for (form = 0; form < func_0200CA98_Table[idx].count; form++) {
            if (TestBit(p + 0x30E, base + form)) {
                *outForm = form;
                *out2 = 0;
                break;
            }
            if (TestBit(p + 0x317, base + form)) {
                *outForm = form;
                *out2 = 1;
                break;
            }
        }
        if (TestSpecies(p + 0x1AC, id) || TestSpecies(p + 0x254, id)) {
            *out1 = 0;
        }
        if (TestSpecies(p + 0x200, id) || TestSpecies(p + 0x2A8, id)) {
            *out1 = 1;
        }
    } else {
        *outForm = 0;
        if (TestSpecies(p + 0x1AC, id)) {
            *out1 = 0;
            *out2 = 0;
        }
        if (TestSpecies(p + 0x200, id)) {
            *out1 = 1;
            *out2 = 0;
        }
        if (TestSpecies(p + 0x254, id)) {
            *out1 = 0;
            *out2 = 1;
        }
        if (TestSpecies(p + 0x2A8, id)) {
            *out1 = 1;
            *out2 = 1;
        }
    }
    h = func_0201ADE4(id, (u16)*outForm, a5);
    if (func_0201AE1C(h, 0x14) == 0xFF) {
        *out1 = 2;
    }
    func_0201AE14(h);
}







/*
 * 244 bytes, 0x0200CDE0..0x0200CED4, one function, which carries a label in
 * the generated listing.
 *
 * PROMOTED from src/pending/, where it was parked at MATCH on the `matched`
 * class: the call at +0xCC into func_0200C738 had no witness outside the
 * compared range.  0x0200C738 acquired its own EXACT entry
 * (src/matched/func_0200C738.c, shard layout/matched/arm9/pkt_0200C738.json)
 * in a later wave, and the tu now resolves 16 of 16 relocations.  No byte of
 * the C changed to close it.
 *
 * src/matched/unit_0200CFA0.c is the same function without the func_0200C738
 * call and without the final bit set; the two were written together and the
 * diff between them is the honest description of what this one does extra.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0200CDE0.c \
 *       --addr 0x0200CDE0 --thumb
 *
 * Addresses are Black-image addresses.
 */
void func_0200CDE0(struct Blk37 *p, void *m)
{
    u32 saved;
    u32 g;
    u32 v0;
    u32 v0C;
    u32 f;
    u32 v6F;
    u16 id;
    s32 y;

    saved = func_02017D30(m);
    if (func_02017E1C(m, 0x4C, 0) == 1) {
        func_02017D70(m, saved);
        return;
    }
    id = (u16)func_02017E1C(m, 5, 0);
    v0 = func_02017E1C(m, 0, 0);
    v6F = func_02017E1C(m, 0x6F, 0);
    v0C = func_02017E1C(m, 0xC, 0);
    f = func_02017F00(m);
    g = func_02017EAC(m);
    func_02017D70(m, saved);
    if (func_0200C720(id) != 0) {
        return;
    }
    if (func_0200D064(p, id) == 0) {
        func_0200CA98(p, id, f, g, v6F);
    }
    if (id == 0x147 && p->unk4D0 == 0) {
        p->unk4D0 = v0;
    }
    func_0200C818((u8 *)p, id, f, g);
    func_0200C914((u8 *)p, id, f, g, v6F);
    func_0200C738((u8 *)p, id, v0C);
    y = (u16)(id - 1);
    p->unk008[y >> 3] |= (u8)(1 << (y & 7));
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 */
u32 func_0200CED4(struct Blk37 *p, u16 id)
{
    s32 y;
    u32 r;

    if (func_0200C720(id) != 0) {
        return 0;
    }
    y = (u16)(id - 1);
    r = 1;
    if ((p->unk008[y >> 3] & (1 << (y & 7))) == 0) {
        r = 0;
    }
    return r;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 */
u16 func_0200CF08(struct Blk37 *p, u32 heap)
{
    if (func_0200CA38(p) != 0) {
        return func_0200CF28(p);
    }
    return func_0200CF54(p, heap);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 */
u16 func_0200CF28(struct Blk37 *p)
{
    s32 n;
    s32 i;

    n = 0;
    for (i = 1; i <= 0x289; i++) {
        if (func_0200CED4(p, (u16)i) == 1) {
            n++;
        }
    }
    return (u16)n;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 */
u16 func_0200CF54(struct Blk37 *p, u32 heap)
{
    u16 i;
    u16 n;
    u16 *t;

    n = 0;
    t = func_0201AF80(heap, 0);
    for (i = 1; i <= 0x289; i++) {
        if (func_0200CED4(p, i) == 1 && t[i] != 0x3E7) {
            n = (u16)(n + 1);
        }
    }
    func_020307B0(t);
    return n;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 */
void func_0200CFA0(struct Blk37 *p, void *m)
{
    u32 saved;
    u32 g;
    u32 v0;
    u32 f;
    u32 v6F;
    u16 id;

    saved = func_02017D30(m);
    if (func_02017E1C(m, 0x4C, 0) == 1) {
        func_02017D70(m, saved);
        return;
    }
    id = (u16)func_02017E1C(m, 5, 0);
    v0 = func_02017E1C(m, 0, 0);
    v6F = func_02017E1C(m, 0x6F, 0);
    f = func_02017F00(m);
    g = func_02017EAC(m);
    func_02017D70(m, saved);
    if (func_0200C720(id) != 0) {
        return;
    }
    if (func_0200D064(p, id) == 0) {
        func_0200CA98(p, id, f, g, v6F);
    }
    if (id == 0x147 && p->unk4D0 == 0) {
        p->unk4D0 = v0;
    }
    func_0200C818((u8 *)p, id, f, g);
    func_0200C914((u8 *)p, id, f, g, v6F);
}


static inline u8 *DistRow(struct Blk37 *p, u16 row)
{
    return p->unk05C[row];
}

/*
 * The four-row "distributed" test: after the func_0200C720 range guard,
 * true when species `id` has its bit set in any of the four 0x54-byte rows
 * struct Blk37::unk05C (docs/families/musical_dist_save.h).
 *
 * Closed in wave 13 by writing it through two small inline helpers instead
 * of one open-coded address (docs/notes/pkt_0200D064.c.txt has the long
 * history of the open-coded spellings, best 10 bytes out):
 *   - a row accessor taking a u16 row index, which is where the image's
 *     `lsls/lsrs #16` of the u32 loop counter at every use comes from;
 *   - the species-bit test `TestSpecies(row, id)` that forms `u16 x = id -
 *     1` itself (the same helper closed func_0200CC40).  Inlined, it keeps
 *     `row + (x >> 3)` in the image's operand order instead of letting the
 *     compiler hoist `p + (x >> 3)` out of the loop, and the plain
 *     `return 1;` inside the loop then gives the preheader `movs r0, #1`.
 */
u32 func_0200D064(struct Blk37 *p, u16 id)
{
    u32 i;

    if (func_0200C720(id) != 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (TestSpecies(DistRow(p, i), id)) {
            return 1;
        }
    }
    return 0;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 152 bytes, 0x0200D0AC..0x0200D144, 3 functions, all labelled.
 *
 * The "seen" counterpart of src/matched/unit_0200CED4.c: the same three
 * functions over func_0200D064's four-bitmap test instead of func_0200CED4's
 * single one.  0x289 is 649, one past the last species id this block tracks,
 * and 0x3E7 is the 999 the id-to-index table uses for "no entry".
 *
 * Near miss, and the reason this range starts at 0x0200D0AC: func_0200D064,
 * 72 bytes, the four-bitmap test itself.  Every instruction reproduces bar the
 * placement of one `adds`: the original recomputes `p + i * 0x54 + (id >> 3)`
 * inside the loop, and mwccarm hoists the loop-invariant `p + (id >> 3)` into
 * the preheader instead, which leaves the same instruction count and the same
 * 72 bytes with 30 concrete bytes differing in register numbers.  Eighty
 * source shapes were compiled and ranked: the loop counter as `u16`, `u32` and
 * `s32`, the index with and without a `(u16)` cast, the bit mask and the byte
 * index as locals and inline, `for` against `do`/`while`, `goto` against
 * `return`, and the row as a pointer local, a dereferenced sum and a flat
 * index.  Only the `(u16)` cast on the index and the mask in a local reach the
 * right size at all, and past that the ranking is flat at 30, so the hoist is
 * not reachable from the source shape.  Same class as the near misses at
 * 0x0200B2A4 and 0x0200B37C.
 */
u32 func_0200D0AC(struct Blk37 *p, u32 heap)
{
    if (func_0200CA38(p) != 0) {
        return func_0200D0CC(p);
    }
    return func_0200D0F8(p, heap);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 152 bytes, 0x0200D0AC..0x0200D144, 3 functions, all labelled.
 *
 * The "seen" counterpart of src/matched/unit_0200CED4.c: the same three
 * functions over func_0200D064's four-bitmap test instead of func_0200CED4's
 * single one.  0x289 is 649, one past the last species id this block tracks,
 * and 0x3E7 is the 999 the id-to-index table uses for "no entry".
 *
 * Near miss, and the reason this range starts at 0x0200D0AC: func_0200D064,
 * 72 bytes, the four-bitmap test itself.  Every instruction reproduces bar the
 * placement of one `adds`: the original recomputes `p + i * 0x54 + (id >> 3)`
 * inside the loop, and mwccarm hoists the loop-invariant `p + (id >> 3)` into
 * the preheader instead, which leaves the same instruction count and the same
 * 72 bytes with 30 concrete bytes differing in register numbers.  Eighty
 * source shapes were compiled and ranked: the loop counter as `u16`, `u32` and
 * `s32`, the index with and without a `(u16)` cast, the bit mask and the byte
 * index as locals and inline, `for` against `do`/`while`, `goto` against
 * `return`, and the row as a pointer local, a dereferenced sum and a flat
 * index.  Only the `(u16)` cast on the index and the mask in a local reach the
 * right size at all, and past that the ranking is flat at 30, so the hoist is
 * not reachable from the source shape.  Same class as the near misses at
 * 0x0200B2A4 and 0x0200B37C.
 */
u16 func_0200D0CC(struct Blk37 *p)
{
    s32 n;
    s32 i;

    n = 0;
    for (i = 1; i <= 0x289; i++) {
        if (func_0200D064(p, (u16)i) == 1) {
            n++;
        }
    }
    return (u16)n;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 152 bytes, 0x0200D0AC..0x0200D144, 3 functions, all labelled.
 *
 * The "seen" counterpart of src/matched/unit_0200CED4.c: the same three
 * functions over func_0200D064's four-bitmap test instead of func_0200CED4's
 * single one.  0x289 is 649, one past the last species id this block tracks,
 * and 0x3E7 is the 999 the id-to-index table uses for "no entry".
 *
 * Near miss, and the reason this range starts at 0x0200D0AC: func_0200D064,
 * 72 bytes, the four-bitmap test itself.  Every instruction reproduces bar the
 * placement of one `adds`: the original recomputes `p + i * 0x54 + (id >> 3)`
 * inside the loop, and mwccarm hoists the loop-invariant `p + (id >> 3)` into
 * the preheader instead, which leaves the same instruction count and the same
 * 72 bytes with 30 concrete bytes differing in register numbers.  Eighty
 * source shapes were compiled and ranked: the loop counter as `u16`, `u32` and
 * `s32`, the index with and without a `(u16)` cast, the bit mask and the byte
 * index as locals and inline, `for` against `do`/`while`, `goto` against
 * `return`, and the row as a pointer local, a dereferenced sum and a flat
 * index.  Only the `(u16)` cast on the index and the mask in a local reach the
 * right size at all, and past that the ranking is flat at 30, so the hoist is
 * not reachable from the source shape.  Same class as the near misses at
 * 0x0200B2A4 and 0x0200B37C.
 */
u16 func_0200D0F8(struct Blk37 *p, u32 heap)
{
    u16 i;
    u16 n;
    u16 *t;

    n = 0;
    t = func_0201AF80(heap, 0);
    for (i = 1; i <= 0x289; i++) {
        if (func_0200D064(p, i) == 1 && t[i] != 0x3E7) {
            n = (u16)(n + 1);
        }
    }
    func_020307B0(t);
    return n;
}



/*
 * The five-way reader over the bitmaps func_0200C818/func_0200C914 write
 * (decode in docs/notes/pkt_0200D144.c.txt).  EXACT* only because the
 * 16-byte leaf that follows it, func_0200D288, has no label; that leaf is
 * filed as its own witness, src/matched/func_0200D288.c.
 *
 * Closed in wave 13: the two-row tests of the last two arms go through the
 * species-bit helper `TestSpecies(row, id)` (it forms `u16 x = id - 1`
 * itself, as in func_0200CC40 and func_0200D064), joined by `||`.  Each
 * inlined copy has its own `x`, so the image's second `adds r0, r5, r1`
 * (p + off formed again for the +0xB0 row) comes out, which no open-coded
 * spelling reached (it was 2 bytes short or 2 long, never right).  The
 * single-row arms keep the open-coded `r = 1; if (!bit) r = 0; return r;`
 * shape that gives their shared `bne` tail.
 */
u32 func_0200D144(u8 *p, u16 id, u32 sel, u32 alt, u32 form)
{
    u32 res;
    s32 x;
    u32 m;
    u32 r;

    if (func_0200C720(id) != 0) {
        return (u32)-1;
    }
    res = func_0200C7C0(id);
    if (res != (u32)-1) {
        x = (u16)(res + form);
        m = 1 << (x & 7);
        r = 1;
        if (((p + alt * 9 + (x >> 3))[0x2FC] & m) == 0) {
            r = 0;
        }
        return r;
    }
    if (sel == 0) {
        if (alt == 1) {
            x = (u16)(id - 1);
            m = 1 << (x & 7);
            r = 1;
            if (((p + (x >> 3))[0x104] & m) == 0) {
                r = 0;
            }
            return r;
        }
        x = (u16)(id - 1);
        m = 1 << (x & 7);
        r = 1;
        if (((p + (x >> 3))[0x5C] & m) == 0) {
            r = 0;
        }
        return r;
    }
    if (sel == 1) {
        if (alt == 1) {
            x = (u16)(id - 1);
            m = 1 << (x & 7);
            r = 1;
            if (((p + (x >> 3))[0x158] & m) == 0) {
                r = 0;
            }
            return r;
        }
        x = (u16)(id - 1);
        m = 1 << (x & 7);
        r = 1;
        if (((p + (x >> 3))[0xB0] & m) == 0) {
            r = 0;
        }
        return r;
    }
    if (alt == 1) {
        if (TestSpecies(p + 0x104, id) || TestSpecies(p + 0x158, id)) {
            goto oneA;
        }
        goto zero;
oneA:
        return 1;
    }
    if (TestSpecies(p + 0x5C, id) || TestSpecies(p + 0xB0, id)) {
        goto oneB;
    }
    goto zero;
oneB:
    return 1;
zero:
    return 0;
}



/*
 * The 16-byte leaf that follows func_0200D144 inside its listing extent
 * (0x0200D288..0x0200D298): `cmp r1, #0 / bne / movs r1, #0x4d / lsls r1,
 * #4 / ldr r0, [r0, r1] / bx lr / movs r0, #0 / bx lr`.  It saves nothing,
 * so disasm.py never labels it (docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md); filed as its own compiled witness in wave 13.  It reads
 * struct Blk37's +0x4D0 word, the first-write-wins species-0x147 cache that
 * func_0200CDE0/func_0200CFA0 fill (docs/families/musical_dist_save.h), and
 * answers 0 for any selector but 0.  Wants seeding into
 * layout/function_starts.txt.
 */
u32 func_0200D288(struct Blk37 *p, u32 which)
{
    if (which == 0) {
        return p->unk4D0;
    }
    return 0;
}


int func_0200D298(void *a0)
{
    u32 v = func_0200D2D8(a0);

    if (v >= 0x27a)
        return 1;
    return 0;
}



/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 */
int func_0200D2B0(void *a0, int a1)
{
    u32 v = func_0200D310(a0, a1);

    if (v >= 0x96)
        return 1;
    return 0;
}


int func_0200D2C4(void *p, unsigned int heap)
{
    return func_0200D368(p, heap) >= 0x96;
}



u16 func_0200D2D8(void *a0)
{
    int i;
    u16 n = 0;

    for (i = 1; i <= 0x289; i++) {
        if (func_0200CED4(a0, i) == 1 && func_0200C780((u16)i) == 1)
            n++;
    }
    return n;
}



int sub_0200D310(void *a0, int a1)
{
    u16 *t = sub_0201AF80(a1, 0);
    u16 i;
    u16 n = 0;

    for (i = 1; i <= 0x289; i++) {
        if (sub_0200CED4(a0, i) != 1) {
            continue;
        }
        if (t[i] == 0x3e7) {
            continue;
        }
        if (sub_0200C7A0(i) == 1) {
            n++;
        }
    }
    func_020307B0(t);
    return n;
}



/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 172 bytes, 0x0200D368..0x0200D414, 2 functions, one of which carries a label
 * in the generated listing.
 *
 * The tail of the save block with id 0x37, whose head is
 * src/matched/unit_0200C9EC.c.  func_0200D368 counts the species this block
 * records as seen that the id table has an entry for and that func_0200C7A0
 * accepts; func_0200D3C0 reads a bit out of the flat 0x1B0-byte bitmap at
 * +0x320, indexed by `(b - 1) + (a - 1) * 7` over a range of 0x1ED rows.
 *
 * func_0200D3C0 saves `r4` without saving `lr`, so `disasm.py` does not label
 * it and it arrives in the listing as a run of `.word`s.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Its second selector is rejected above 8 and at exactly 6, and then
 * decremented above 6, so the seven live values 1..5, 7, 8 map onto 0..6; the
 * hole at 6 and the shift around it are in the original and are what the two
 * compares and the `subs` encode.
 *
 * This range starts at 0x0200D368 rather than at the head of the group because
 * func_0200C7A0 is reached from exactly two places in the image, 0x0200D33A in
 * func_0200D310 and 0x0200D392 here, so a range holding both has no witness
 * left for it.  Cut between them and this half closes.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The other
 * half does not close, because func_0200C780 is reached only from
 * func_0200D2D8; it is parked in src/pending/unit_0200D288.c.
 *
 * Near miss in the same original file: func_0200D144, 322 bytes at
 * 0x0200D144, the five-way reader over the same bitmaps.  It reaches the right
 * size and the right control flow, and sixteen bytes in its last arm differ in
 * register numbers alone: the original keeps the shifted id in one register and
 * masks it into a scratch, and mwccarm masks in place and allocates the bit and
 * the loaded byte the other way round.  Adding a named local for the mask
 * fixes the arm before it, which is where the original also spends a register
 * copy, and adding one here costs an instruction the original does not have;
 * all 120 permutations of the five locals and every spelling of the two
 * operands rank flat at sixteen.
 */
u16 func_0200D368(struct Blk37 *p, u32 heap)
{
    u16 i;
    u16 n;
    u16 *t;

    n = 0;
    t = func_0201AF80(heap, 0);
    for (i = 1; i <= 0x289; i++) {
        if (func_0200D064(p, i) == 1 && t[i] != 0x3E7 && func_0200C7A0(i) == 1) {
            n = (u16)(n + 1);
        }
    }
    func_020307B0(t);
    return n;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 172 bytes, 0x0200D368..0x0200D414, 2 functions, one of which carries a label
 * in the generated listing.
 *
 * The tail of the save block with id 0x37, whose head is
 * src/matched/unit_0200C9EC.c.  func_0200D368 counts the species this block
 * records as seen that the id table has an entry for and that func_0200C7A0
 * accepts; func_0200D3C0 reads a bit out of the flat 0x1B0-byte bitmap at
 * +0x320, indexed by `(b - 1) + (a - 1) * 7` over a range of 0x1ED rows.
 *
 * func_0200D3C0 saves `r4` without saving `lr`, so `disasm.py` does not label
 * it and it arrives in the listing as a run of `.word`s.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Its second selector is rejected above 8 and at exactly 6, and then
 * decremented above 6, so the seven live values 1..5, 7, 8 map onto 0..6; the
 * hole at 6 and the shift around it are in the original and are what the two
 * compares and the `subs` encode.
 *
 * This range starts at 0x0200D368 rather than at the head of the group because
 * func_0200C7A0 is reached from exactly two places in the image, 0x0200D33A in
 * func_0200D310 and 0x0200D392 here, so a range holding both has no witness
 * left for it.  Cut between them and this half closes.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The other
 * half does not close, because func_0200C780 is reached only from
 * func_0200D2D8; it is parked in src/pending/unit_0200D288.c.
 *
 * Near miss in the same original file: func_0200D144, 322 bytes at
 * 0x0200D144, the five-way reader over the same bitmaps.  It reaches the right
 * size and the right control flow, and sixteen bytes in its last arm differ in
 * register numbers alone: the original keeps the shifted id in one register and
 * masks it into a scratch, and mwccarm masks in place and allocates the bit and
 * the loaded byte the other way round.  Adding a named local for the mask
 * fixes the arm before it, which is where the original also spends a register
 * copy, and adding one here costs an instruction the original does not have;
 * all 120 permutations of the five locals and every spelling of the two
 * operands rank flat at sixteen.
 */
u32 func_0200D3C0(struct Blk37 *p, u32 a, u32 b)
{
    s32 x;
    u32 r;

    if (b > 8 || b == 6) {
        return 0;
    }
    if (a > 0x1ED) {
        return 0;
    }
    if (b >= 7) {
        b--;
    }
    a--;
    x = (u16)((b - 1) + a * 7);
    r = 1;
    if ((p->unk320[x >> 3] & (1 << (x & 7))) == 0) {
        r = 0;
    }
    return r;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
u32 func_0200D414(void)
{
    return sizeof(struct Blk38);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
void *func_0200D418(void *sys)
{
    return func_020071CC(sys, 0x38);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
void func_0200D424(struct Blk38 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk38));
    p->unk30 = 0;
    p->unk31 = 0;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
void func_0200D440(void *sys)
{
    struct Blk38 *p = func_0200D418(sys);

    p->unk30 = func_02005728(0x11);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
u8 func_0200D454(struct Blk38 *p)
{
    return p->unk30;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
void func_0200D45C(struct Blk38 *p, u16 v)
{
    if (p->unk00 != v) {
        p->unk02 = p->unk00;
        p->unk00 = v;
    }
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
u8 func_0200D468(struct Blk38 *p, u32 i)
{
    return p->unk2E[i];
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
void func_0200D470(struct Blk38 *p, u32 i, u32 v)
{
    p->unk2E[i] = v;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
u8 func_0200D478(struct Blk38 *p, u32 i)
{
    return p->unk2C[i];
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
void func_0200D480(struct Blk38 *p, u32 i, u8 v)
{
    p->unk2C[i] = v;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
u8 func_0200D488(struct Blk38 *p, u32 i)
{
    return p->unk04[i].unk12;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
void func_0200D494(struct GdsEnt *e)
{
    MI_CpuFill8(e, 0, sizeof(struct GdsEnt));
    e->unk00 = 0xFFFF;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
struct GdsEnt *func_0200D4AC(struct Blk38 *p, u32 i)
{
    return &p->unk04[i];
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
u32 func_0200D4B8(const struct GdsEnt *e, u32 i)
{
    switch (i) {
    case 0:
        break;
    case 1:
        return e->unk00;
    case 2:
        return e->unk04;
    case 3:
        return e->unk08;
    case 10:
        return e->unk02;
    case 4:
        return e->unk0C;
    case 5:
        return e->unk0E;
    case 6:
        return e->unk10;
    case 7:
        return e->unk11;
    case 8:
        return e->unk12;
    case 9:
        return e->unk13;
    }
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
void func_0200D50C(struct GdsEnt *e, u32 i, u32 v)
{
    switch (i) {
    case 0:
        break;
    case 1:
        e->unk00 = v;
        break;
    case 2:
        e->unk04 = v;
        break;
    case 3:
        e->unk08 = v;
        break;
    case 10:
        e->unk02 = v;
        break;
    case 4:
        e->unk0C = v;
        break;
    case 5:
        e->unk0E = v;
        break;
    case 6:
        e->unk10 = v;
        break;
    case 7:
        e->unk11 = v;
        break;
    case 8:
        e->unk12 = v;
        break;
    case 9:
        e->unk13 = v;
        break;
    }
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
void func_0200D55C(struct Blk38 *p, u8 v)
{
    p->unk31 = v;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
u32 func_0200D564(struct Blk38 *p)
{
    if (p->unk31 != 0) {
        p->unk31 = p->unk31 - 1;
        if (p->unk31 == 0) {
            return 1;
        }
    }
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D454, func_0200D45C, func_0200D468, func_0200D470,
 *           func_0200D478, func_0200D480, func_0200D488, func_0200D494,
 *           func_0200D4AC, func_0200D4B8, func_0200D50C, func_0200D55C,
 *           func_0200D564, func_0200D58C
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * func_0200D440 is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: func_0200D414 returns 0x34,
 * func_0200D418 is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * func_0200D424 clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - func_0200D564 reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    func_0200D55C or func_0200D58C, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
u32 func_0200D58C(struct Blk38 *p)
{
    if (p->unk31 == 0) {
        return 1;
    }
    return 0;
}
