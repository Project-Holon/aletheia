/*
 * file:     nns_g3d_mdl.c
 * unit:     yes
 * function: NNS_G3dAllocRenderObj, NNS_G3dFreeRenderObj, NNS_G3dAllocAnmObj, NNS_G3dFreeAnmObj, NNS_G3dMdlSetMdlLightEnableFlag, NNS_G3dMdlSetMdlPolygonMode, NNS_G3dMdlSetMdlCullMode, NNS_G3dMdlSetMdlPolygonID, NNS_G3dMdlSetMdlAlpha, NNS_G3dMdlSetMdlPolygonIDAll
 * address:  0x0206E348
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GetTaggedPayloadSize    0x02069C14  arm
 *   NNS_FndAllocFromAllocator    0x02061330  arm
 *   NNS_FndFreeToAllocator  0x02061344  arm
 */
#include "../types.h"

#include "../sdk_nnsfnd.h"

/* NNSG3dResMat: two list offsets, then the material dictionary. */
typedef struct {
    u16 ofsDictTexToMatList;
    u16 ofsDictPlttToMatList;
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} ResMat;

/* NNSG3dResMdl: block offsets, then the model info (numMat at +0x18). */
typedef struct {
    u32 size;
    u32 ofsSbc;
    u32 ofsMat;
    u8  unused0c[0xC];
    u8  numMat;
} ResMdl;

/* Dictionary data record: offset of the material relative to ResMat. */
typedef struct {
    u32 ofsMatData;
} ResDictData;

/* NNSG3dResMatData: polygon attribute word at +0x0C. */
typedef struct {
    u32 unused00[3];
    u32 polyAttr;
} ResMatData;

/* GXPOLYGONATTR fields */
#define POLYATTR_LIGHT_MASK    0x0000000fu
#define POLYATTR_MODE_SHIFT    4
#define POLYATTR_MODE_MASK     0x00000030u
#define POLYATTR_CULL_SHIFT    6
#define POLYATTR_CULL_MASK     0x000000c0u
#define POLYATTR_ALPHA_SHIFT   16
#define POLYATTR_ALPHA_MASK    0x001f0000u
#define POLYATTR_ID_SHIFT      24
#define POLYATTR_ID_MASK       0x3f000000u

#include "nns_gfd_vram_manager.h"
struct NNSiFndObject;
#include "nns_g2d_font.h"
void *NNS_G3dAllocRenderObj(struct NNSFndAllocator *pAllocator);
void NNS_G3dFreeRenderObj(struct NNSFndAllocator *pAllocator, void *pRenderObj);
void *NNS_G3dAllocAnmObj(struct NNSFndAllocator *pAllocator, const u8 *pAnm, const ResMdl *pMdl);
void NNS_G3dFreeAnmObj(struct NNSFndAllocator *pAllocator, void *pAnmObj);
void NNS_G3dMdlSetMdlLightEnableFlag(ResMdl *pMdl, u32 matIdx, u32 lightMask);
void NNS_G3dMdlSetMdlPolygonMode(ResMdl *pMdl, u32 matIdx, u32 polygonMode);
void NNS_G3dMdlSetMdlCullMode(ResMdl *pMdl, u32 matIdx, u32 cullMode);
void NNS_G3dMdlSetMdlPolygonID(ResMdl *pMdl, u32 matIdx, u32 polygonId);
void NNS_G3dMdlSetMdlAlpha(ResMdl *pMdl, u32 matIdx, u32 alpha);
void NNS_G3dMdlSetMdlPolygonIDAll(ResMdl *pMdl, u32 polygonId);

/* NNS_G3dAllocRenderObj: 0x54 bytes from the allocator. */
void *NNS_G3dAllocRenderObj(struct NNSFndAllocator *pAllocator){ return NNS_FndAllocFromAllocator((NNSiFndObject *)pAllocator, 0x54); }

/* NNS_G3dFreeRenderObj */
void NNS_G3dFreeRenderObj(struct NNSFndAllocator *pAllocator, void *pRenderObj){ NNS_FndFreeToAllocator((struct NNSiFndObject *)pAllocator, (u32)pRenderObj); }

/*
 * NNS_G3dAllocAnmObj: forwards the two tail arguments through GetTaggedPayloadSize and hands the result,
 * with the first argument, to NNS_FndAllocFromAllocator -- the argument shuffle is why the
 * first parameter moves into r4 before either call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dAllocAnmObj.c \
 *       --func NNS_G3dAllocAnmObj --addr 0x0206E364 --cc 1.1p1 --arm
 */
void *NNS_G3dAllocAnmObj(struct NNSFndAllocator *pAllocator, const u8 *pAnm, const ResMdl *pMdl)
{
    return NNS_FndAllocFromAllocator((NNSiFndObject *)pAllocator, GetTaggedPayloadSize(pAnm, (const TaggedNode *)pMdl));
}

/* NNS_G3dFreeAnmObj */
void NNS_G3dFreeAnmObj(struct NNSFndAllocator *pAllocator, void *pAnmObj){ NNS_FndFreeToAllocator((struct NNSiFndObject *)pAllocator, (u32)pAnmObj); }

/*
 * A family of five near-identical bitfield setters over the same inlined
 * two-step resolve: root -> bank (relative offset at +0x08), bank -> entry
 * (indexed table at bank+4+off0A, element stride read as a u16 at that same
 * address), entry -> node (relative offset at entry+0). The five differ only
 * in which field of node->attr0C they clear and set:
 *   NNS_G3dMdlSetMdlLightEnableFlag  bits 0..3     (mask 0x0000000f, shift 0)
 *   NNS_G3dMdlSetMdlPolygonMode  bits 4..5     (mask 0x00000030, shift 4)
 *   NNS_G3dMdlSetMdlCullMode  bits 6..7     (mask 0x000000c0, shift 6)
 *   NNS_G3dMdlSetMdlPolygonID  bits 24..29   (mask 0x3f000000, shift 24)
 *   NNS_G3dMdlSetMdlAlpha  bits 16..20   (mask 0x001f0000, shift 16)
 * NNS_G3dMdlSetMdlPolygonIDAll (already EXACT, next packet boundary) loops NNS_G3dMdlSetMdlPolygonID.
 *
 * Two shape notes that cost the derivation real time:
 *  - Every NULL arm shares ONE tail (`n = 0` at the very end), so each early
 *    bail has to be a `goto` to that block; writing them as nested else arms
 *    predicates `moveq r1,#0` at the top instead of branching to +0x60.
 *  - The resolved entry pointer is carried in the `idx` PARAMETER's register
 *    (r1), not in a fresh local: declaring a separate `Ent *e` allocates r0
 *    and flips `mla r1,r0,r1,r3` to `mla r0,r1,r0,r3`. Reassigning `idx`
 *    itself is what reproduces the original register choice.
 *
 * No proc hint for this packet; compiled with the default arm946e. No
 * interworking-conflict or constant-materialisation tell was observed, so
 * docs/FRONTEND-PINS.md does not apply here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0206E394.c \
 *       --addr 0x0206E394 --arm
 */
void NNS_G3dMdlSetMdlLightEnableFlag(ResMdl *pMdl, u32 matIdx, u32 lightMask)
{
    ResMat *pMat;
    ResMatData *pMatData;
    u8 *pDict;

    pMat = (pMdl != 0 && pMdl->ofsMat != 0) ? (ResMat *)((u8 *)pMdl + pMdl->ofsMat) : 0;
    if (pMat == 0) goto none;
    pDict = (u8 *)pMat + 4;
    if (pDict == 0) goto nullent;
    if (matIdx >= pMat->numEntry) goto nullent;
    matIdx = (u32)(pDict + pMat->ofsEntry + 4 + (*(u16 *)(pDict + pMat->ofsEntry)) * matIdx);
    goto have;
nullent:
    matIdx = 0;
have:
    if (matIdx == 0) goto none;
    pMatData = (ResMatData *)((u8 *)pMat + ((ResDictData *)matIdx)->ofsMatData);
    goto set;
none:
    pMatData = 0;
set:
    pMatData->polyAttr = (pMatData->polyAttr & ~POLYATTR_LIGHT_MASK) | lightMask;
}

void NNS_G3dMdlSetMdlPolygonMode(ResMdl *pMdl, u32 matIdx, u32 polygonMode)
{
    ResMat *pMat;
    ResMatData *pMatData;
    u8 *pDict;

    pMat = (pMdl != 0 && pMdl->ofsMat != 0) ? (ResMat *)((u8 *)pMdl + pMdl->ofsMat) : 0;
    if (pMat == 0) goto none;
    pDict = (u8 *)pMat + 4;
    if (pDict == 0) goto nullent;
    if (matIdx >= pMat->numEntry) goto nullent;
    matIdx = (u32)(pDict + pMat->ofsEntry + 4 + (*(u16 *)(pDict + pMat->ofsEntry)) * matIdx);
    goto have;
nullent:
    matIdx = 0;
have:
    if (matIdx == 0) goto none;
    pMatData = (ResMatData *)((u8 *)pMat + ((ResDictData *)matIdx)->ofsMatData);
    goto set;
none:
    pMatData = 0;
set:
    pMatData->polyAttr = (pMatData->polyAttr & ~POLYATTR_MODE_MASK) | (polygonMode << POLYATTR_MODE_SHIFT);
}

void NNS_G3dMdlSetMdlCullMode(ResMdl *pMdl, u32 matIdx, u32 cullMode)
{
    ResMat *pMat;
    ResMatData *pMatData;
    u8 *pDict;

    pMat = (pMdl != 0 && pMdl->ofsMat != 0) ? (ResMat *)((u8 *)pMdl + pMdl->ofsMat) : 0;
    if (pMat == 0) goto none;
    pDict = (u8 *)pMat + 4;
    if (pDict == 0) goto nullent;
    if (matIdx >= pMat->numEntry) goto nullent;
    matIdx = (u32)(pDict + pMat->ofsEntry + 4 + (*(u16 *)(pDict + pMat->ofsEntry)) * matIdx);
    goto have;
nullent:
    matIdx = 0;
have:
    if (matIdx == 0) goto none;
    pMatData = (ResMatData *)((u8 *)pMat + ((ResDictData *)matIdx)->ofsMatData);
    goto set;
none:
    pMatData = 0;
set:
    pMatData->polyAttr = (pMatData->polyAttr & ~POLYATTR_CULL_MASK) | (cullMode << POLYATTR_CULL_SHIFT);
}

void NNS_G3dMdlSetMdlPolygonID(ResMdl *pMdl, u32 matIdx, u32 polygonId)
{
    ResMat *pMat;
    ResMatData *pMatData;
    u8 *pDict;

    pMat = (pMdl != 0 && pMdl->ofsMat != 0) ? (ResMat *)((u8 *)pMdl + pMdl->ofsMat) : 0;
    if (pMat == 0) goto none;
    pDict = (u8 *)pMat + 4;
    if (pDict == 0) goto nullent;
    if (matIdx >= pMat->numEntry) goto nullent;
    matIdx = (u32)(pDict + pMat->ofsEntry + 4 + (*(u16 *)(pDict + pMat->ofsEntry)) * matIdx);
    goto have;
nullent:
    matIdx = 0;
have:
    if (matIdx == 0) goto none;
    pMatData = (ResMatData *)((u8 *)pMat + ((ResDictData *)matIdx)->ofsMatData);
    goto set;
none:
    pMatData = 0;
set:
    pMatData->polyAttr = (pMatData->polyAttr & ~POLYATTR_ID_MASK) | (polygonId << POLYATTR_ID_SHIFT);
}

void NNS_G3dMdlSetMdlAlpha(ResMdl *pMdl, u32 matIdx, u32 alpha)
{
    ResMat *pMat;
    ResMatData *pMatData;
    u8 *pDict;

    pMat = (pMdl != 0 && pMdl->ofsMat != 0) ? (ResMat *)((u8 *)pMdl + pMdl->ofsMat) : 0;
    if (pMat == 0) goto none;
    pDict = (u8 *)pMat + 4;
    if (pDict == 0) goto nullent;
    if (matIdx >= pMat->numEntry) goto nullent;
    matIdx = (u32)(pDict + pMat->ofsEntry + 4 + (*(u16 *)(pDict + pMat->ofsEntry)) * matIdx);
    goto have;
nullent:
    matIdx = 0;
have:
    if (matIdx == 0) goto none;
    pMatData = (ResMatData *)((u8 *)pMat + ((ResDictData *)matIdx)->ofsMatData);
    goto set;
none:
    pMatData = 0;
set:
    pMatData->polyAttr = (pMatData->polyAttr & ~POLYATTR_ALPHA_MASK) | (alpha << POLYATTR_ALPHA_SHIFT);
}

/*
 * Walks the count byte at +0x18, calling NNS_G3dMdlSetMdlPolygonID with the counter and the
 * caller's second argument; the counter is zeroed before the entry test (which
 * is why the original's `mov r4, #0` precedes `cmp`/`popls`) and the count is
 * re-read from memory every iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dMdlSetMdlPolygonIDAll.c \
 *       --func NNS_G3dMdlSetMdlPolygonIDAll --addr 0x0206E5EC --cc 1.1p1 --arm
 */
void NNS_G3dMdlSetMdlPolygonIDAll(ResMdl *pMdl, u32 polygonId)
{
    u32 matIdx = 0;
    for (matIdx = 0; matIdx < pMdl->numMat; matIdx++) {
        NNS_G3dMdlSetMdlPolygonID(pMdl, matIdx, polygonId);
    }
}
