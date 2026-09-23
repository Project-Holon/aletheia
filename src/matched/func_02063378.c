/*
 * function: func_02063378
 * address:  0x02063378
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
 *
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
