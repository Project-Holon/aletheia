/*
 * function: func_0206343C
 * address:  0x0206343C
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
 *   g_020A81E4     0x020A81E4  data  a4
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   GX_LoadOAM  0x0207E684  arm
 *   GXS_LoadOAM  0x0207E708  arm
 *
 * NitroSystem g2d_OAM.c NNS_G2dApplyOamManagerToHW(pMan).  Fast-transfer
 * managers: LoadOamAndAffineFast_ (DC_FlushRange DWCi_ScreenDC_FlushRange over the
 * span, then GX_LoadOAM GX_LoadOAM or GXS_LoadOAM GXS_LoadOAM by
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

typedef void (OBJLoadFunction)(const void *pSrc, u32 offset, u32 szByte);

extern OBJLoadFunction *g_020A81E4[5];  /* GetOBJLoadFunction_'s funcTbl */
extern void DWCi_ScreenDC_FlushRange(const void *startAddr, u32 nBytes);         /* DC_FlushRange */
extern void GX_LoadOAM(const void *pSrc, u32 offset, u32 szByte);  /* GX_LoadOAM */
extern void GXS_LoadOAM(const void *pSrc, u32 offset, u32 szByte);  /* GXS_LoadOAM */

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

    DWCi_ScreenDC_FlushRange(pFrom, szByte);

    switch (type) {
    case NNS_G2D_OAMTYPE_MAIN:
        GX_LoadOAM(pFrom, offset, szByte);
        break;
    case NNS_G2D_OAMTYPE_SUB:
        GXS_LoadOAM(pFrom, offset, szByte);
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
