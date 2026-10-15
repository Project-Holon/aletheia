/*
 * function: func_02063640
 * address:  0x02063640
 * packet:   pkt_02063000
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146BC8     0x02146BC8  data  a4
 *   GXi_DmaId     0x020A84C0  data  a4
 *   func_020862B8  0x020862B8  arm
 *   MIi_DmaFill32  0x020821C0  arm
 *   func_02082A7C  0x02082A7C  arm
 *
 * NitroSystem g2d_OAM.c NNS_G2dResetOamManagerBuffer(pMan).  Fast-transfer
 * managers: DC_InvalidateRange (func_020862B8) over the managed OAM span,
 * then NNSi_G2dDmaFill32(NNS_G2D_DMA_NO, span, 0xC0, size) -- MIi_DmaFill32
 * (MIi_DmaFill32, five arguments, the fifth on the stack) on the default
 * DMA channel, MIi_CpuClear32 (func_02082A7C) when GX_GetDefaultDMA()
 * reports GX_DMA_NOT_USE; otherwise ResetOam_ writes 0xC0 into attr0 of
 * each entry.  Both cursors are then rewound to fromIdx.
 *
 * GXi_DmaId is GXi_DmaId; this build's GX_GetDefaultDMA clamps it,
 * `id > 3 ? GX_DMA_NOT_USE : id` (the image's `cmp #3 / mvnhi`), so the
 * register-held -1 the wave-10 notes chased is the SDK's own sentinel.
 * Closed in wave 13 on the first compile of the library body and inlines
 * (GetSizeOfManageArea_, GetOamFromPtr_, GetOamBufferPtr_, ResetOam_,
 * NNSi_G2dDmaFill32, MI_DmaFill32, MI_CpuFill32): the "mla destination"
 * residue was the inline boundary.  ../2.0/sp2 and sp2p2 identical; 1.1p1
 * is 320 bytes.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef int BOOL;
typedef s32 fx32;

typedef struct { fx32 _00, _01, _10, _11; } MtxFx22;

typedef union {
    struct { u16 attr0; u16 attr1; u16 attr2; u16 attr3; };
    struct { u32 attr01; u32 attr23; };
    struct {
        u32 y:8; u32 rsMode:2; u32 objMode:2; u32 mosaic:1; u32 colorMode:1; u32 shape:2;
        u32 x:9; u32 rsParam:5; u32 size:2;
        u32 charNo:10; u32 priority:2; u32 cParam:4; u32 _3:16;
    };
} GXOamAttr;

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

extern OamCache g_02146BC8[3];          /* oamCache_ */

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

extern u32 GXi_DmaId;                  /* GXi_DmaId */
extern void func_020862B8(const void *startAddr, u32 nBytes);          /* DC_InvalidateRange */
extern void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL flag);  /* MIi_DmaFill32 */
extern void func_02082A7C(u32 data, void *dest, u32 size);            /* MIi_CpuClear32 */

static inline u32 GX_GetDefaultDMA(void)
{
    return (GXi_DmaId > 3) ? (u32)~0 : GXi_DmaId;
}

static inline void MI_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size)
{
    MIi_DmaFill32(dmaNo, dest, data, size, 1);
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
