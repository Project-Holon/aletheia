/*
 * file:     unit_0206A17C.c
 * unit:     yes
 * function: func_0206A17C, func_0206A19C, func_0206A2CC, func_0206A3CC, func_0206A4AC, func_0206A5B4
 * address:  0x0206A17C
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
 *   FX_Div  0x0207C768  arm
 *   func_0206E62C  0x0206E62C  arm
 */
#include "../../matched/include/Obj07044.h"
#include "../../matched/include/Obj11595.h"
#include "../../matched/include/Obj16556.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    char  pad00[0x2c];
    void *buf;
    char  pad30[2];
    u16   flags;
} S;

typedef unsigned char  u8;

typedef int s32;

typedef s32 fx32;

typedef struct { u8 revision; u8 numEntry; u16 sizeDictBlk; u16 dummy_; u16 ofsEntry; } ResDict;

typedef struct { u16 sizeUnit; u16 sizeTotal; u8 data[4]; } ResDictEntryHeader;

typedef struct { u16 ofsDictTexToMatList; u16 ofsDictPlttToMatList; ResDict dict; } ResMat;

typedef struct { u32 sig; u32 size; u32 texVramKey; u8 pad0c[0x0c]; u32 tex4x4VramKey; u8 pad1c[0x10]; u32 plttVramKey; u8 pad30[4]; u16 ofsPlttDict; u8 pad36[6]; ResDict dict; } ResTex;

typedef struct { u16 offset; u8 numIdx; u8 flag; } TexToMatIdx;

typedef struct { u32 texImageParam; u32 extraParam; } TexData;

typedef struct {
    u16 itemTag; u16 size; u32 diffAmb; u32 specEmi; u32 polyAttr; u32 polyAttrMask;
    u32 texImageParam; u32 texImageParamMask; u16 texPlttBase; u16 flag;
    u16 origWidth; u16 origHeight; fx32 magW; fx32 magH;
} MatData;

typedef int BOOL;

typedef struct { u8 name[16]; } ResName;

typedef struct { u32 sig; u32 size; u32 ofsMat; } ResMdl;

typedef struct { u16 offset; u8 numIdx; u8 flag; } PlttToMatIdx;

typedef struct { u16 offset; u16 flag; } PlttData;

typedef struct {
    u8  f0;
    u8  count;
    u8  f2;
    u8  flags;
    u16 f4;
    u16 tbl;
} Ent;

extern u32 FX_Div(u32 a, u32 b);
extern void *func_0206E62C(const ResDict *dict, const ResName *name);
void *func_0206A17C(S *p);
void func_0206A19C(ResMat *pMat, TexToMatIdx *pBindData, const ResTex *pTex, const TexData *pTexData);
BOOL func_0206A2CC(ResMdl *pMdl, const ResTex *pTex);
void func_0206A3CC(ResMat *pMat, PlttToMatIdx *pBindData, const ResTex *pTex, const PlttData *pPlttData);
BOOL func_0206A4AC(ResMdl *pMdl, const ResTex *pTex);
int func_0206A5B4(char *h, char *c, u32 i2, u32 i3);





/*
 * Clear the "loaded" bit of the flags halfword at +0x32, detach the buffer
 * pointer at +0x2c and return the old pointer.
 *
 * Pin evidence (2.0), measured 2026-09-21: the "kept constants" tell.  The
 * image materialises the store's zero EARLY, `mov r1, #0` at 0x0206A180
 * (`00 10 a0 e3`) between the `ldrh` and the `bic`, and only loads the buffer
 * pointer at 0x0206A18C, after the flags read-modify-write has retired.
 * dsi/1.1p1 -O4,p hoists the buffer load instead and sinks the constant,
 * giving `ldrh r3 / ldr r2,[r0,#0x2c] / mov r1,#0 / bic r3,r3,#1 / strh r3`:
 * the same 32 bytes with the first five instructions permuted, 16 concrete
 * bytes out.  Three source orderings (block-scoped old, statement-split
 * compound assign, raw pointer casts) all schedule identically under 1.1p1.
 * Under the pin the C below is 32 bytes, 0 mismatches.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A17C.c \
 *       --func func_0206A17C --addr 0x0206A17C --arm --cc ../2.0/sp2
 */
void *func_0206A17C(S *p)
{
    void *old;
    u32   f = p->flags;

    p->flags = (u16)(f & ~1u);
    old = p->buf;
    p->buf = 0;
    return old;
}





static inline void *GetResDataByIdx(const ResDict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const ResDictEntryHeader *hdr = (const ResDictEntryHeader *)((const u8 *)dict + dict->ofsEntry);
        return (void *)((const u8 *)hdr + 4 + hdr->sizeUnit * idx);
    }
    return 0;
}





static inline MatData *GetMatDataByIdx(ResMat *mat, u32 idx)
{
    if (mat) {
        u32 *data = (u32 *)GetResDataByIdx(&mat->dict, idx);
        if (data)
            return (MatData *)((u8 *)mat + *data);
    }
    return 0;
}





static inline u32 GetTexKeyAddr(u32 key)
{
    return (u32)((key & 0xffff) << 3);
}





/*
 * NitroSystem G3D bindMdlTex_Internal_ (static helper of NNS_G3dBindMdlTex,
 * func_0206A2CC): for every material index in a tex-to-material bind record,
 * ORs the texture's TEXIMAGE_PARAM (plus the VRAM key address >> 3) into the
 * material and sets magW/magH to width/origWidth and height/origHeight as
 * fx32 (FX32_ONE fast path, else FX_Div = FX_Div).  The key comes from
 * texInfo.vramKey (+8) or, for a 4x4-compressed texture (texfmt field
 * 0x1c000000 == 5 << 26), tex4x4Info.vramKey (+0x18).
 *
 * WHAT CLOSED IT (open since wave 9, "prologue spill choice"): writing the
 * body in terms of the real NitroSystem types and inlines instead of raw
 * offsets -- NNS_G3dGetMatDataByIdx(mat, idx) as a static inline with an
 * `if (mat)` guard around NNS_G3dGetResDataByIdx(&mat->dict, idx), and
 * NNS_GfdGetTexKeyAddr(key) = (key & 0xffff) << 3 followed by `>> 3` (the
 * pair is what 2.0 folds to the bic #0xe0000000).  EXACT on the first compile.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206A19C.c
 *       --func func_0206A19C --addr 0x0206A19C --arm --cc ../2.0/sp2
 */
void func_0206A19C(ResMat *pMat, TexToMatIdx *pBindData, const ResTex *pTex, const TexData *pTexData)
{
    u8 *base;
    u32 vramOffset;
    u32 j;

    base = (u8 *)pMat + pBindData->offset;

    if ((pTexData->texImageParam & 0x1c000000) != 0x14000000)
        vramOffset = GetTexKeyAddr(pTex->texVramKey) >> 3;
    else
        vramOffset = GetTexKeyAddr(pTex->tex4x4VramKey) >> 3;

    for (j = 0; j < pBindData->numIdx; ++j) {
        MatData *matData = GetMatDataByIdx(pMat, base[j]);
        u32 w, h;

        matData->texImageParam |= pTexData->texImageParam + vramOffset;
        w = pTexData->extraParam & 0x7ff;
        h = (pTexData->extraParam & (0x7ff << 11)) >> 11;
        matData->magW = (w == matData->origWidth) ? 0x1000 : FX_Div((fx32)(w << 12), (fx32)(matData->origWidth << 12));
        matData->magH = (h == matData->origHeight) ? 0x1000 : FX_Div((fx32)(h << 12), (fx32)(matData->origHeight << 12));
    }
    pBindData->flag |= 1;
}





static inline ResMat *GetMat(ResMdl *mdl)
{
    if (mdl != 0 && mdl->ofsMat != 0) return (ResMat *)((u8 *)mdl + mdl->ofsMat);
    return 0;
}





static inline const ResName *GetResNameByIdx(const ResDict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const ResDictEntryHeader *hdr = (const ResDictEntryHeader *)((const u8 *)dict + dict->ofsEntry);
        return (const ResName *)((const u8 *)hdr + hdr->sizeTotal) + idx;
    }
    return 0;
}





static inline void *GetTexDataByName(const ResTex *tex, const ResName *name)
{
    if (tex)
        return func_0206E62C(&tex->dict, name);
    return 0;
}





/*
 * NitroSystem G3D NNS_G3dBindMdlTex(mdl, tex): for every entry of the
 * material block's tex-to-material dictionary, looks the entry's name up in
 * the texture's dictionary (func_0206E62C = NNS_G3dGetResDataByName, dict at
 * tex + 0x3c) and, when found and not already bound (flag bit 0), binds it
 * through func_0206A19C; returns FALSE if any name was missing.
 *
 * WHAT CLOSED IT: the 9-byte r8/sb swap (base vs name-stride accumulator)
 * that 2285 permuter compiles could not move was the SPELLING OF
 * NNS_G3dGetMat: a static inline written as an if/return with a trailing
 * `return 0;` -- the same guard as a ternary gives the swap.  Everything else
 * is the real NitroSystem shape: GetResNameByIdx / GetResDataByIdx inlines
 * over the ResDict, BOOL result initialised at declaration.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206A2CC.c
 *       --func func_0206A2CC --addr 0x0206A2CC --arm --cc ../2.0/sp2
 */
BOOL func_0206A2CC(ResMdl *pMdl, const ResTex *pTex)
{
    ResMat *mat;
    ResDict *dict;
    u32 i;
    BOOL result = 1;

    mat = GetMat(pMdl);
    dict = (ResDict *)((u8 *)mat + mat->ofsDictTexToMatList);

    for (i = 0; i < dict->numEntry; ++i) {
        const ResName *name = GetResNameByIdx(dict, i);
        void *texData = GetTexDataByName(pTex, name);
        if (texData) {
            TexToMatIdx *data = (TexToMatIdx *)GetResDataByIdx(dict, i);
            if (!(data->flag & 1))
                func_0206A19C(mat, data, pTex, texData);
        } else {
            result = 0;
        }
    }
    return result;
}





static inline u32 GetPlttKeyAddr(u32 key)
{
    return (u32)((key & 0xffff) << 3);
}





/*
 * NitroSystem G3D bindMdlPltt_Internal_ (static helper of
 * NNS_G3dBindMdlPltt, func_0206A4AC): for every material index in a
 * pltt-to-material bind record, stores plttBase + (plttInfo.vramKey address)
 * into the material's texPlttBase, both halved when the palette is not a
 * 4-colour one (flag bit 0 clear); marks the record bound.
 *
 * WHAT CLOSED IT: the 2-byte lsr/ldrh r4/r5 swap (2315 permuter compiles and
 * 28 hand spellings flat) was in the DECLARATIONS: plttBase and vramOffset
 * as u16 locals, vramOffset = (u16)(NNS_GfdGetPlttKeyAddr(key) >> 3) with the
 * key-address helper as an inline ((key & 0xffff) << 3), and the material
 * lookup as the NNS_G3dGetMatDataByIdx inline with an `if (mat)` guard.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206A3CC.c
 *       --func func_0206A3CC --addr 0x0206A3CC --arm --cc ../2.0/sp2
 */
void func_0206A3CC(ResMat *pMat, PlttToMatIdx *pBindData, const ResTex *pTex, const PlttData *pPlttData)
{
    u8 *base;
    u16 plttBase;
    u16 vramOffset;
    u32 j;

    base = (u8 *)pMat + pBindData->offset;
    plttBase = pPlttData->offset;
    vramOffset = (u16)(GetPlttKeyAddr(pTex->plttVramKey) >> 3);

    if (!(pPlttData->flag & 1)) {
        plttBase >>= 1;
        vramOffset >>= 1;
    }
    for (j = 0; j < pBindData->numIdx; ++j) {
        MatData *matData = GetMatDataByIdx(pMat, base[j]);
        matData->texPlttBase = (u16)(plttBase + vramOffset);
    }
    pBindData->flag |= 1;
}



static inline void *GetPlttDataByName(const ResTex *tex, const ResName *name)
{
    if (tex && tex->ofsPlttDict != 0)
        return func_0206E62C((const ResDict *)((const u8 *)tex + tex->ofsPlttDict), name);
    return 0;
}



/*
 * NitroSystem G3D NNS_G3dBindMdlPltt(mdl, tex): the palette twin of
 * func_0206A2CC.  Walks the pltt-to-material dictionary, looks each name up in
 * the texture's palette dictionary (tex + plttInfo.ofsDict at +0x34, only when
 * that offset is non-zero), binds through func_0206A3CC.  Same closing lever
 * as func_0206A2CC (GetMat as an if/return inline).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206A4AC.c
 *       --func func_0206A4AC --addr 0x0206A4AC --arm --cc ../2.0/sp2
 */
BOOL func_0206A4AC(ResMdl *pMdl, const ResTex *pTex)
{
    ResMat *mat;
    ResDict *dict;
    u32 i;
    BOOL result = 1;

    mat = GetMat(pMdl);
    dict = (ResDict *)((u8 *)mat + mat->ofsDictPlttToMatList);

    for (i = 0; i < dict->numEntry; ++i) {
        const ResName *name = GetResNameByIdx(dict, i);
        void *plttData = GetPlttDataByName(pTex, name);
        if (plttData) {
            PlttToMatIdx *data = (PlttToMatIdx *)GetResDataByIdx(dict, i);
            if (!(data->flag & 1))
                func_0206A3CC(mat, data, pTex, plttData);
        } else {
            result = 0;
        }
    }
    return result;
}



/*
 * Resolve one animation entry out of the nested cell/attribute tables and,
 * if it is not already marked done (flags bit 0 at +3), hand it plus the
 * matching context entry to func_0206A3CC.  Returns 1 when the entry was
 * dispatched, 0 otherwise.
 *
 * The listing extent runs to 332 bytes because 0x0206A67C has no label;
 * the function itself is the 200 bytes 0x0206A5B4..0x0206A67C.  The
 * unlabelled follower at 0x0206A67C is reported rather than seeded here.
 *
 * Pin evidence (2.0), measured 2026-09-21: the "kept branches" tell.  The
 * image writes the zero result of the context lookup out TWICE, once per
 * arm: `mov r3, #0` at 0x0206A614 (`00 30 a0 e3`) reached by the inner
 * bounds failure, and a second `mov r3, #0` at 0x0206A61C (`00 30 a0 e3`)
 * reached by the outer null/offset guard, each with its own `b 0x0206A620`
 * (`02 00 00 ea` at 0x0206A610, `00 00 00 ea` at 0x0206A618).  dsi/1.1p1
 * -O4,p cross-jumps the two arms into a single `mov r3, #0` and emits the
 * two branches back to back, giving 196 bytes against the original's 200,
 * every following instruction identical and shifted by exactly four.  Four
 * source spellings of the split (goto to a shared label, chained else-if,
 * hoisted `r3 = 0` initialiser, and the duplicated-else form below) all
 * fold the same way under 1.1p1.  Under the pin the C below is 200 bytes,
 * 0 mismatches.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A5B4.c \
 *       --func func_0206A5B4 --addr 0x0206A5B4 --arm --cc ../2.0/sp2
 */
int func_0206A5B4(char *h, char *c, u32 i2, u32 i3)
{
    char *base;
    Ent  *e1;
    Ent  *r3;
    Ent  *t;

    base = (h != 0 && ((struct Obj07044 *)h)->f8 != 0) ? h + ((struct Obj07044 *)h)->f8 : 0;
    e1 = (Ent *)(base + ((struct Obj16556 *)base)->f2);

    if (c != 0 && ((struct Obj11595 *)c)->f34 != 0) {
        Ent *s = (Ent *)(c + ((struct Obj11595 *)c)->f34);
        if (s != 0 && i3 < s->count) {
            u16 t3 = s->tbl;
            r3 = (Ent *)((char *)s + t3 + 4
                         + *(u16 *)((char *)s + t3) * i3);
        } else {
            r3 = 0;
        }
    } else {
        r3 = 0;
    }
    if (e1 != 0 && i2 < e1->count) {
        u16 t2 = e1->tbl;
        u16 st = *(u16 *)((char *)e1 + t2);
        t = (Ent *)((char *)e1 + t2 + 4 + st * i2);
    } else {
        t = 0;
    }

    if (t != 0 && !(t->flags & 1)) {
        func_0206A3CC((ResMat *)base, (PlttToMatIdx *)t, (const ResTex *)c, (const PlttData *)r3);
        return 1;
    }
    return 0;
}
