/*
 * file:     nns_g2d_oam_manager_2.c
 * unit:     yes
 * function: func_02063078, func_02063138, func_02063294, func_02063378, func_0206343C, func_02063640
 * address:  0x02063078
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
 *   MIi_CpuClear16  0x02082A48  arm
 *   g_02146BC8      0x02146BC8  data
 *   g_02146BC4      0x02146BC4  data  a2
 *   g_020A81E4     0x020A81E4  data  a4
 *   func_020862F0  0x020862F0  arm
 *   func_0207E684  0x0207E684  arm
 *   func_0207E708  0x0207E708  arm
 *   g_020A84C0     0x020A84C0  data  a4
 *   func_020862B8  0x020862B8  arm
 *   func_020821C0  0x020821C0  arm
 *   func_02082A7C  0x02082A7C  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short s16;

typedef int s32;

typedef s32 fx32;

typedef union {
    struct { u16 attr0; u16 attr1; u16 attr2; u16 attr3; };
    struct { u32 attr01; u32 attr23; };
    struct {
        u32 y:8; u32 rsMode:2; u32 objMode:2; u32 mosaic:1; u32 colorMode:1; u32 shape:2;
        u32 x:9; u32 rsParam:5; u32 size:2;
        u32 charNo:10; u32 priority:2; u32 cParam:4; u32 _3:16;
    };
} GXOamAttr;

typedef struct OamAttributeCache {
    u16 reservationTable[128];
    GXOamAttr oamBuffer[128];
} OamAttributeCache;

typedef struct OamAffineCache {
    u16 reservationTable[32];
} OamAffineCache;

typedef struct OamCache {
    OamAttributeCache attributeCache;
    OamAffineCache affineCache;
} OamCache;

struct Span {
    u32 which;
    u16 first;
    u16 last;
    u16 cur;
    u16 afirst;
    u16 alast;
    u16 acur;
    u16 id;
    u16 pad_12;
    u32 live;
};

struct Win02063294 { u32 bank; u16 min_oam; u16 max_oam; u16 cur_oam; };

typedef int BOOL;

typedef struct { fx32 _00, _01, _10, _11; } MtxFx22;

typedef struct {
    u16 _0, _1, _2; s16 PA;
    u16 _4, _5, _6; s16 PB;
    u16 _8, _9, _10; s16 PC;
    u16 _12, _13, _14; s16 PD;
} GXOamAffine;

typedef enum { NNS_G2D_OAMTYPE_MAIN = 0, NNS_G2D_OAMTYPE_SUB = 1, NNS_G2D_OAMTYPE_SOFTWAREEMULATION = 2 } NNSG2dOamType;

typedef struct NNSG2dOAMManageArea {
    u16 fromIdx;
    u16 toIdx;
    u16 currentIdx;
} NNSG2dOAMManageArea;

typedef struct NNSG2dOamManagerInstance {
    NNSG2dOamType type;
    NNSG2dOAMManageArea managedAttrArea;
    NNSG2dOAMManageArea managedAffineArea;
    u16 GUID;
    u16 pad16_;
    BOOL bFastTransferEnable;
    fx32 spriteZoffsetStep;
} NNSG2dOamManagerInstance;

typedef void (OBJLoadFunction)(const void *pSrc, u32 offset, u32 szByte);

extern void MIi_CpuClear16(u16 data, void *dest, u32 size);
extern void func_020862F0(const void *startAddr, u32 nBytes);         /* DC_FlushRange */
extern void func_0207E684(const void *pSrc, u32 offset, u32 szByte);  /* GX_LoadOAM */
extern void func_0207E708(const void *pSrc, u32 offset, u32 szByte);  /* GXS_LoadOAM */
extern void func_020862B8(const void *startAddr, u32 nBytes);          /* DC_InvalidateRange */
extern void func_020821C0(u32 dmaNo, void *dest, u32 data, u32 size, BOOL flag);  /* MIi_DmaFill32 */
extern void func_02082A7C(u32 data, void *dest, u32 size);            /* MIi_CpuClear32 */
void func_02063078(void);
u32 func_02063138(struct Span *s, u16 first, u16 count, u32 which);
u32 func_02063294(struct Win02063294 *win, GXOamAttr *src, u32 mode);
u16 func_02063378(NNSG2dOamManagerInstance *pMan, const MtxFx22 *mtx);
void func_0206343C(NNSG2dOamManagerInstance *pMan, u32 bound);
void func_02063640(NNSG2dOamManagerInstance *pMan);
extern OamCache g_02146BC8[3];
extern u16 g_02146BC4;
extern OBJLoadFunction *g_020A81E4[5];  /* GetOBJLoadFunction_'s funcTbl */
extern u32 g_020A84C0;                  /* GXi_DmaId */






/*
 * The cell/OAM bank reset: nine MIi_CpuClear16 calls that blank all three
 * 0x540-byte bank records of g_02146BC8 -- the OAM mirror at +0x100 (0x400
 * bytes, fill 0xC0) and the two free-slot tables, slotsA at +0x000 (0x100
 * bytes) and slotsB at +0x500 (0x40 bytes), both filled with the 0xFFFF
 * free sentinel that func_02063138 tests for.
 *
 * COMPILER PIN, ../2.0/sp2, the cluster's "kept constants" tell.  The image
 * rematerialises each call's fill value and size into r0/r2 at every one of
 * the nine sites (`mov r0,#0xc0` at 0x02063080/0x02063090/0x020630A0, then
 * `ldr r0,[pc,#0x68]` naming the same 0xFFFF pool word at 0x0206311C six
 * times over, and `mov r2,#0x40` at 0x020630E4/0x020630F4/0x02063104) and
 * spends no callee-saved register at all: `push {r3, lr}` / `pop {r3, pc}`.
 * dsi/1.1p1 -O4,p CSEs 0xFFFF into r5 and 0x40 into r4 and holds both live
 * across the call chain, widening the prologue to `push {r3, r4, r5, lr}`
 * and replacing each rematerialisation with `mov r0,r5` / `mov r2,r4`:
 * same 192 bytes, 30 concrete out.  Under the pin this identical C is 0
 * mismatches on the first compile.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02063078.c \
 *       --func func_02063078 --addr 0x02063078 --cc ../2.0/sp2 --arm
 */
void func_02063078(void)
{
    MIi_CpuClear16(0xC0, g_02146BC8[0].attributeCache.oamBuffer, 0x400);
    MIi_CpuClear16(0xC0, g_02146BC8[1].attributeCache.oamBuffer, 0x400);
    MIi_CpuClear16(0xC0, g_02146BC8[2].attributeCache.oamBuffer, 0x400);
    MIi_CpuClear16(0xFFFF, g_02146BC8[0].attributeCache.reservationTable, 0x100);
    MIi_CpuClear16(0xFFFF, g_02146BC8[1].attributeCache.reservationTable, 0x100);
    MIi_CpuClear16(0xFFFF, g_02146BC8[2].attributeCache.reservationTable, 0x100);
    MIi_CpuClear16(0xFFFF, g_02146BC8[0].affineCache.reservationTable, 0x40);
    MIi_CpuClear16(0xFFFF, g_02146BC8[1].affineCache.reservationTable, 0x40);
    MIi_CpuClear16(0xFFFF, g_02146BC8[2].affineCache.reservationTable, 0x40);
}






static inline void Fill(u16 *tbl, u16 first, u16 last, u16 id)
{
    MIi_CpuClear16(id, (u8 *)tbl + first * 2, (last - first + 1) * 2);
}






static inline u32 IsFree(u16 *tbl, u16 first, u16 last)
{
    u16 *p = &tbl[first];
    u16 *end = &tbl[last];
    for (; p <= end; p++) {
        if (*p != 0xFFFF)
            return 0;
    }
    return 1;
}






/*
 * Reserves a span of OAM entries in bank g_02146BC8[which]: checks that
 * slotsA[first..last] are all free (0xFFFF), stamps them with the next
 * allocation id out of g_02146BC4, then does the same on the coarse
 * slotsB table at 1/4 granularity, fills the span record *s and returns 1
 * (0 as soon as either range is taken).
 *
 * WHAT CLOSED IT (wave 10), from 165 bytes out: the body is two inline
 * helpers used twice each, IsFree(tbl, first, last) (a pointer walk from
 * &tbl[first] to &tbl[last]) and Fill(tbl, first, last, id) (the
 * MIi_CpuClear16 call), with each check written `if (IsFree(..)) {...}
 * else return 0;` -- then-block first, which is what gives the image's two
 * branched-to `mov r0,#0; pop` failure tails.  Two register levers on top:
 *  - Fill's destination is spelled `(u8 *)tbl + first * 2`, a different
 *    expression from IsFree's `&tbl[first]`, so the image recomputes the
 *    address (`add r1, r4, r7, lsl #1`) instead of carrying a CSE copy
 *    across the loop;
 *  - the coarse table base is bound to a local (`coarse = bank->slotsB`),
 *    which becomes the image's in-place `add r4, r4, #0x500`.
 * ../2.0/sp2 as for the rest of the cluster.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02063138.c
 *       --func func_02063138 --addr 0x02063138 --arm --cc ../2.0/sp2
 */
u32 func_02063138(struct Span *s, u16 first, u16 count, u32 which)
{
    OamCache *bank = &g_02146BC8[which];
    u16 last = first + (count - 1);
    u16 afirst, alast;
    u16 *coarse;

    if (IsFree(bank->attributeCache.reservationTable, first, last)) {
        s->id = g_02146BC4++;
        s->first = first;
        s->last = last;
        s->cur = first;
        Fill(bank->attributeCache.reservationTable, first, last, s->id);
    } else {
        return 0;
    }

    afirst = first >> 2;
    alast = afirst + ((u16)(count >> 2) - 1);
    coarse = bank->affineCache.reservationTable;
    if (IsFree(coarse, afirst, alast)) {
        s->afirst = afirst;
        s->alast = alast;
        s->acur = afirst;
        Fill(coarse, afirst, alast, s->id);
    } else {
        return 0;
    }

    s->live = 1;
    s->which = which;
    return 1;
}





/*
 * Writes one OAM entry (attr0/attr1/attr2) into the next free slot of a
 * reserved span of bank g_02146BC8[win->bank]'s OAM shadow (+0x100), and,
 * when the entry is affine (rsMode bit 0) and mode != 0xFFFE, stamps the
 * affine parameter index into attr1 bits 9-13.  Returns 1, or 0 when the
 * span is full.
 *
 * WHAT CLOSED IT (wave 10), after 16 hand spellings at 13 bytes out:
 *  1. The permuter's split-assign(ptr): `ptr = g_02146BC8; ptr = ptr +
 *     win->bank * 0x540;` -- two statements on ONE variable -- coalesces the
 *     mla's addend with its destination (image `mla ip, r4, r3, ip`), which
 *     the one-expression spelling never does.  The "mla destination is not
 *     source-addressable" wall of cluster_02063000.h was a declarations
 *     question here.  (13 -> 7 bytes out.)
 *  2. The attribute read-modify-write is the SDK GXOamAttr bitfield union:
 *     `if (dst->rsMode & 1) dst->rsParam = mode;`.  The shift pair
 *     (<<22, >>30) is the 2-bit rsMode field at bits 8-9 and the 0x3E000000
 *     mask is the 5-bit rsParam at bits 25-29; the explicit shift/mask
 *     spelling puts the loaded word and the test in swapped registers.
 *     (7 -> 0.)
 * dsi/1.1p1 is 220 bytes (it predicates the count block): the ../2.0/sp2
 * "kept branches" pin, as for the rest of the cluster.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02063294.c
 *       --func func_02063294 --addr 0x02063294 --arm --cc ../2.0/sp2
 */
u32 func_02063294(struct Win02063294 *win, GXOamAttr *src, u32 mode)
{
    u16 max_oam = win->max_oam;
    u16 cur_oam = *(volatile u16 *)&win->cur_oam;
    u32 valid = 0;
    u32 count;
    u32 ge;
    u8 *ptr;
    u32 idx;
    if (!((int)cur_oam > (int)max_oam + 1)) {
        if (win->min_oam <= max_oam) valid = 1;
    }
    if (valid == 0) count = 0;
    else count = (u16)(max_oam - cur_oam + 1);
    if (count >= 1) ge = 1; else ge = 0;
    if (ge == 0) goto fail;
    ptr = (u8 *)g_02146BC8;
    ptr = ptr + win->bank * 0x540;
    idx = win->cur_oam;
    ptr = ptr + 0x100;
    {
        GXOamAttr *dst = (GXOamAttr *)(ptr + idx * 8);
        dst->attr0 = src->attr0;
        dst->attr1 = src->attr1;
        dst->attr2 = src->attr2;
        if (mode != 0xFFFE) {
            if (dst->rsMode & 1) {
                dst->rsParam = mode;
            }
        }
    }
    win->cur_oam = win->cur_oam + 1;
    return 1;
fail:
    return 0;
}




static inline BOOL IsManageAreaValid_(const NNSG2dOAMManageArea *pArea)
{
    return (BOOL)((pArea->currentIdx <= pArea->toIdx + 1) &&
                  (pArea->fromIdx <= pArea->toIdx));
}




static inline OamCache *GetOamCachePtr_(NNSG2dOamType type)
{
    return &g_02146BC8[type];
}




static inline GXOamAttr *GetOamBufferPtr_(NNSG2dOamType type, u16 index)
{
    {
        OamCache *pOamCache = GetOamCachePtr_(type);

        return pOamCache->attributeCache.oamBuffer + index;
    }
}




static inline GXOamAffine *GetAffineBufferPtr_(NNSG2dOamType type, u16 index)
{
    {
        GXOamAffine *pAff = (GXOamAffine *)GetOamBufferPtr_(type, 0);

        return pAff + index;
    }
}




static inline u16 GetCapacity_(const NNSG2dOAMManageArea *pArea)
{
    if (IsManageAreaValid_(pArea)) {
        return (u16)((int)pArea->toIdx - pArea->currentIdx + 1);
    } else {
        return 0;
    }
}




static inline BOOL HasEnoughCapacity_(const NNSG2dOAMManageArea *pArea, u16 num)
{
    return (BOOL)(GetCapacity_(pArea) >= num);
}




static inline void G2_SetOBJAffine(GXOamAffine *oam, const MtxFx22 *mtx)
{
    oam->PA = (s16)(mtx->_00 >> 4);
    oam->PB = (s16)(mtx->_01 >> 4);
    oam->PC = (s16)(mtx->_10 >> 4);
    oam->PD = (s16)(mtx->_11 >> 4);
}




static inline void SetAffineParams_(NNSG2dOamType type, const MtxFx22 *mtx, u16 idx)
{
    {
        GXOamAffine *pAff = GetAffineBufferPtr_(type, idx);

        G2_SetOBJAffine(pAff, mtx);
    }
}




/*
 * NitroSystem g2d_OAM.c NNS_G2dEntryOamManagerAffine(pMan, mtx) -> u16:
 * if the managed affine area has room for one more entry, write the 2x2
 * matrix (each term >> 4, the TwlSDK G2_SetOBJAffine inline) into the
 * GXOamAffine slot at managedAffineArea.currentIdx of oamCache_[pMan->type]
 * (g_02146BC8, three 0x540-byte OamCache records), bump currentIdx and
 * return the old index; otherwise NNS_G2D_OAM_AFFINE_IDX_NONE (0xFFFE).
 *
 * Closed in wave 13 on the first compile of the library body with its
 * inlines (IsManageAreaValid_, GetCapacity_, HasEnoughCapacity_,
 * GetOamCachePtr_, GetOamBufferPtr_, GetAffineBufferPtr_, SetAffineParams_,
 * G2_SetOBJAffine) and the NitroSDK GXOamAttr / GXOamAffine types.  The
 * "mla destination wall" earlier waves measured (22 spellings, the
 * permuter, 5 then 4 bytes) was the inline boundaries: the buffer address
 * comes out of GetAffineBufferPtr_(type, 0) + index, which is what keeps
 * base, destination and index in three registers.  ../2.0/sp2 and sp2p2
 * identical; 1.1p1 is 188 bytes.
 */
u16 func_02063378(NNSG2dOamManagerInstance *pMan, const MtxFx22 *mtx)
{
    if (HasEnoughCapacity_(&pMan->managedAffineArea, 1)) {
        const u16 currentAffineIdx = pMan->managedAffineArea.currentIdx;

        SetAffineParams_(pMan->type, mtx, currentAffineIdx);

        pMan->managedAffineArea.currentIdx++;

        return currentAffineIdx;
    } else {
        return 0xFFFE;
    }
}



static inline OBJLoadFunction *GetOBJLoadFunction_(NNSG2dOamType type)
{
    return g_020A81E4[type];
}



static inline void LoadOneAffine_(const GXOamAffine *pAff, u32 offset, OBJLoadFunction *pOBJLoadFunc)
{
    offset += sizeof(u16) * 3;

    (*pOBJLoadFunc)(&pAff->PA, offset + sizeof(GXOamAttr) * 0, sizeof(u16));
    (*pOBJLoadFunc)(&pAff->PB, offset + sizeof(GXOamAttr) * 1, sizeof(u16));
    (*pOBJLoadFunc)(&pAff->PC, offset + sizeof(GXOamAttr) * 2, sizeof(u16));
    (*pOBJLoadFunc)(&pAff->PD, offset + sizeof(GXOamAttr) * 3, sizeof(u16));
}



static inline void LoadOamAndAffineFast_(NNSG2dOamType type, u16 fromIdx, u16 toIdx)
{
    GXOamAttr *pFrom = GetOamBufferPtr_(type, fromIdx);
    const u16 szByte = (u16)(sizeof(GXOamAttr) * (toIdx - fromIdx + 1));
    u16 offset = (u16)(sizeof(GXOamAttr) * fromIdx);

    func_020862F0(pFrom, szByte);

    switch (type) {
    case NNS_G2D_OAMTYPE_MAIN:
        func_0207E684(pFrom, offset, szByte);
        break;
    case NNS_G2D_OAMTYPE_SUB:
        func_0207E708(pFrom, offset, szByte);
        break;
    default:
        break;
    }
}



static inline void LoadOam_(NNSG2dOamType type, u16 fromIdx, u16 toIdx)
{
    GXOamAttr *pFrom = GetOamBufferPtr_(type, fromIdx);
    const u16 numArea = (u16)(toIdx - fromIdx + 1);
    u16 offset = (u16)(sizeof(GXOamAttr) * fromIdx);
    u16 i;
    OBJLoadFunction *pOBJLoadFunc = GetOBJLoadFunction_(type);

    for (i = 0; i < numArea; i++) {
        (*pOBJLoadFunc)(pFrom, offset, sizeof(u16) * 3);

        offset += sizeof(GXOamAttr);
        pFrom++;
    }
}



static inline void LoadAffine_(NNSG2dOamType type, u16 fromIdx, u16 toIdx)
{
    GXOamAffine *pFrom = GetAffineBufferPtr_(type, fromIdx);
    const u16 numArea = (u16)(toIdx - fromIdx + 1);
    u16 offset = (u16)(sizeof(GXOamAffine) * fromIdx);
    u16 i;
    OBJLoadFunction *pOBJLoadFunc = GetOBJLoadFunction_(type);

    for (i = 0; i < numArea; i++) {
        LoadOneAffine_(pFrom, offset, pOBJLoadFunc);

        offset += sizeof(GXOamAffine);
        pFrom++;
    }
}



/*
 * NitroSystem g2d_OAM.c NNS_G2dApplyOamManagerToHW(pMan).  Fast-transfer
 * managers: LoadOamAndAffineFast_ (DC_FlushRange func_020862F0 over the
 * span, then GX_LoadOAM func_0207E684 or GXS_LoadOAM func_0207E708 by
 * type).  Otherwise LoadOam_ pushes each entry's three attribute halfwords
 * through the per-type loader, and when the affine area is valid
 * LoadAffine_ pushes PA..PD of each GXOamAffine (LoadOneAffine_) the same
 * way.  g_020A81E4 is GetOBJLoadFunction_'s static funcTbl
 * { CpuLoadOAMMain_ = sub_02063068, CpuLoadOAMSub_ = sub_02063054, 0, 0, 0 }.
 *
 * Closed in wave 13 on the first compile of the library body with its
 * inlines; the wave-10 transcription sat at 99 out on callee-saved
 * allocation, which was the inline boundaries.  ../2.0/sp2 and sp2p2
 * identical; 1.1p1 is 508 bytes.
 */
void func_0206343C(NNSG2dOamManagerInstance *pMan, u32 bound)
{
    {
        if (pMan->bFastTransferEnable) {
            LoadOamAndAffineFast_(pMan->type,
                                  pMan->managedAttrArea.fromIdx,
                                  pMan->managedAttrArea.toIdx);
        } else {
            LoadOam_(pMan->type,
                     pMan->managedAttrArea.fromIdx,
                     pMan->managedAttrArea.toIdx);

            if (IsManageAreaValid_(&pMan->managedAffineArea)) {
                LoadAffine_(pMan->type,
                            pMan->managedAffineArea.fromIdx,
                            pMan->managedAffineArea.toIdx);
            }
        }
    }
}


static inline u32 GX_GetDefaultDMA(void)
{
    return (g_020A84C0 > 3) ? (u32)~0 : g_020A84C0;
}


static inline void MI_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size)
{
    func_020821C0(dmaNo, dest, data, size, 1);
}


static inline void MI_CpuFill32(void *dest, u32 data, u32 size)
{
    func_02082A7C(data, dest, size);
}


static inline void NNSi_G2dDmaFill32(u32 dmaNo, void *dest, u32 data, u32 size)
{
    if (dmaNo != (u32)~0) {
        MI_DmaFill32(dmaNo, dest, data, size);
    } else {
        MI_CpuFill32(dest, data, size);
    }
}


static inline GXOamAttr *GetOamFromPtr_(NNSG2dOamManagerInstance *pMan)
{
    {
        GXOamAttr *pFrom = GetOamBufferPtr_(pMan->type, pMan->managedAttrArea.fromIdx);

        return pFrom;
    }
}


static inline u32 GetSizeOfManageArea_(const NNSG2dOAMManageArea *pArea)
{
    if (IsManageAreaValid_(pArea)) {
        return (u32)(sizeof(GXOamAttr) * (u16)(pArea->toIdx - pArea->fromIdx + 1));
    } else {
        return 0;
    }
}


static inline void ResetOam_(NNSG2dOamType type, u16 fromIdx, u16 toIdx)
{
    GXOamAttr *pFrom = GetOamBufferPtr_(type, fromIdx);
    const u16 numArea = (u16)(toIdx - fromIdx + 1);
    u16 i;

    for (i = 0; i < numArea; i++) {
        *((u16 *)pFrom) = 192;
        pFrom++;
    }
}


/*
 * NitroSystem g2d_OAM.c NNS_G2dResetOamManagerBuffer(pMan).  Fast-transfer
 * managers: DC_InvalidateRange (func_020862B8) over the managed OAM span,
 * then NNSi_G2dDmaFill32(NNS_G2D_DMA_NO, span, 0xC0, size) -- MIi_DmaFill32
 * (func_020821C0, five arguments, the fifth on the stack) on the default
 * DMA channel, MIi_CpuClear32 (func_02082A7C) when GX_GetDefaultDMA()
 * reports GX_DMA_NOT_USE; otherwise ResetOam_ writes 0xC0 into attr0 of
 * each entry.  Both cursors are then rewound to fromIdx.
 *
 * g_020A84C0 is GXi_DmaId; this build's GX_GetDefaultDMA clamps it,
 * `id > 3 ? GX_DMA_NOT_USE : id` (the image's `cmp #3 / mvnhi`), so the
 * register-held -1 the wave-10 notes chased is the SDK's own sentinel.
 * Closed in wave 13 on the first compile of the library body and inlines
 * (GetSizeOfManageArea_, GetOamFromPtr_, GetOamBufferPtr_, ResetOam_,
 * NNSi_G2dDmaFill32, MI_DmaFill32, MI_CpuFill32): the "mla destination"
 * residue was the inline boundary.  ../2.0/sp2 and sp2p2 identical; 1.1p1
 * is 320 bytes.
 */
void func_02063640(NNSG2dOamManagerInstance *pMan)
{
    {
        if (pMan->bFastTransferEnable) {
            const u32 szByte = GetSizeOfManageArea_(&pMan->managedAttrArea);
            void *pData = GetOamFromPtr_(pMan);

            func_020862B8(pData, szByte);
            NNSi_G2dDmaFill32(GX_GetDefaultDMA(), pData, 192, szByte);

        } else {
            ResetOam_(pMan->type,
                      pMan->managedAttrArea.fromIdx,
                      pMan->managedAttrArea.toIdx);
        }
    }

    {
        pMan->managedAttrArea.currentIdx = pMan->managedAttrArea.fromIdx;
        pMan->managedAffineArea.currentIdx = pMan->managedAffineArea.fromIdx;
    }
}
