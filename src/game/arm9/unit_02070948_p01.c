/*
 * file:     unit_02070948_p01.c
 * unit:     yes
 * function: func_02070948, func_02070A24
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
 */
#include "../../matched/include/Obj16648.h"

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

void MIi_CpuClear16(u16 value, void *dest, u32 size);
s32_02070948 func_0206E7EC(void *name, void *ent);
extern void *func_0206E62C(const ResDict *dict, u32 idx);
extern u32 func_0207C768(u32 a, u32 b);
void func_02070A24(const ResTex *pTex, u32 idx, MatAnmResult *pResult);
extern u32 data_020A822C;


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

#define GetTexKeyAddr(key) ((u32)(((key) & 0x0000FFFF) << 3))

/*
 * NitroSystem g3d, the texture-parameter setter of the texture-pattern
 * animation: look the texture up by index in the texture block's dictionary
 * (func_0206E62C, at +0x3c of the texture resource), rebase its TEXIMAGE_PARAM
 * on the VRAM address of the plain or the 4x4-compressed texture slot (format
 * field == 5, 0x14000000), store the original width/height (two 11-bit fields
 * of the extra parameter) and derive the magnification factors with FX_Div
 * (func_0207C768), FX32_ONE when unchanged.
 *
 * The earlier DIFF 60 (a mask/value register swap throughout) came from
 * three misreadings, all fixed here: the second parameter is the dictionary
 * INDEX forwarded untouched to func_0206E62C (the caller func_02070B64 passes
 * a dictionary lookup's result there); the `lsl #16 / lsr #16 / bic
 * #0xe0000000` triple is NNS_GfdGetTexKeyAddr(vramKey) >> 3, i.e.
 * ((key & 0xffff) << 3) >> 3, not a 16-bit bitfield; and the prmTexImage
 * update is `&=` then `|=`.  1.1p1 is 28 bytes out on this source.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070A24.c \
 *       --func func_02070A24 --addr 0x02070A24 --arm --cc ../2.0/sp2
 */
void func_02070A24(const ResTex *pTex, u32 idx, MatAnmResult *pResult)
{
    const DictTexData *pData = (const DictTexData *)(pTex ? func_0206E62C(&pTex->dict, idx) : 0);
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
