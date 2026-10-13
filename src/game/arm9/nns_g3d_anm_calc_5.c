/*
 * file:     nns_g3d_anm_calc_5.c
 * unit:     yes
 * function: func_02070948, func_02070A24, func_02070AFC, func_02070B64, func_02070BD8
 * address:  0x02070948
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
 *   MIi_CpuClear16   0x02082A48  arm
 *   func_0206E7EC    0x0206E7EC  arm
 *   data_020A822C    0x020A822C  data
 *   func_0206E62C  0x0206E62C  arm
 *   func_0207C768  0x0207C768  arm
 *   NNSi_G3dTexPatAnmGetFrameValue  0x0206EA58  arm
 *   func_0206EA00  0x0206EA00  arm
 *   func_0206EA2C  0x0206EA2C  arm
 *   data_020A8220  0x020A8220  data
 */
#include "../../matched/include/Obj16648.h"

#define GetTexKeyAddr(key) ((u32)(((key) & 0x0000FFFF) << 3))
struct NNSG3dResName;
struct NNSG3dResTexPatAnm;
struct Dst70AFC;
struct Obj70AFC;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32_02070948;

struct Src70948 {
    u8  pad00[12];
    u8  b0c;
    volatile u8 b0d;
    u8  pad0e[4];
    u16 h12;
};

struct Ctx70948 {
    u8  pad00[8];
    u32 f08;
    u32 f0c;
    u8  pad10[9];
    u8  b19;
    u16 h1a[1];
};

struct Arg70948 {
    u8  pad00[8];
    u32 f08;
    u8  pad0c[12];
    u8  b18;
};

typedef int            s32_02070A24;

typedef s32_02070A24            fx32;

typedef struct { u32 vramKey; u16 sizeTex; u16 ofsDict; u16 flag; u16 pad; u32 ofsTex; } TexInfo;

typedef struct { u32 vramKey; u16 sizeTex; u16 ofsDict; u16 flag; u16 pad; u32 ofsTex; u32 ofsTexPlttIdx; } Tex4x4Info;

typedef struct { u32 vramKey; u16 sizePltt; u16 flag; u16 ofsDict; u16 pad; u32 ofsPlttData; } PlttInfo;

typedef struct { u8 dummy[4]; } ResDict;

typedef struct {
    u32        header[2];
    TexInfo    texInfo;      /* 0x08 */
    Tex4x4Info tex4x4Info;   /* 0x18 */
    PlttInfo   plttInfo;     /* 0x2c */
    ResDict    dict;         /* 0x3c */
} ResTex;

typedef struct { u32 texImageParam; u32 extraParam; } DictTexData;

typedef struct {
    u32  flag;
    u32  prmMatColor0;
    u32  prmMatColor1;
    u32  prmPolygonAttr;
    u32  prmTexImage;        /* 0x10 */
    u32  prmTexPltt;
    fx32 scaleS, scaleT;
    short sinR, cosR;
    fx32 transS, transT;
    u16  origWidth, origHeight;  /* 0x2c */
    fx32 magW, magH;         /* 0x30 */
} MatAnmResult;

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

void MIi_CpuClear16(u16 value, void *dest, u32 size);
s32_02070948 func_0206E7EC(void *name, void *ent);
extern void *func_0206E62C(const ResDict *dict, const void *name);
extern u32 func_0207C768(u32 a, u32 b);
extern u16 *NNSi_G3dTexPatAnmGetFrameValue(u16 *p, u32 arg, u32 v);
extern const struct NNSG3dResName *func_0206EA00(const struct NNSG3dResTexPatAnm *pPatAnm, u8 texIdx);
extern const struct NNSG3dResName *func_0206EA2C(const struct NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx);
void func_02070948(struct Ctx70948 *ctx, struct Src70948 *src, struct Arg70948 *arg);
void func_02070A24(const ResTex *pTex, const void *name, MatAnmResult *pResult);
void func_02070AFC(struct Obj70AFC *obj, void *name, struct Dst70AFC *dst);
void func_02070B64(void *ctx, struct N *n, u32 t);
void func_02070BD8(struct S *s, u32 a, u8 *src);
extern u32 data_020A822C;
extern u32 data_020A8220;



static inline void *GetName(struct Src70948 *src, u32 idx)
{
    u8 *tbl = (u8 *)src + 0xc;
    if (tbl != 0 && idx < src->b0d) {
        u8 *q = tbl + src->h12;
        return q + ((struct Obj16648 *)q)->f2 + idx * 0x10;
    }
    return 0;
}


static inline s32_02070948 Lookup(u8 *names, void *ent)
{
    if (names != 0)
        return func_0206E7EC(names + 4, ent);
    return -1;
}


/*
 * Third member of the func_02070360 / func_02070830 binder set.  Same body
 * with two differences: it also records the source resource in ctx->f08
 * (the u32 store is why the clear's size re-reads ctx->b19 from memory: the
 * store may alias it), and its name dictionary sits at src+0xc (count at
 * +0xd, entry offset at +0x12) instead of src+8.  Seeds ctx->f0c from
 * data_020A822C (= &func_02070B64).  Same levers: GetName/Lookup inline
 * helpers, `volatile` count byte, `i` declared before `names`, ../2.0/sp2.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070948.c
 *       --func func_02070948 --addr 0x02070948 --arm --cc ../2.0/sp2
 */
void func_02070948(struct Ctx70948 *ctx, struct Src70948 *src, struct Arg70948 *arg)
{
    u32 i;
    u8 *names;

    if (arg != 0 && arg->f08 != 0)
        names = (u8 *)arg + arg->f08;
    else
        names = 0;

    ctx->f0c = data_020A822C;
    ctx->b19 = arg->b18;
    ctx->f08 = (u32)src;
    MIi_CpuClear16(0, ctx->h1a, (u32)ctx->b19 * 2);

    for (i = 0; i < src->b0d; i++) {
        s32_02070948 slot = Lookup(names, GetName(src, i));
        if (slot >= 0)
            ctx->h1a[slot] = (u16)(i | 0x100);
    }
}


/*
 * NitroSystem g3d, the texture-parameter setter of the texture-pattern
 * animation: look the texture up by name in the texture block's dictionary
 * (func_0206E62C, at +0x3c of the texture resource), rebase its TEXIMAGE_PARAM
 * on the VRAM address of the plain or the 4x4-compressed texture slot (format
 * field == 5, 0x14000000), store the original width/height (two 11-bit fields
 * of the extra parameter) and derive the magnification factors with FX_Div
 * (func_0207C768), FX32_ONE when unchanged.
 *
 * The earlier DIFF 60 (a mask/value register swap throughout) came from
 * three misreadings, all fixed here: the second parameter is the resource\n * name forwarded untouched to func_0206E62C (the caller func_02070B64 passes\n * a name lookup's result there); the `lsl #16 / lsr #16 / bic
 * #0xe0000000` triple is NNS_GfdGetTexKeyAddr(vramKey) >> 3, i.e.
 * ((key & 0xffff) << 3) >> 3, not a 16-bit bitfield; and the prmTexImage
 * update is `&=` then `|=`.  1.1p1 is 28 bytes out on this source.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070A24.c \
 *       --func func_02070A24 --addr 0x02070A24 --arm --cc ../2.0/sp2
 */
void func_02070A24(const ResTex *pTex, const void *name, MatAnmResult *pResult)
{
    const DictTexData *pData = (const DictTexData *)(pTex ? func_0206E62C(&pTex->dict, name) : 0);
    u32 offset;
    if ((pData->texImageParam & 0x1c000000) != 0x14000000)
        offset = GetTexKeyAddr(pTex->texInfo.vramKey) >> 3;
    else
        offset = GetTexKeyAddr(pTex->tex4x4Info.vramKey) >> 3;
    pResult->prmTexImage &= 0xc00f0000;
    pResult->prmTexImage |= pData->texImageParam + offset;
    pResult->origWidth  = (u16)((pData->extraParam & 0x7ff) >> 0);
    pResult->origHeight = (u16)((pData->extraParam & (0x7ff << 11)) >> 11);
    {
        u32 w = (pData->extraParam & 0x7ff) >> 0;
        u32 h = (pData->extraParam & (0x7ff << 11)) >> 11;
        pResult->magW = (w != pResult->origWidth) ? func_0207C768((fx32)(w << 12), (fx32)(pResult->origWidth << 12)) : 0x1000;
        pResult->magH = (h != pResult->origHeight) ? func_0207C768((fx32)(h << 12), (fx32)(pResult->origHeight << 12)) : 0x1000;
    }
}



static inline struct Ent70AFC *GetEnt(struct Obj70AFC *obj, void *name)
{
    if (obj != 0 && obj->h34 != 0)
        return (struct Ent70AFC *)func_0206E62C((const ResDict *)((u8 *)obj + obj->h34), name);
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
 * to each of NNSi_G3dTexPatAnmGetFrameValue, func_0206EA00, func_0206EA2C, func_02070A24 and
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
 *   - the two narrowings passed to NNSi_G3dTexPatAnmGetFrameValue are u32 shift pairs, NOT u16
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
    r = (u8 *)NNSi_G3dTexPatAnmGetFrameValue(h, (t << 16) >> 16, (n->f0 << 4) >> 16);
    func_02070A24(n->f14, func_0206EA00(h, r[2]), ctx);
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
