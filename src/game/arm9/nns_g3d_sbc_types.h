/*
 * nns_g3d_sbc_types.h: NitroSystem g3d Sbc interpreter (nns_g3d_sbc.c):
 * geometry FIFO registers, callee declarations and the inline resource
 * accessors the Sbc command handlers share.  The render state (NNSG3dRS),
 * the render object and the resource item layouts live in
 * nns_g3d_anm_calc_types.h; the global state (NNS_G3dGlb) lives in
 * nns_g3d_glb_types.h.
 *
 * symbols:
 *   NNS_G3dGlbGetInvCameraMtx  0x0206AAD4  arm  arm9
 *   NNS_G3dGlbGetWVMtx  0x0206ADBC  arm  arm9
 *   NNS_G3dGlbGetInvWVMtx  0x0206ADF4  arm  arm9
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm  arm9
 *   NNS_G3dGeSendDL  0x0206DC00  arm  arm9
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm  arm9
 *   G3X_GetClipMtx  0x0207DC98  arm  arm9
 *   MIi_CpuSend32  0x02082AA8  arm  arm9
 */
#ifndef NNS_G3D_SBC_TYPES_H
#define NNS_G3D_SBC_TYPES_H

#include "nns_g3d_anm_calc_types.h"
#include "nns_g3d_glb_types.h"

/* Geometry engine ports. */
#define GXFIFO           (*(volatile u32 *)0x04000400)
#define REG_MTX_MODE     (*(volatile u32 *)0x04000440)
#define REG_MTX_STORE    (*(volatile u32 *)0x0400044C)
#define REG_MTX_RESTORE  (*(volatile u32 *)0x04000450)
#define REG_MTX_IDENTITY (*(volatile u32 *)0x04000454)

/* Geometry engine command ids used by the handlers. */
#define GECMD_MTX_MODE    0x10
#define GECMD_MTX_RESTORE 0x14
#define GECMD_MTX_STORE   0x13

/*
 * The static command block of a billboard handler: a packed command word, two
 * parameter words, then the 4x3 matrix and the scale vector that follow them in
 * the GXFIFO stream.
 */
typedef struct BillboardCmdBlock {
    u32     cmd;
    u32     params[2];
    MtxFx43 mtx;
    VecFx32 scale;
} BillboardCmdBlock;

/* Option bits of an Sbc command byte (top three bits): MTX_RESTORE before, MTX_STORE after. */
#define NNS_G3D_SBC_OPT_RESTORE(opt) ((opt) == 0x40 || (opt) == 0x60)
#define NNS_G3D_SBC_OPT_STORE(opt)   ((opt) == 0x20 || (opt) == 0x60)

/* Geometry engine helpers in other files. */
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
extern void NNS_G3dGeFlushBuffer(void);
extern int  G3X_GetClipMtx(MtxFx44 *pClipMtx);
extern u32 *NNS_G3dGlbGetWVMtx(void);
extern u32 *NNS_G3dGlbGetInvWVMtx(void);
extern u32 *NNS_G3dGlbGetInvCameraMtx(void);
extern void NNS_G3dGeSendDL(const u32 *pDisplayList, u32 size);
extern void func_0207B5C0(const MtxFx43 *pSrc, MtxFx44 *pDst);
extern void func_0207BE14(const MtxFx44 *pA, const MtxFx44 *pB, MtxFx44 *pAB);
extern fx32 func_0207CBD0(const VecFx32 *pVec);
extern void MIi_CpuSend32(const void *pSrc, volatile void *pDst, u32 size);

/* Index into a dictionary: the data address of entry idx, or 0. */
static inline void *NNSi_G3dGetResDataByIdx(const NNSG3dResDict *pDict, u32 idx)
{
    if (pDict && idx < pDict->numEntry) {
        const NNSG3dResDictEntryHdr *pHdr =
            (const NNSG3dResDictEntryHdr *)((const u8 *)pDict + pDict->ofsEntry);

        return (void *)((u32)pHdr + sizeof(NNSG3dResDictEntryHdr) + pHdr->sizeUnit * idx);
    }
    return 0;
}

static inline const NNSG3dResMatData *NNSi_G3dGetMatDataByIdx(const NNSG3dResMat *pMat, u32 idx)
{
    if (pMat) {
        const u32 *pOfs = (const u32 *)NNSi_G3dGetResDataByIdx(&pMat->dict, idx);

        if (pOfs)
            return (const NNSG3dResMatData *)((const u8 *)pMat + *pOfs);
    }
    return 0;
}

static inline const NNSG3dResShpData *NNSi_G3dGetShpDataByIdx(const NNSG3dResShp *pShp, u32 idx)
{
    if (pShp) {
        const u32 *pOfs = (const u32 *)NNSi_G3dGetResDataByIdx(&pShp->dict, idx);

        if (pOfs)
            return (const NNSG3dResShpData *)((const u8 *)pShp + *pOfs);
    }
    return 0;
}

static inline const NNSG3dResNodeData *NNSi_G3dGetNodeDataByIdx(const NNSG3dResDict *pDict, u32 idx)
{
    if (pDict) {
        const u32 *pOfs = (const u32 *)NNSi_G3dGetResDataByIdx(pDict, idx);

        if (pOfs)
            return (const NNSG3dResNodeData *)((const u8 *)pDict + *pOfs);
    }
    return 0;
}

/* Callback timing of command cmd: 0 when no callback is installed. */
static inline u32 NNSi_G3dCheckPossibilityOfCallback(NNSG3dRS *pRS, u32 cmd)
{
    return pRS->cbVecFunc[cmd] ? pRS->cbVecTiming[cmd] : 0;
}

/* Timing 1 (before the command): returns nonzero when the callback asked to skip it. */
static inline u32 NNSi_G3dCallBackCheckA(NNSG3dRS *pRS, u32 cmd, u32 *pTiming)
{
    if (*pTiming == 1) {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        (*pRS->cbVecFunc[cmd])(pRS);
        *pTiming = NNSi_G3dCheckPossibilityOfCallback(pRS, cmd);
        return pRS->flag & NNS_G3D_RSFLAG_SKIP;
    }
    return 0;
}

/* Timing 2 (between the command's stages). */
static inline u32 NNSi_G3dCallBackCheckB(NNSG3dRS *pRS, u32 cmd, u32 *pTiming)
{
    if (*pTiming == 2) {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        (*pRS->cbVecFunc[cmd])(pRS);
        *pTiming = NNSi_G3dCheckPossibilityOfCallback(pRS, cmd);
        return pRS->flag & NNS_G3D_RSFLAG_SKIP;
    }
    return 0;
}

/* Timing 3 (after the command). */
static inline u32 NNSi_G3dCallBackCheckC(NNSG3dRS *pRS, u32 cmd, u32 timing)
{
    if (timing == 3) {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        (*pRS->cbVecFunc[cmd])(pRS);
        return pRS->flag & NNS_G3D_RSFLAG_SKIP;
    }
    return 0;
}

#endif
