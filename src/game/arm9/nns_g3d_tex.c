/*
 * file:     nns_g3d_tex.c
 * unit:     yes
 * function: NNS_G3dAnmObjInit, NNS_G3dRenderObjInit, NNSi_G3dAnmObjInsertByPriority, NNSi_G3dAnmObjCollectMapDataMask, NNS_G3dRenderObjAddAnmObj, NNSi_G3dAnmObjUnlink, NNS_G3dRenderObjRemoveAnmObj, NNS_G3dTexGetRequiredSize, NNS_G3dTex4x4GetRequiredSize, NNS_G3dTexSetTexKey, NNS_G3dTexLoad, NNS_G3dTexReleaseTexKey, NNS_G3dPlttGetRequiredSize, NNS_G3dPlttSetPlttKey, NNS_G3dPlttLoad, NNS_G3dPlttReleasePlttKey, NNSi_G3dBindMdlTexInternal, NNS_G3dBindMdlTex, NNSi_G3dBindMdlPlttInternal, NNS_G3dBindMdlPltt, NNS_G3dBindMdlPlttEx, NNS_G3dReleaseMdlPltt
 * address:  0x02069C74
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem g3d: animation object init, render object animation lists,
 * texture and palette upload, and binding of textures and palettes to the
 * materials of a model.
 *
 * Compiler notes (the file is pinned to ../2.0/sp2):
 *  - The mask helper NNSi_G3dAnmObjCollectMapDataMask needs the 2.0 front end, which keeps the
 *    branch over the guard body that 1.1p1 would predicate.
 *  - The texture release function (NNS_G3dTexReleaseTexKey) must narrow in the
 *    expression: `(u16)(flag & ~1)` gives `bic #1`, the plain `&= ~1` costs a
 *    literal pool word.
 *  - The texture load (NNS_G3dTexLoad) reads the VRAM key as a u32 and shifts
 *    it as `(key << 16) >> 13` to get `(key & 0xffff) << 3`; the 4x4 index
 *    offset is read into a local before the first GX_LoadTex call.
 *
 * symbols:
 *   sHandlerCount  0x020A821C  data
 *   sHandlerKeys   0x020A8240  data
 *   sHandlerFns    0x020A8244  data
 *   gNNSiG3dFuncBlendVisDefault     0x020A8234  data
 *   gNNSiG3dFuncBlendJntDefault     0x020A8238  data
 *   gNNSiG3dFuncBlendMatDefault     0x020A823C  data
 *   MIi_CpuClear32  0x02082A7C  arm
 *   GX_BeginLoadTex  0x0207F7A0  arm
 *   GX_LoadTex       0x0207F7FC  arm
 *   GX_EndLoadTex    0x0207F9B4  arm
 *   GX_BeginLoadTexPltt  0x0207FA0C  arm
 *   GX_LoadTexPltt       0x0207FA40  arm
 *   GX_EndLoadTexPltt    0x0207FADC  arm
 *   FX_Div  0x0207C768  arm
 *   NNS_G3dGetResDataByName  0x0206E62C  arm
 */

#include "nns_g3d_anm_types.h"

typedef int            BOOL;

/* Header of an animation resource: the two category codes select the init handler. */
typedef struct {
    u8  category0;
    u8  dummy_;
    u16 category1;
} NNSG3dAnmFmtHeader;

/* One row of the animation init handler table (the handler pointer sits in the
 * parallel array sHandlerFns, 8 bytes per row). */
typedef struct {
    u8  category0;
    u8  pad1;
    u16 category1;
    u32 pad4;
} NNSiG3dAnmObjInitKey;

/* Render object flag set when an animation is removed from one of its lists. */
#define NNS_G3D_RENDEROBJ_FLAG_RECORD 0x10

/* Render object (0x54 bytes): the material, joint and visibility animation
 * lists, their blend functions and the masks of entries they drive. */
typedef struct {
    u32           flag;
    void         *resMdl;
    NNSG3dAnmObj *anmMat;
    void         *funcBlendMat;
    NNSG3dAnmObj *anmJnt;
    void         *funcBlendJnt;
    NNSG3dAnmObj *anmVis;
    void         *funcBlendVis;
    u8            pad20[0x1c];
    u32           recAnmMat[2];
    u32           recAnmJnt[2];
    u32           recAnmVis[2];
} NNSG3dRenderObj;

/* Resource dictionary header. */
typedef struct { u8 revision; u8 numEntry; u16 sizeDictBlk; u16 dummy_; u16 ofsEntry; } NNSG3dResDict;

typedef struct { u16 sizeUnit; u16 sizeTotal; u8 data[4]; } NNSG3dResDictEntryHeader;

typedef struct {
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u16 flag;
    u16 dummy_;
    u32 ofsTex;
} NNSG3dResTexInfo;

typedef struct {
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u16 flag;
    u16 dummy_;
    u32 ofsTex;
    u32 ofsTexPlttIdx;
} NNSG3dResTex4x4Info;

typedef struct {
    u32 vramKey;
    u16 sizePltt;
    u16 flag;
    u16 ofsDict;
    u16 dummy_;
    u32 ofsPlttData;
} NNSG3dResPlttInfo;

typedef struct {
    u32                 sig;
    u32                 size;
    NNSG3dResTexInfo    texInfo;
    NNSG3dResTex4x4Info tex4x4Info;
    NNSG3dResPlttInfo   plttInfo;
    NNSG3dResDict       dict;
} NNSG3dResTex;

typedef struct { u16 ofsDictTexToMatList; u16 ofsDictPlttToMatList; NNSG3dResDict dict; } NNSG3dResMat;

typedef struct { u32 sig; u32 size; u32 ofsMat; } NNSG3dResMdl;

/* Data record of the tex-to-material dictionary. */
typedef struct { u16 offset; u8 numIdx; u8 flag; } NNSG3dResTexToMatIdx;

/* Data record of the pltt-to-material dictionary. */
typedef struct { u16 offset; u8 numIdx; u8 flag; } NNSG3dResPlttToMatIdx;

/* Data record of the texture dictionary. */
typedef struct { u32 texImageParam; u32 extraParam; } NNSG3dResDictTexData;

/* Data record of the palette dictionary. */
typedef struct { u16 offset; u16 flag; } NNSG3dResDictPlttData;

typedef struct {
    u16 itemTag; u16 size; u32 diffAmb; u32 specEmi; u32 polyAttr; u32 polyAttrMask;
    u32 texImageParam; u32 texImageParamMask; u16 texPlttBase; u16 flag;
    u16 origWidth; u16 origHeight; fx32 magW; fx32 magH;
} NNSG3dResMatData;

typedef struct { u8 name[16]; } NNSG3dResName;

extern void MIi_CpuClear32(u32 val, void *dst, u32 len);
extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(void *src, u32 off, u32 n);
extern void GX_EndLoadTex(void);
extern void GX_BeginLoadTexPltt(void);
extern void GX_LoadTexPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);
extern void GX_EndLoadTexPltt(void);
extern u32 FX_Div(u32 a, u32 b);
extern void *NNS_G3dGetResDataByName(const NNSG3dResDict *dict, const NNSG3dResName *name);
void NNS_G3dAnmObjInit(NNSG3dAnmObj *anmObj, NNSG3dAnmFmtHeader *resAnm, u32 resMdl, u32 resTex);
void NNS_G3dRenderObjInit(NNSG3dRenderObj *rndObj, u32 resMdl);
void NNSi_G3dAnmObjInsertByPriority(NNSG3dAnmObj **head, NNSG3dAnmObj *item);
void NNSi_G3dAnmObjCollectMapDataMask(u32 *mask, NNSG3dAnmObj *anmObj);
void NNS_G3dRenderObjAddAnmObj(NNSG3dRenderObj *rndObj, NNSG3dAnmObj *anmObj);
u32 NNSi_G3dAnmObjUnlink(NNSG3dAnmObj **head, NNSG3dAnmObj *target);
void NNS_G3dRenderObjRemoveAnmObj(NNSG3dRenderObj *rndObj, NNSG3dAnmObj *anmObj);
int NNS_G3dTexGetRequiredSize(int pTex);
int NNS_G3dTex4x4GetRequiredSize(int pTex);
void NNS_G3dTexSetTexKey(NNSG3dResTex *pTex, int texKey, int tex4x4Key);
void NNS_G3dTexLoad(NNSG3dResTex *pTex, u32 exec);
void NNS_G3dTexReleaseTexKey(NNSG3dResTex *pTex, u32 *pTexKey, u32 *pTex4x4Key);
u32 NNS_G3dPlttGetRequiredSize(NNSG3dResTex *pTex);
void NNS_G3dPlttSetPlttKey(NNSG3dResTex *pTex, u32 plttKey);
void NNS_G3dPlttLoad(NNSG3dResTex *pTex, BOOL exec);
void *NNS_G3dPlttReleasePlttKey(NNSG3dResTex *pTex);
void NNSi_G3dBindMdlTexInternal(NNSG3dResMat *pMat, NNSG3dResTexToMatIdx *pBindData, const NNSG3dResTex *pTex, const NNSG3dResDictTexData *pTexData);
BOOL NNS_G3dBindMdlTex(NNSG3dResMdl *pMdl, const NNSG3dResTex *pTex);
void NNSi_G3dBindMdlPlttInternal(NNSG3dResMat *pMat, NNSG3dResPlttToMatIdx *pBindData, const NNSG3dResTex *pTex, const NNSG3dResDictPlttData *pPlttData);
BOOL NNS_G3dBindMdlPltt(NNSG3dResMdl *pMdl, const NNSG3dResTex *pTex);
int NNS_G3dBindMdlPlttEx(NNSG3dResMdl *pMdl, NNSG3dResTex *pTex, u32 plttToMatIdx, u32 plttDataIdx);
void NNS_G3dReleaseMdlPltt(NNSG3dResMdl *pMdl);
extern u32 sHandlerCount;
extern NNSiG3dAnmObjInitKey sHandlerKeys[];
extern u8 sHandlerFns[];
extern u32 gNNSiG3dFuncBlendVisDefault;
extern u32 gNNSiG3dFuncBlendJntDefault;
extern u32 gNNSiG3dFuncBlendMatDefault;


/*
 * NNS_G3dAnmObjInit: reset the animation object and call the init handler
 * whose category pair matches the resource header. The handler takes
 * (anmObj, resAnm, resMdl). The entry test must be spelled
 * `i = 0; if (i >= n) return;` for the image's `popls`.
 */
void NNS_G3dAnmObjInit(NNSG3dAnmObj *anmObj, NNSG3dAnmFmtHeader *resAnm, u32 resMdl, u32 resTex)
{
    u8 category0;
    u32 i;
    u32 n;

    anmObj->frame = 0;
    anmObj->resAnm = resAnm;
    anmObj->next = 0;
    anmObj->priority = 0x7f;
    anmObj->ratio = 0x1000;
    anmObj->resTex = (const void *)resTex;
    anmObj->numMapData = 0;
    anmObj->funcAnm = 0;

    n = sHandlerCount;
    i = 0;
    if (i >= n) return;
    category0 = resAnm->category0;
    do {
        if (category0 != sHandlerKeys[i].category0) goto next;
        if (resAnm->category1 != sHandlerKeys[i].category1) goto next;
        if (*(void (**)(NNSG3dAnmObj *, NNSG3dAnmFmtHeader *, u32))(sHandlerFns + (i << 3)) == 0) return;
        (*(void (**)(NNSG3dAnmObj *, NNSG3dAnmFmtHeader *, u32))(sHandlerFns + (i << 3)))(anmObj, resAnm, resMdl);
        return;
next:
        i++;
    } while (i < n);
}


/*
 * NNS_G3dRenderObjInit: clear the render object (0x54 bytes), store the
 * model and install the default blend functions. The literal for
 * gNNSiG3dFuncBlendMatDefault has no witness outside this function.
 */
void NNS_G3dRenderObjInit(NNSG3dRenderObj *rndObj, u32 resMdl)
{
    MIi_CpuClear32(0, rndObj, 0x54);
    rndObj->funcBlendMat = (void *)gNNSiG3dFuncBlendMatDefault;
    rndObj->funcBlendJnt = (void *)gNNSiG3dFuncBlendJntDefault;
    rndObj->funcBlendVis = (void *)gNNSiG3dFuncBlendVisDefault;
    rndObj->resMdl = (void *)resMdl;
}


/*
 * Priority-ordered insert into the singly-linked list rooted at *head,
 * highest priority first; `item` may itself be a chain, so before splicing
 * the code walks to its tail and attaches the displaced remainder there.
 *
 *  - The one-element case (*head has no next) is written out separately; that
 *    gives the `bne`/`beq` pair on one `cmp r2,#0` where the second branch
 *    re-uses the flags of the first.
 *  - The search loop is top-tested (`while (nx != 0)`); rotating it costs
 *    four bytes.
 *  - The insert guard is `nx->priority >= item->priority`; the reverse
 *    polarity is a single wrong byte (`bhs` for `blo`).
 */
void NNSi_G3dAnmObjInsertByPriority(NNSG3dAnmObj **head, NNSG3dAnmObj *item)
{
    NNSG3dAnmObj *cur;
    NNSG3dAnmObj *nx;
    NNSG3dAnmObj *tail;

    cur = *head;
    if (cur == 0) { *head = item; return; }
    nx = cur->next;
    if (nx == 0) {
        if (cur->priority > item->priority) {
            tail = item;
            if (item->next != 0) {
                do {
                    tail = tail->next;
                } while (tail->next != 0);
            }
            tail->next = cur;
            *head = item;
            return;
        }
        cur->next = item;
        return;
    }
    while (nx != 0) {
        if (nx->priority >= item->priority) {
            tail = item;
            if (item->next != 0) {
                do {
                    tail = tail->next;
                } while (tail->next != 0);
            }
            cur->next = item;
            tail->next = nx;
            return;
        }
        cur = nx;
        nx = nx->next;
    }
    cur->next = item;
}


/*
 * Walk the list from `anmObj` and, for each animation, set bit i of `mask`
 * for every mapData[i] (i < numMapData) that carries the EXIST flag.
 *
 * Needs ../2.0/sp2: the original keeps `tst r2,#0x100` / `beq` over a
 * five-instruction guard body, which dsi/1.1p1 -O4,p would predicate.
 */
void NNSi_G3dAnmObjCollectMapDataMask(u32 *mask, NNSG3dAnmObj *anmObj)
{
    s32 i;

    if (anmObj == 0) return;
    do {
        for (i = 0; i < (s32)anmObj->numMapData; i++) {
            if (anmObj->mapData[i] & NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
                mask[i >> 5] |= 1 << (i & 0x1f);
            }
        }
        anmObj = anmObj->next;
    } while (anmObj != 0);
}


/*
 * NNS_G3dRenderObjAddAnmObj: dispatch on the category byte of the animation
 * resource ('M' material, 'J' joint, 'V' visibility); each case pairs one
 * mask update with one priority insert into the matching list. The case order
 * in the source is 0x4D, 0x4A, 0x56 (the emitted compare chain tests 0x4A
 * first because the compiler reorders the tests).
 */
void NNS_G3dRenderObjAddAnmObj(NNSG3dRenderObj *rndObj, NNSG3dAnmObj *anmObj)
{
    const NNSG3dAnmFmtHeader *resAnm;

    if (anmObj == 0) return;
    resAnm = anmObj->resAnm;
    if (resAnm == 0) return;
    switch (resAnm->category0) {
    case 0x4d:
        NNSi_G3dAnmObjCollectMapDataMask(rndObj->recAnmMat, anmObj);
        NNSi_G3dAnmObjInsertByPriority(&rndObj->anmMat, anmObj);
        break;
    case 0x4a:
        NNSi_G3dAnmObjCollectMapDataMask(rndObj->recAnmJnt, anmObj);
        NNSi_G3dAnmObjInsertByPriority(&rndObj->anmJnt, anmObj);
        break;
    case 0x56:
        NNSi_G3dAnmObjCollectMapDataMask(rndObj->recAnmVis, anmObj);
        NNSi_G3dAnmObjInsertByPriority(&rndObj->anmVis, anmObj);
        break;
    }
}


/*
 * Unlink `target` from the list rooted at *head, clear the removed node's
 * next pointer and return 1 on success. `q` must be declared before `p`,
 * otherwise the trailing cursor takes r0 instead of r2. The inner unlink is
 * `p->next = q->next`, not `p->next = target->next`.
 */
u32 NNSi_G3dAnmObjUnlink(NNSG3dAnmObj **head, NNSG3dAnmObj *target)
{
    NNSG3dAnmObj *q;
    NNSG3dAnmObj *p;

    p = *head;
    if (p == 0) return 0;
    if (p == target) {
        *head = p->next;
        target->next = 0;
        return 1;
    }
    for (q = p->next; q != 0; q = q->next) {
        if (q == target) {
            p->next = q->next;
            q->next = 0;
            return 1;
        }
        p = q;
    }
    return 0;
}


/*
 * NNS_G3dRenderObjRemoveAnmObj: try the material, joint and visibility lists
 * in turn and set the RECORD flag if one of them held the node. The three
 * guards must nest so the three success paths share one flag store.
 */
void NNS_G3dRenderObjRemoveAnmObj(NNSG3dRenderObj *rndObj, NNSG3dAnmObj *anmObj)
{
    if (!NNSi_G3dAnmObjUnlink(&rndObj->anmMat, anmObj)) {
        if (!NNSi_G3dAnmObjUnlink(&rndObj->anmJnt, anmObj)) {
            if (!NNSi_G3dAnmObjUnlink(&rndObj->anmVis, anmObj)) {
                return;
            }
        }
    }
    rndObj->flag |= NNS_G3D_RENDEROBJ_FLAG_RECORD;
}


/* NNS_G3dTexGetRequiredSize: texture block size in bytes. */
int NNS_G3dTexGetRequiredSize(int pTex)
{
    return pTex ? (((NNSG3dResTex *)pTex)->texInfo.sizeTex << 3) : 0;
}


/* NNS_G3dTex4x4GetRequiredSize: 4x4 compressed texture block size in bytes. */
int NNS_G3dTex4x4GetRequiredSize(int pTex)
{
    return pTex ? (((NNSG3dResTex *)pTex)->tex4x4Info.sizeTex << 3) : 0;
}


/* NNS_G3dTexSetTexKey: store the VRAM keys of the texture and 4x4 blocks (when non-zero). */
void NNS_G3dTexSetTexKey(NNSG3dResTex *pTex, int texKey, int tex4x4Key)
{
    if (texKey) *(int *)&pTex->texInfo.vramKey = texKey;
    if (tex4x4Key) *(int *)&pTex->tex4x4Info.vramKey = tex4x4Key;
}


/*
 * NNS_G3dTexLoad: push the texture block and the 4x4 block into texture VRAM
 * and mark each as loaded. `exec` asks for the GX_BeginLoadTex /
 * GX_EndLoadTex bracket to be opened and closed here.
 *
 * The 4x4 block is uploaded twice: its index data (ofsTexPlttIdx) goes to the
 * second bank at half the size, with the offset remapped as
 *     ((off & 0x1FFFF) >> 1) + 0x20000 + ((off & 0x40000) >> 2).
 *
 * What the bytes forced:
 *  1. vramKey is a u32 read with a full-word `ldr` and narrowed by the
 *     unequal shift pair, so the offset is written `(key << 16) >> 13`.
 *  2. `hi` (the `<< 16` result) must stay its own value; the remap is derived
 *     from `hi >> 13`, not from `off`.
 *  3. ofsTexPlttIdx is read into a local before the first GX_LoadTex call.
 *  4. The two blocks use separate size locals, and ofsPlttIdx is declared
 *     before tex4x4Size.
 */
void NNS_G3dTexLoad(NNSG3dResTex *pTex, u32 exec)
{
    u32 texSize;
    u32 ofsPlttIdx;
    u32 hi;
    u32 off;
    u32 tex4x4Size;

    if (exec != 0) {
        GX_BeginLoadTex();
    }
    texSize = pTex->texInfo.sizeTex << 3;
    if (texSize != 0) {
        GX_LoadTex((u8 *)pTex + pTex->texInfo.ofsTex, (pTex->texInfo.vramKey << 16) >> 13, texSize);
        pTex->texInfo.flag = (u16)(pTex->texInfo.flag | 1);
    }
    tex4x4Size = pTex->tex4x4Info.sizeTex << 3;
    if (tex4x4Size != 0) {
        hi = pTex->tex4x4Info.vramKey << 16;
        off = hi >> 13;
        ofsPlttIdx = pTex->tex4x4Info.ofsTexPlttIdx;
        GX_LoadTex((u8 *)pTex + pTex->tex4x4Info.ofsTex, off, tex4x4Size);
        GX_LoadTex((u8 *)pTex + ofsPlttIdx,
                   (((hi >> 13) & 0x1FFFF) >> 1) + 0x20000
                       + ((off & 0x40000) >> 2),
                   tex4x4Size >> 1);
        pTex->tex4x4Info.flag = (u16)(pTex->tex4x4Info.flag | 1);
    }
    if (exec != 0) {
        GX_EndLoadTex();
    }
}


/*
 * NNS_G3dTexReleaseTexKey: for each non-null out-pointer, clear the block's
 * loaded bit, hand back its VRAM key and zero it. Both halves are leaf code
 * (no unconditional dereference). The AND must be narrowed inside the
 * expression.
 */
void NNS_G3dTexReleaseTexKey(NNSG3dResTex *pTex, u32 *pTexKey, u32 *pTex4x4Key)
{
    if (pTexKey != 0) {
        pTex->texInfo.flag = (u16)(pTex->texInfo.flag & ~1);
        *pTexKey = pTex->texInfo.vramKey;
        pTex->texInfo.vramKey = 0;
    }
    if (pTex4x4Key != 0) {
        pTex->tex4x4Info.flag = (u16)(pTex->tex4x4Info.flag & ~1);
        *pTex4x4Key = pTex->tex4x4Info.vramKey;
        pTex->tex4x4Info.vramKey = 0;
    }
}


/* NNS_G3dPlttGetRequiredSize: palette block size in bytes (sizePltt is in 8-byte units). */
u32 NNS_G3dPlttGetRequiredSize(NNSG3dResTex *pTex)
{
    return pTex ? ((u32)pTex->plttInfo.sizePltt << 3) : 0;
}


/* NNS_G3dPlttSetPlttKey: store the VRAM key of the palette block. */
void NNS_G3dPlttSetPlttKey(NNSG3dResTex *pTex, u32 plttKey){ pTex->plttInfo.vramKey = plttKey; }


/*
 * NNS_G3dPlttLoad: bracket with GX_BeginLoadTexPltt / GX_EndLoadTexPltt when
 * exec is set, upload the palette block at pTex + ofsPlttData to the slot
 * from the VRAM key, set the loaded bit in plttInfo.flag. Both bracket calls
 * take no argument; passing any keeps registers live and costs 9 bytes.
 */
void NNS_G3dPlttLoad(NNSG3dResTex *pTex, BOOL exec)
{
    if (exec) {
        GX_BeginLoadTexPltt();
    }
    {
        u32 szByte;
        const void *pPlttData;
        u32 destSlotAddr;

        szByte       = (u32)pTex->plttInfo.sizePltt << 3;
        pPlttData    = (u8 *)pTex + pTex->plttInfo.ofsPlttData;
        destSlotAddr = (pTex->plttInfo.vramKey & 0xffff) << 3;
        GX_LoadTexPltt(pPlttData, destSlotAddr, szByte);
    }
    pTex->plttInfo.flag |= 1;
    if (exec) {
        GX_EndLoadTexPltt();
    }
}


/*
 * NNS_G3dPlttReleasePlttKey: clear the "loaded" bit of plttInfo.flag, detach
 * the palette VRAM key and return the old key.
 *
 * Needs ../2.0/sp2: the image materialises the store's zero early (`mov r1, #0`
 * between the `ldrh` and the `bic`) and loads the key after the flag
 * read-modify-write; 1.1p1 hoists the key load instead.
 */
void *NNS_G3dPlttReleasePlttKey(NNSG3dResTex *pTex)
{
    u32 oldKey;
    u32 flag = pTex->plttInfo.flag;

    pTex->plttInfo.flag = (u16)(flag & ~1u);
    oldKey = pTex->plttInfo.vramKey;
    pTex->plttInfo.vramKey = 0;
    return (void *)oldKey;
}


static inline void *NNS_G3dGetResDataByIdx(const NNSG3dResDict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const NNSG3dResDictEntryHeader *hdr = (const NNSG3dResDictEntryHeader *)((const u8 *)dict + dict->ofsEntry);
        return (void *)((const u8 *)hdr + 4 + hdr->sizeUnit * idx);
    }
    return 0;
}


static inline NNSG3dResMatData *NNS_G3dGetMatDataByIdx(NNSG3dResMat *mat, u32 idx)
{
    if (mat) {
        u32 *data = (u32 *)NNS_G3dGetResDataByIdx(&mat->dict, idx);
        if (data)
            return (NNSG3dResMatData *)((u8 *)mat + *data);
    }
    return 0;
}


static inline u32 NNS_GfdGetTexKeyAddr(u32 key)
{
    return (u32)((key & 0xffff) << 3);
}


/*
 * bindMdlTex_Internal_ (static helper of NNS_G3dBindMdlTex): for every
 * material index in a tex-to-material bind record, ORs the texture's
 * TEXIMAGE_PARAM (plus the VRAM key address >> 3) into the material and sets
 * magW/magH to width/origWidth and height/origHeight as fx32 (FX32_ONE fast
 * path, else FX_Div). The key comes from texInfo.vramKey or, for a
 * 4x4-compressed texture (texfmt field == 5 << 26), tex4x4Info.vramKey.
 *
 * The body must be written with the real inlines: the NNS_G3dGetMatDataByIdx
 * guard around NNS_G3dGetResDataByIdx and NNS_GfdGetTexKeyAddr followed by
 * `>> 3` (the pair folds to the `bic #0xe0000000`).
 */
void NNSi_G3dBindMdlTexInternal(NNSG3dResMat *pMat, NNSG3dResTexToMatIdx *pBindData, const NNSG3dResTex *pTex, const NNSG3dResDictTexData *pTexData)
{
    u8 *base;
    u32 vramOffset;
    u32 j;

    base = (u8 *)pMat + pBindData->offset;

    if ((pTexData->texImageParam & 0x1c000000) != 0x14000000)
        vramOffset = NNS_GfdGetTexKeyAddr(pTex->texInfo.vramKey) >> 3;
    else
        vramOffset = NNS_GfdGetTexKeyAddr(pTex->tex4x4Info.vramKey) >> 3;

    for (j = 0; j < pBindData->numIdx; ++j) {
        NNSG3dResMatData *matData = NNS_G3dGetMatDataByIdx(pMat, base[j]);
        u32 width, height;

        matData->texImageParam |= pTexData->texImageParam + vramOffset;
        width = pTexData->extraParam & 0x7ff;
        height = (pTexData->extraParam & (0x7ff << 11)) >> 11;
        matData->magW = (width == matData->origWidth) ? 0x1000 : FX_Div((fx32)(width << 12), (fx32)(matData->origWidth << 12));
        matData->magH = (height == matData->origHeight) ? 0x1000 : FX_Div((fx32)(height << 12), (fx32)(matData->origHeight << 12));
    }
    pBindData->flag |= 1;
}


/* NNS_G3dGetMat. Written as an if/return: the ternary form swaps two registers. */
static inline NNSG3dResMat *NNS_G3dGetMat(NNSG3dResMdl *mdl)
{
    if (mdl != 0 && mdl->ofsMat != 0) return (NNSG3dResMat *)((u8 *)mdl + mdl->ofsMat);
    return 0;
}


static inline const NNSG3dResName *NNS_G3dGetResNameByIdx(const NNSG3dResDict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const NNSG3dResDictEntryHeader *hdr = (const NNSG3dResDictEntryHeader *)((const u8 *)dict + dict->ofsEntry);
        return (const NNSG3dResName *)((const u8 *)hdr + hdr->sizeTotal) + idx;
    }
    return 0;
}


static inline void *NNS_G3dGetTexDataByName(const NNSG3dResTex *tex, const NNSG3dResName *name)
{
    if (tex)
        return NNS_G3dGetResDataByName(&tex->dict, name);
    return 0;
}


/*
 * NNS_G3dBindMdlTex(mdl, tex): for every entry of the material block's
 * tex-to-material dictionary, looks the entry's name up in the texture's
 * dictionary (NNS_G3dGetResDataByName = NNS_G3dGetResDataByName) and, when found and
 * not already bound (flag bit 0), binds it through NNSi_G3dBindMdlTexInternal. Returns
 * FALSE if any name was missing.
 */
BOOL NNS_G3dBindMdlTex(NNSG3dResMdl *pMdl, const NNSG3dResTex *pTex)
{
    NNSG3dResMat *mat;
    NNSG3dResDict *dict;
    u32 i;
    BOOL result = 1;

    mat = NNS_G3dGetMat(pMdl);
    dict = (NNSG3dResDict *)((u8 *)mat + mat->ofsDictTexToMatList);

    for (i = 0; i < dict->numEntry; ++i) {
        const NNSG3dResName *name = NNS_G3dGetResNameByIdx(dict, i);
        void *texData = NNS_G3dGetTexDataByName(pTex, name);
        if (texData) {
            NNSG3dResTexToMatIdx *data = (NNSG3dResTexToMatIdx *)NNS_G3dGetResDataByIdx(dict, i);
            if (!(data->flag & 1))
                NNSi_G3dBindMdlTexInternal(mat, data, pTex, texData);
        } else {
            result = 0;
        }
    }
    return result;
}


static inline u32 NNS_GfdGetPlttKeyAddr(u32 key)
{
    return (u32)((key & 0xffff) << 3);
}


/*
 * bindMdlPltt_Internal_ (static helper of NNS_G3dBindMdlPltt): for every
 * material index in a pltt-to-material bind record, stores plttBase + the
 * palette key address into the material's texPlttBase, both halved when the
 * palette is not a 4-colour one (flag bit 0 clear); marks the record bound.
 *
 * plttBase and vramOffset must be u16 locals, with
 * vramOffset = (u16)(NNS_GfdGetPlttKeyAddr(key) >> 3), and the material
 * lookup must be the NNS_G3dGetMatDataByIdx inline.
 */
void NNSi_G3dBindMdlPlttInternal(NNSG3dResMat *pMat, NNSG3dResPlttToMatIdx *pBindData, const NNSG3dResTex *pTex, const NNSG3dResDictPlttData *pPlttData)
{
    u8 *base;
    u16 plttBase;
    u16 vramOffset;
    u32 j;

    base = (u8 *)pMat + pBindData->offset;
    plttBase = pPlttData->offset;
    vramOffset = (u16)(NNS_GfdGetPlttKeyAddr(pTex->plttInfo.vramKey) >> 3);

    if (!(pPlttData->flag & 1)) {
        plttBase >>= 1;
        vramOffset >>= 1;
    }
    for (j = 0; j < pBindData->numIdx; ++j) {
        NNSG3dResMatData *matData = NNS_G3dGetMatDataByIdx(pMat, base[j]);
        matData->texPlttBase = (u16)(plttBase + vramOffset);
    }
    pBindData->flag |= 1;
}


static inline void *NNS_G3dGetPlttDataByName(const NNSG3dResTex *tex, const NNSG3dResName *name)
{
    if (tex && tex->plttInfo.ofsDict != 0)
        return NNS_G3dGetResDataByName((const NNSG3dResDict *)((const u8 *)tex + tex->plttInfo.ofsDict), name);
    return 0;
}


/*
 * NNS_G3dBindMdlPltt(mdl, tex): the palette twin of NNS_G3dBindMdlTex. Walks the
 * pltt-to-material dictionary, looks each name up in the texture's palette
 * dictionary (only when plttInfo.ofsDict is non-zero) and binds through
 * NNSi_G3dBindMdlPlttInternal.
 */
BOOL NNS_G3dBindMdlPltt(NNSG3dResMdl *pMdl, const NNSG3dResTex *pTex)
{
    NNSG3dResMat *mat;
    NNSG3dResDict *dict;
    u32 i;
    BOOL result = 1;

    mat = NNS_G3dGetMat(pMdl);
    dict = (NNSG3dResDict *)((u8 *)mat + mat->ofsDictPlttToMatList);

    for (i = 0; i < dict->numEntry; ++i) {
        const NNSG3dResName *name = NNS_G3dGetResNameByIdx(dict, i);
        void *plttData = NNS_G3dGetPlttDataByName(pTex, name);
        if (plttData) {
            NNSG3dResPlttToMatIdx *data = (NNSG3dResPlttToMatIdx *)NNS_G3dGetResDataByIdx(dict, i);
            if (!(data->flag & 1))
                NNSi_G3dBindMdlPlttInternal(mat, data, pTex, plttData);
        } else {
            result = 0;
        }
    }
    return result;
}


/*
 * NNS_G3dBindMdlPlttEx: bind one palette (plttDataIdx of the texture's
 * palette dictionary) to one pltt-to-material record (plttToMatIdx of the
 * model's material dictionary) through NNSi_G3dBindMdlPlttInternal, unless the record is
 * already bound. Returns 1 when it bound.
 *
 * Needs ../2.0/sp2: the image writes the zero result of the palette lookup
 * out twice, once per arm (`mov r3, #0` at +0x60 and +0x68); 1.1p1 cross-jumps
 * the two arms into one. Goto, else-if, hoisted initialiser and the duplicated
 * else below all fold the same way under 1.1p1.
 */
int NNS_G3dBindMdlPlttEx(NNSG3dResMdl *pMdl, NNSG3dResTex *pTex, u32 plttToMatIdx, u32 plttDataIdx)
{
    NNSG3dResMat  *mat;
    NNSG3dResDict *matDict;
    NNSG3dResDictPlttData *plttData;
    NNSG3dResPlttToMatIdx *bindData;

    mat = (pMdl != 0 && pMdl->ofsMat != 0) ? (NNSG3dResMat *)((u8 *)pMdl + pMdl->ofsMat) : 0;
    matDict = (NNSG3dResDict *)((u8 *)mat + mat->ofsDictPlttToMatList);

    if (pTex != 0 && pTex->plttInfo.ofsDict != 0) {
        NNSG3dResDict *plttDict = (NNSG3dResDict *)((u8 *)pTex + pTex->plttInfo.ofsDict);
        if (plttDict != 0 && plttDataIdx < plttDict->numEntry) {
            u16 ofsEntry = plttDict->ofsEntry;
            plttData = (NNSG3dResDictPlttData *)((u8 *)plttDict + ofsEntry + 4
                         + *(u16 *)((u8 *)plttDict + ofsEntry) * plttDataIdx);
        } else {
            plttData = 0;
        }
    } else {
        plttData = 0;
    }
    if (matDict != 0 && plttToMatIdx < matDict->numEntry) {
        u16 ofsEntry = matDict->ofsEntry;
        u16 sizeUnit = *(u16 *)((u8 *)matDict + ofsEntry);
        bindData = (NNSG3dResPlttToMatIdx *)((u8 *)matDict + ofsEntry + 4 + sizeUnit * plttToMatIdx);
    } else {
        bindData = 0;
    }

    if (bindData != 0 && !(bindData->flag & 1)) {
        NNSi_G3dBindMdlPlttInternal(mat, bindData, pTex, plttData);
        return 1;
    }
    return 0;
}


/*
 * NNS_G3dReleaseMdlPltt: clear the "bound" bit (flag bit 0) of every record
 * of the model's pltt-to-material dictionary. The bound is re-read through
 * `volatile` for the fresh `ldrb`, the entry test compares against the
 * counter, and the clear is masked at full width `(u8)(flag & ~1u)`.
 */
void NNS_G3dReleaseMdlPltt(NNSG3dResMdl *pMdl)
{
    NNSG3dResMat  *pMat;
    NNSG3dResDict *pDict;
    u32            entryIdx;

    pMat = (pMdl != 0 && pMdl->ofsMat != 0) ? (NNSG3dResMat *)((u8 *)pMdl + pMdl->ofsMat) : 0;
    pDict = (NNSG3dResDict *)((u8 *)pMat + pMat->ofsDictPlttToMatList);

    entryIdx = 0;
    if (pDict->numEntry <= entryIdx)
        return;

    do {
        NNSG3dResPlttToMatIdx *pData;
        if (pDict != 0 && entryIdx < *(volatile u8 *)&pDict->numEntry) {
            u16 ofsEntry = pDict->ofsEntry;
            u16 sizeUnit = *(u16 *)((char *)pDict + ofsEntry);
            pData = (NNSG3dResPlttToMatIdx *)((char *)pDict + ofsEntry + 4 + sizeUnit * entryIdx);
        } else {
            pData = 0;
        }
        entryIdx++;
        if (pData->flag & 1) {
            pData->flag = (u8)(pData->flag & ~1u);
        }
    } while (entryIdx < pDict->numEntry);
}
