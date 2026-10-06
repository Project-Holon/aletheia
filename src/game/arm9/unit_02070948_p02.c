/*
 * file:     unit_02070948_p02.c
 * unit:     yes
 * function: func_02070AFC, func_02070B64, func_02070BD8
 * address:  0x02070AFC
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0206E62C    0x0206E62C  arm
 *   func_0206EA58  0x0206EA58  arm
 *   func_0206EA00  0x0206EA00  arm
 *   func_0206EA2C  0x0206EA2C  arm
 *   func_02070A24  0x02070A24  arm
 *   func_02070AFC  0x02070AFC  arm
 *   data_020A8220  0x020A8220  data
 */
struct NNSG3dResName;
struct NNSG3dResTexPatAnm;
struct Dst70AFC;
struct Obj70AFC;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Ent70AFC { u16 offset; u16 flag; };

struct Obj70AFC {
    u8  pad00[0x2c];
    u32 f2c;
    u32 pad30[1];
    u16 h34;
};

struct Dst70AFC { u8 pad00[0x14]; u32 f14; };

struct N {
    u32   f0;
    u32   f4;
    void *f8;
    u32   fc;
    u32   f10;
    void *f14;
};

struct S {
    u8  pad0[8];
    u32 f8;
    u32 fc;
    u8  pad10[9];
    u8  f19;
    u16 f1a[1];
};

struct Ent70AFC *func_0206E62C(void *dict, void *name);
extern u16 *func_0206EA58(u16 *p, u32 arg, u32 v);
extern const struct NNSG3dResName *func_0206EA00(const struct NNSG3dResTexPatAnm *pPatAnm, u8 texIdx);
extern const struct NNSG3dResName *func_0206EA2C(const struct NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx);
extern void  func_02070A24(void *p, u32 v, void *ctx);
extern void func_02070AFC(struct Obj70AFC *obj, void *name, struct Dst70AFC *dst);
extern u32 data_020A8220;


static inline struct Ent70AFC *GetEnt(struct Obj70AFC *obj, void *name)
{
    if (obj != 0 && obj->h34 != 0)
        return func_0206E62C((u8 *)obj + obj->h34, name);
    return 0;
}

/*
 * Resolves the palette offset for the bound slot: the dictionary entry
 * (offset, flag) of obj's resource at +0x34, plus the 16-bit base index
 * held in obj->f2c (masked to 29 bits).  When flag bit 0 is clear both are
 * halved before the sum is stored at dst->f14 -- the NitroSystem 4-colour
 * palette rule (offsets in 8-byte units for 4-colour, 16-byte otherwise).
 *
 * WHAT CLOSED IT (wave 10), after the 4-instruction r0/r1 exchange of
 * docs/notes/func_02070AFC.c.txt: the two shift pairs `<<15, >>16` are not
 * an explicit truncation but `v >>= 1` on u16 LOCALS (the store's narrowing
 * folded into the shift).  With `u16 ofs, base` and `ofs >>= 1; base >>= 1;`
 * inside `if (!(e->flag & 1))`, plus the obj/h34 guard as an inline
 * GetEnt() helper, it is byte-exact on the first compile.  ../2.0/sp2 (1.1p1
 * is 100 bytes).  The caller func_02070B64 treats it as void.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070AFC.c
 *       --func func_02070AFC --addr 0x02070AFC --arm --cc ../2.0/sp2
 */
void func_02070AFC(struct Obj70AFC *obj, void *name, struct Dst70AFC *dst)
{
    struct Ent70AFC *e = GetEnt(obj, name);
    u16 base = (u16)obj->f2c & ~0xE0000000;
    u16 ofs = e->offset;
    if (!(e->flag & 1)) {
        ofs >>= 1;
        base >>= 1;
    }
    dst->f14 = ofs + base;
}


/*
 * BYTE-CORRECT: 116 bytes, every concrete byte identical to the image.
 * Verdict MATCH* under `--cc ../2.0/sp2 --arm`.
 *
 * Blocked on evidence class `label`, on ALL FIVE PC24 sites at once: this
 * function is the ONLY branch anywhere in the image (arm9 and every overlay)
 * to each of func_0206EA58, func_0206EA00, func_0206EA2C, func_02070A24 and
 * func_02070AFC, so every witness for every site lies inside the compared
 * range and `label` refuses all five.  `--suggest-split` cannot help: there is
 * only one function here to cut, and the report would name each site as
 * having no outside witness at all.  It unblocks the moment any one of the
 * five callees reaches EXACT in a manifest, which then attests it `matched`
 * (func_02070A24 and func_02070AFC are both in this packet and both still
 * open; func_02070AFC has a note at docs/notes/func_02070AFC.c.txt).
 *
 * The `*` is the unlabelled follower at 0x02070BD8, not a byte difference:
 * show --addr 0x02070B64 reports a 192-byte extent because the leaf at
 * 0x02070BD8 saves no lr and so carries no auto-label.  That follower is now
 * filed EXACT as src/matched/func_02070BD8.c; seeding 0x02070BD8 into
 * layout/function_starts.txt would drop the star.
 *
 * Two spelling notes that cost real time:
 *   - the two narrowings passed to func_0206EA58 are u32 shift pairs, NOT u16
 *     casts: `(t << 16) >> 16` and `(n->f0 << 4) >> 16` give the image's
 *     `lsl r1,#0x10 / lsl r2,r3,#4 / lsr r1,#0x10 / lsr r2,#0x10`, while
 *     declaring the parameters u16 and casting adds a second `lsl/lsr` pair on
 *     the second argument (+8 bytes).
 *   - `h` must be declared AFTER the pointer that receives the first call's
 *     result, which is what puts n in r6, h in r5 and the record in r4;
 *     declared first, n lands in r4 and h in r6 and every mov shifts.
 */
void func_02070B64(void *ctx, struct N *n, u32 t)
{
    void *h;
    u8   *r;

    h = n->f8;
    r = (u8 *)func_0206EA58(h, (t << 16) >> 16, (n->f0 << 4) >> 16);
    func_02070A24(n->f14, (u32)func_0206EA00(h, r[2]), ctx);
    if (r[3] == 0xff)
        return;
    func_02070AFC(n->f14, (void *)((u32)func_0206EA2C(h, r[3])), ctx);
}


/*
 * Unlabelled leaf follower of func_02070B64: no lr-saving prologue, so
 * disasm.py never auto-labels it and the worklist folds its 72 bytes into
 * func_02070B64's inferred extent.  It should be seeded into
 * layout/function_starts.txt as a function start at 0x02070BD8, extent
 * 0x02070BD8..0x02070C20 with a single pool word at 0x02070C20.
 *
 * Every one of the 18 instructions is byte-for-byte identical to the image.
 * The single ABS32 site (the pool word at 0x02070C20 holding 0x020A8220)
 * resolves `data_table x8`, so the row is EXACT with no wildcards.
 *
 * Initialiser slot-table setup: stores a global word to +0x0C, copies the
 * count byte from src[0x17] into +0x19, stores the caller's word at +0x08,
 * then fills +0x1A with `i | 0x100` halfwords for i in [0, count).
 * The counter/bound order (`i = 0` assigned before the loop, bound re-read
 * from the struct field each iteration) is what gives `mov ip, #0` hoisted
 * above the first store and the two `ldrb r1, [r0, #0x19]` reloads.
 */
void func_02070BD8(struct S *s, u32 a, u8 *src)
{
    u32 i = 0;
    s->fc = data_020A8220;
    s->f19 = src[0x17];
    s->f8 = a;
    while (i < s->f19) {
        s->f1a[i] = (u16)(i | 0x100);
        i = i + 1;
    }
}
