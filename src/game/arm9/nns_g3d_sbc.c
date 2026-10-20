/*
 * file:     nns_g3d_sbc.c
 * unit:     yes
 * function: NNSi_G3dSbcRun, NNSi_G3dRenderObjRunSbc, NNSi_G3dAnmObjMarkExistMap, NNS_G3dDraw, NNSi_G3dFuncSbc_NOP, NNSi_G3dFuncSbc_RET, NNSi_G3dFuncSbc_NODE, NNSi_G3dFuncSbc_MTX, NNSi_G3dFuncSbc_MAT_InternalDefault, NNSi_G3dFuncSbc_MAT, NNSi_G3dFuncSbc_SHP_InternalDefault, NNSi_G3dFuncSbc_SHP, NNSi_G3dFuncSbc_NODEDESC, NNSi_G3dFuncSbc_BB, NNSi_G3dFuncSbc_BBY, NNSi_G3dFuncSbc_NODEMIX, NNSi_G3dFuncSbc_CALLDL, NNSi_G3dFuncSbc_POSSCALE, NNSi_G3dFuncSbc_ENVMAP, NNSi_G3dFuncSbc_PRJMAP
 * address:  0x0206B458
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gSbcFuncTable      0x020A83B8  data
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   gJntScaleFuncTable        0x020A829C  data
 *   gJntMtxFuncTable        0x020A8290  data
 *   gMatTexMtxFuncTable        0x020A82A8  data
 *   gCurrentRS      0x02148DB0  data
 *   MIi_CpuClear32   0x02082A7C  arm
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   gMatAnmResultScratch     0x02148DB4  data
 *   gMatColorMaskTable     0x020A1954  data
 *   gMatHandlerTable   0x020A82C8  data
 *   gShpHandlerTable   0x020A82D8  data
 *   gPivotAxisTable     0x020A1974  data
 *   NNS_G3dGeSendDL  0x0206DC00  arm
 *   MI_Zero36B  0x020834A8  thumb
 *   gBillboardCmd     0x020A8328  data
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   G3X_GetClipMtx  0x0207DC98  arm
 *   NNS_G3dGlbGetWVMtx  0x0206ADBC  arm
 *   NNS_G3dGlbGetInvWVMtx  0x0206ADF4  arm
 *   NNS_G3dGlbGetInvCameraMtx  0x0206AAD4  arm
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   MTX_Concat44  0x0207BE14  arm
 *   VEC_Mag  0x0207CBD0  arm
 *   MIi_CpuSend32  0x02082AA8  arm
 *   gBillboardYCmd     0x020A8370  data
 *   gEvpCache     0x0214A1B4  data
 *   gTexImageParamCmd     0x020A82B8  data
 *   gPrjMapTexMtx     0x020A82E8  data
 *   VEC_Normalize  0x0207CCA4  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   G3_MultMtx43  0x0207D918  arm
 *   G3_MultMtx33  0x0207D934  arm
 *   G3X_GetVectorMtx  0x0207DCC8  arm
 *   G3_LoadMtx43  0x0207D8E0  arm
 *   NNS_G3dGeResetGX  0x0206DE88  arm
 *   NNS_G3dGlb                   0x02148B4C  data
 */
#include "nns_g3d_sbc_types.h"
#include "../sdk_ioreg_reg.h"
#include "../sdk_ioreg.h"

typedef void (*NNSG3dSbcFunc)(NNSG3dRS *pRS, u32 opt);

/* Inverse bind matrices of one node (resource layout, 0x54 bytes). */
typedef struct NNSG3dEvpMtx {
    MtxFx43 invM;
    MtxFx33 invN;
} NNSG3dEvpMtx;

/* Cached envelope matrices of one node (0x64 bytes). */
typedef struct NNSG3dEvpCache {
    MtxFx44 M;
    MtxFx33 N;
} NNSG3dEvpCache;

/* Two static TEXIMAGE_PARAM command pairs: packed op word, then its parameter. */
typedef struct TexImageParamCmd {
    u32 op0;
    u32 param0;
    u32 op1;
    u32 param1;
} TexImageParamCmd;

extern void MIi_CpuClearFast(u32 value, void *pDst, u32 size);
extern void MIi_CpuClear32(u32 value, void *pDst, u32 size);
extern void MI_Zero36B(void *pDst);
#include "fx_vec.h"
#include "g3imm.h"
typedef int GXFogBlend;
typedef int GXFogSlope;
#include "g3x.h"
#include "nns_g3d_ge.h"
void NNSi_G3dSbcRun(NNSG3dRS *pRS);
void NNSi_G3dRenderObjRunSbc(NNSG3dRS *pRS, NNSG3dRenderObj *pRenderObj);
void NNSi_G3dAnmObjMarkExistMap(u32 *pExistMap, NNSG3dAnmObj *pAnmObj);
void NNS_G3dDraw(NNSG3dRenderObj *pRenderObj);
void NNSi_G3dFuncSbc_NOP(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_RET(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_NODE(NNSG3dRS *pRS);
void NNSi_G3dFuncSbc_MTX(NNSG3dRS *pRS);
void NNSi_G3dFuncSbc_MAT_InternalDefault(NNSG3dRS *pRS, u32 opt, const NNSG3dResMatData *pMatData, u32 idMat);
void NNSi_G3dFuncSbc_MAT(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_SHP_InternalDefault(NNSG3dRS *pRS, u32 opt, const NNSG3dResShpData *pShp, u32 idxShp);
void NNSi_G3dFuncSbc_SHP(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_NODEDESC(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_BB(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_BBY(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_NODEMIX(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_CALLDL(NNSG3dRS *pRS);
void NNSi_G3dFuncSbc_POSSCALE(NNSG3dRS *pRS, u32 which);
void NNSi_G3dFuncSbc_ENVMAP(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_PRJMAP(NNSG3dRS *pRS, u32 opt);
/* Sbc command handlers, indexed by the low five bits of the command byte. */
extern NNSG3dSbcFunc gSbcFuncTable[];
/* Joint scale and joint matrix functions, indexed by the model's scaling rule. */
extern NNSG3dJntScaleFunc gJntScaleFuncTable[];
extern NNSG3dFuncJntMtx gJntMtxFuncTable[];
/* Texture matrix functions, indexed by the model's texture matrix mode. */
extern NNSG3dFuncMatTexMtx gMatTexMtxFuncTable[];
/* The render state of the draw in progress, 0 outside a draw. */
extern NNSG3dRS *gCurrentRS;
/* Scratch material results used for materials that have no recorded slot. */
extern NNSG3dMatAnmResult gMatAnmResultScratch[];
/* Mask table selecting which colour bits the material overrides, indexed by a 3-bit material flag field. */
extern u32 gMatColorMaskTable[];
/* Pivot rotation layout: for each pivot index the four matrix cells of the A, B, C, D terms. */
extern const u8 gPivotAxisTable[][4];
extern BillboardCmdBlock gBillboardCmd;
extern BillboardCmdBlock gBillboardYCmd;
extern NNSG3dEvpCache gEvpCache[];
extern TexImageParamCmd gTexImageParamCmd;
extern MtxFx44 gPrjMapTexMtx;


/*
 * The Sbc interpreter loop: clear RSFLAG_SKIP, read the command byte through
 * the stream pointer, dispatch its low five bits through the handler table with
 * the top three bits as the option argument, and repeat until a handler raises
 * RSFLAG_RETURN.  2.0/sp2 pin: under dsi/1.1p1 the same source is 72 bytes with
 * 9 concrete bytes out (the state pointer takes r0 and the object argument is
 * deferred).
 */
void NNSi_G3dSbcRun(NNSG3dRS *pRS)
{
    u32 cmd;

    do {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        cmd = NNS_G3D_SBC_BYTE(pRS, 0);
        gSbcFuncTable[cmd & 0x1f](pRS, cmd & 0xe0u);
    } while ((pRS->flag & NNS_G3D_RSFLAG_RETURN) == 0);
}


/*
 * Initialises a render state for a render object and runs its Sbc stream:
 * zero the whole 0x188-byte state, mark matrix slot 0 cached and the state
 * flag word as 1, take the stream pointer from the object's ptrSbc override or
 * else from the model's Sbc block, then unpack the model into the state:
 * node, material and shape dictionaries (each offset-or-null), the joint scale,
 * joint matrix and texture matrix functions picked by the model's scaling rule
 * and texture matrix mode, the position scale pair, an optional (command,
 * timing, callback) override, the object's option bits mirrored into the state
 * flags, an optional init callback, and finally the interpreter loop.
 *
 * Two spellings are load-bearing:
 *   - the store of pRenderObj into the state goes through a volatile lvalue.
 *     Without it the compiler fuses the first two stores into `stm r5, {r0, r4}`
 *     and the function comes out four bytes short.
 *   - the local `pMdl = pRenderObj->resMdl;` in front of the material and shape
 *     offset assembly.  Spelled through the object directly, the `&&`
 *     materialises a boolean (`movne r1,#1 / cmp r1,#0`) and reloads the
 *     offset, 28 bytes of excess; through the local it is the predicated
 *     `cmp / ldrne / cmpne / addne / moveq` chain.
 */
void NNSi_G3dRenderObjRunSbc(NNSG3dRS *pRS, NNSG3dRenderObj *pRenderObj)
{
    const NNSG3dResMdl *pMdl;

    MIi_CpuClearFast(0, pRS, sizeof(NNSG3dRS));
    pRS->isMtxCached[0] = 1;
    pRS->flag = 1;
    pRS->c = pRenderObj->ptrSbc != 0
        ? (const NNSG3dSbcNodeDesc *)pRenderObj->ptrSbc
        : (const NNSG3dSbcNodeDesc *)((const u8 *)pRenderObj->resMdl + pRenderObj->resMdl->ofsSbc);
    *(NNSG3dRenderObj *volatile *)&pRS->pRenderObj = pRenderObj;
    pRS->nodeDict = pRenderObj->resMdl != 0 ? &pRenderObj->resMdl->nodeInfo : 0;
    pMdl = pRenderObj->resMdl;
    pRS->pResMat = pMdl != 0 && pMdl->ofsMat != 0
        ? (NNSG3dResMat *)((const u8 *)pMdl + pMdl->ofsMat) : 0;
    pMdl = pRenderObj->resMdl;
    pRS->pResShp = pMdl != 0 && pMdl->ofsShp != 0
        ? (NNSG3dResShp *)((const u8 *)pMdl + pMdl->ofsShp) : 0;
    pRS->jntScaleFunc = gJntScaleFuncTable[pRenderObj->resMdl->info.scalingRule];
    pRS->jntMtxFunc = gJntMtxFuncTable[pRenderObj->resMdl->info.scalingRule];
    pRS->matTexMtxFunc = gMatTexMtxFuncTable[pRenderObj->resMdl->info.texMtxMode];
    pRS->posScale = pRenderObj->resMdl->info.posScale;
    pRS->invPosScale = pRenderObj->resMdl->info.invPosScale;
    if (pRenderObj->cbFunc != 0 && pRenderObj->cbCmd < 0x20) {
        pRS->cbVecFunc[pRenderObj->cbCmd] = pRenderObj->cbFunc;
        pRS->cbVecTiming[pRenderObj->cbCmd] = pRenderObj->cbTiming;
    }
    if (pRenderObj->flag & NNS_G3D_RENDEROBJ_FLAG_RECORD)
        pRS->flag |= NNS_G3D_RSFLAG_OPT_RECORD;
    if (pRenderObj->flag & NNS_G3D_RENDEROBJ_FLAG_NOGECMD)
        pRS->flag |= NNS_G3D_RSFLAG_OPT_NOGECMD;
    if (pRenderObj->flag & NNS_G3D_RENDEROBJ_FLAG_SKIP_SBCDRAW)
        pRS->flag |= NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW;
    if (pRenderObj->flag & NNS_G3D_RENDEROBJ_FLAG_SKIP_SBCMTXCALC)
        pRS->flag |= NNS_G3D_RSFLAG_OPT_SKIP_SBCMTXCALC;
    if (pRenderObj->cbInitFunc != 0)
        pRenderObj->cbInitFunc(pRS);
    NNSi_G3dSbcRun(pRS);
    pRenderObj->flag &= ~NNS_G3D_RENDEROBJ_FLAG_RECORD;
}


/*
 * Walks an animation chain (next at +0x10, entry count at +0x19, u16 map data
 * array at +0x1a) and sets, in the existence map, one bit per entry whose
 * NNS_G3D_ANMOBJ_MAPDATA_EXIST flag is up.  The count is a u8 read into an
 * `int i` loop, which is what makes the bound tests the original's signed
 * `ble`/`blt`.
 *
 * 2.0/sp2 pin: dsi/1.1p1 and 1.2 both if-convert the flagged-bit store into
 * asrne/ldrne/orrne/strne and land at 100 bytes against the original's 104.
 */
void NNSi_G3dAnmObjMarkExistMap(u32 *pExistMap, NNSG3dAnmObj *pAnmObj)
{
    int i;

    while (pAnmObj != 0) {
        for (i = 0; i < pAnmObj->numMapData; i++) {
            if (pAnmObj->mapData[i] & NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
                pExistMap[i >> 5] |= 1 << (i & 0x1f);
            }
        }
        pAnmObj = pAnmObj->next;
    }
}


/*
 * NNS_G3dDraw core: when the object's RESET_ANMEXIST flag is up, rebuild its
 * three animation existence maps (material, joint, visibility) from the
 * animation chains and drop the flag.  Then run the Sbc stream: through the
 * render state of the draw already in progress when there is one (a nested
 * draw), else through a render state on this frame's stack, which is published
 * in gCurrentRS while the draw is in flight.
 *
 * Shape notes, each measured:
 *   - the 2.0 front end: dsi/1.1p1 gives 224 bytes and 1.2 228 for the same C;
 *     2.0/sp2 gives the original's 220;
 *   - `if (g != 0) {...} else {...}` in that order (the original's `beq` jumps
 *     into the stash arm, and the fall-through arm is the source order);
 *   - the three clear calls and the three map builders take the chain pointer
 *     as the guard's own loaded value: the guard's value is still in r1 at the
 *     call and the original never reloads it.
 */
void NNS_G3dDraw(NNSG3dRenderObj *pRenderObj)
{
    NNSG3dRS work;

    if ((pRenderObj->flag & NNS_G3D_RENDEROBJ_FLAG_RESET_ANMEXIST) == NNS_G3D_RENDEROBJ_FLAG_RESET_ANMEXIST) {
        MIi_CpuClear32(0, pRenderObj->matAnmExist, 8);
        MIi_CpuClear32(0, pRenderObj->jntAnmExist, 8);
        MIi_CpuClear32(0, pRenderObj->visAnmExist, 8);
        if (pRenderObj->anmMat != 0)
            NNSi_G3dAnmObjMarkExistMap(pRenderObj->matAnmExist, pRenderObj->anmMat);
        if (pRenderObj->anmJnt != 0)
            NNSi_G3dAnmObjMarkExistMap(pRenderObj->jntAnmExist, pRenderObj->anmJnt);
        if (pRenderObj->anmVis != 0)
            NNSi_G3dAnmObjMarkExistMap(pRenderObj->visAnmExist, pRenderObj->anmVis);
        pRenderObj->flag &= ~NNS_G3D_RENDEROBJ_FLAG_RESET_ANMEXIST;
    }
    if (gCurrentRS != 0) {
        NNSi_G3dRenderObjRunSbc(gCurrentRS, pRenderObj);
    } else {
        gCurrentRS = &work;
        NNSi_G3dRenderObjRunSbc(&work, pRenderObj);
        gCurrentRS = 0;
    }
}


/*
 * NNSi_G3dFuncSbc_NOP: runs the user callback of the NOP command when one is
 * installed, handing it the render state (which is why the pointer is loaded
 * into r1 and never r0), then steps the command stream by one byte.
 */
void NNSi_G3dFuncSbc_NOP(NNSG3dRS *pRS, u32 opt)
{
    if (pRS->cbVecFunc[NNS_G3D_SBC_NOP] != 0) {
        pRS->cbVecFunc[NNS_G3D_SBC_NOP](pRS);
    }
    NNS_G3D_SBC_ADVANCE(pRS, 1);
}


/*
 * NNSi_G3dFuncSbc_RET: runs the user callback of the RET command when one is
 * installed, then raises RSFLAG_RETURN, which ends the interpreter loop.
 */
void NNSi_G3dFuncSbc_RET(NNSG3dRS *pRS, u32 opt)
{
    if (pRS->cbVecFunc[NNS_G3D_SBC_RET] != 0) {
        pRS->cbVecFunc[NNS_G3D_SBC_RET](pRS);
    }
    pRS->flag |= NNS_G3D_RSFLAG_RETURN;
}


/*
 * NNSi_G3dFuncSbc_NODE: the three-byte NODE command (opcode, node index,
 * visibility flag).  Unless the draw skips Sbc drawing it records the node
 * index in currentNode, raises RSFLAG_CURRENT_NODE_VALID, points
 * pVisAnmResult at the state's own temporary result, then walks the three
 * callback timings.  Between timings A and B the visibility comes from the
 * render object's visibility animation (funcBlendVis, when the node has a bit
 * in visAnmExist), else from the command's flag byte; after timing B
 * RSFLAG_NODE_VISIBLE mirrors it.  The stream advances by three.
 *
 * 2.0/sp2 pin: under dsi/1.1p1 the front end hoists the callback-timing
 * ternary above the field stores (368 bytes against 380); the identical body
 * is byte-exact under ../2.0/sp2, as is NNSi_G3dFuncSbc_MTX.
 */
void NNSi_G3dFuncSbc_NODE(NNSG3dRS *pRS)
{
    if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW)) {
        u32 idxNode;
        u32 timing;
        u32 cbFlag;

        idxNode = NNS_G3D_SBC_BYTE(pRS, 1);
        pRS->currentNode = idxNode;
        pRS->flag |= NNS_G3D_RSFLAG_CURRENT_NODE_VALID;
        pRS->pVisAnmResult = &pRS->tmpVisAnmResult;
        timing = pRS->cbVecFunc[NNS_G3D_SBC_NODE] ? pRS->cbVecTiming[NNS_G3D_SBC_NODE] : 0;

        if (timing == 1) {
            pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
            pRS->cbVecFunc[NNS_G3D_SBC_NODE](pRS);
            timing = pRS->cbVecFunc[NNS_G3D_SBC_NODE] ? pRS->cbVecTiming[NNS_G3D_SBC_NODE] : 0;
            cbFlag = pRS->flag & NNS_G3D_RSFLAG_SKIP;
        } else {
            cbFlag = 0;
        }
        if (cbFlag == 0) {
            NNSG3dRenderObj *pRenderObj = pRS->pRenderObj;
            if (pRenderObj->anmVis == 0
                || (pRenderObj->visAnmExist[idxNode >> 5] & (1u << (idxNode & 0x1f))) == 0
                || pRenderObj->funcBlendVis(pRS->pVisAnmResult, pRenderObj->anmVis, idxNode) == 0) {
                pRS->pVisAnmResult->isVisible = NNS_G3D_SBC_BYTE(pRS, 2) & 1;
            }
        }
        if (timing == 2) {
            pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
            pRS->cbVecFunc[NNS_G3D_SBC_NODE](pRS);
            timing = pRS->cbVecFunc[NNS_G3D_SBC_NODE] ? pRS->cbVecTiming[NNS_G3D_SBC_NODE] : 0;
            cbFlag = pRS->flag & NNS_G3D_RSFLAG_SKIP;
        } else {
            cbFlag = 0;
        }
        if (cbFlag == 0) {
            if (pRS->pVisAnmResult->isVisible) {
                pRS->flag |= NNS_G3D_RSFLAG_NODE_VISIBLE;
            } else {
                pRS->flag &= ~NNS_G3D_RSFLAG_NODE_VISIBLE;
            }
        }
        if (timing == 3) {
            pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
            pRS->cbVecFunc[NNS_G3D_SBC_NODE](pRS);
        }
    }
    NNS_G3D_SBC_ADVANCE(pRS, 3);
}


/*
 * NNSi_G3dFuncSbc_MTX: the two-byte MTX command (opcode, matrix stack slot).
 * For a visible node it restores that slot with MTX_RESTORE unless the draw
 * emits no geometry commands; the callback runs at timings A and C.  The
 * stream advances by two.
 */
void NNSi_G3dFuncSbc_MTX(NNSG3dRS *pRS)
{
    u32 flagWord = pRS->flag;
    u32 timing;
    u32 cbFlag;

    if (!(flagWord & NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW) && (flagWord & NNS_G3D_RSFLAG_NODE_VISIBLE)) {
        timing = pRS->cbVecFunc[NNS_G3D_SBC_MTX] ? pRS->cbVecTiming[NNS_G3D_SBC_MTX] : 0;
        if (timing == 1) {
            pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
            pRS->cbVecFunc[NNS_G3D_SBC_MTX](pRS);
            timing = pRS->cbVecFunc[NNS_G3D_SBC_MTX] ? pRS->cbVecTiming[NNS_G3D_SBC_MTX] : 0;
            cbFlag = pRS->flag & NNS_G3D_RSFLAG_SKIP;
        } else {
            cbFlag = 0;
        }
        if (cbFlag == 0) {
            u32 idxMtx = NNS_G3D_SBC_BYTE(pRS, 1);
            if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD)) {
                NNS_G3dGeBufferOP_N(GECMD_MTX_RESTORE, &idxMtx, 1);
            }
        }
        if (timing == 3) {
            pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
            pRS->cbVecFunc[NNS_G3D_SBC_MTX](pRS);
        }
    }
    NNS_G3D_SBC_ADVANCE(pRS, 2);
}


/*
 * NNSi_G3dFuncSbc_MAT_InternalDefault: the default body of the MAT command,
 * called as (state, option, material data, material index).  Resolves the
 * material result (recorded slot, cached scratch slot, or the state's own
 * temporary), merges the material colours under the global state masks, reads
 * the optional texture-matrix trailer, then sends DIF_AMB, SPE_EMI,
 * POLYGON_ATTR, TEXIMAGE_PARAM and TEXPLTT_BASE as one packed command buffer
 * through NNS_G3dGeBufferOP_N (command word 0x00293130 for the first three, 0x2b2a
 * for the last two).  A zero alpha marks the material transparent
 * (RSFLAG_MAT_TRANSPARENT) and sends nothing.
 *
 * Spellings that close it: the inline accessors with the NULL test of the
 * material block inside them and one shared `return 0`; the texture-matrix
 * trailer tests negated as `if (!(flag & SCALEONE)) copy; else result->flag
 * |= ...`, which if-converts the flag arm.
 */
void NNSi_G3dFuncSbc_MAT_InternalDefault(NNSG3dRS *pRS, u32 opt, const NNSG3dResMatData *pMatData, u32 idMat)
{
    u32 timing;
    u32 cbFlag;
    NNSG3dMatAnmResult *pResult;
    u32 pkt[7];

    pRS->currentMat = idMat;
    pRS->flag |= NNS_G3D_RSFLAG_CURRENT_MAT_VALID;
    pRS->pMatAnmResult = &pRS->tmpMatAnmResult;
    timing = pRS->cbVecFunc[NNS_G3D_SBC_MAT] ? pRS->cbVecTiming[NNS_G3D_SBC_MAT] : 0;

    if (timing == 1) {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        pRS->cbVecFunc[NNS_G3D_SBC_MAT](pRS);
        timing = pRS->cbVecFunc[NNS_G3D_SBC_MAT] ? pRS->cbVecTiming[NNS_G3D_SBC_MAT] : 0;
        cbFlag = pRS->flag & NNS_G3D_RSFLAG_SKIP;
    } else {
        cbFlag = 0;
    }

    if (cbFlag == 0) {
        NNSG3dMatAnmResult *base = pRS->pRenderObj->recMatAnm;

        if (base != 0 && !(pRS->flag & NNS_G3D_RSFLAG_OPT_RECORD)) {
            pResult = base + idMat;
        } else if ((opt == 0x20 || opt == 0x40)
                   && (pRS->isMatCached[idMat >> 5] & (1u << (idMat & 0x1f))) != 0) {
            if (base != 0) {
                pResult = base + idMat;
                goto done;
            }
            pResult = gMatAnmResultScratch + idMat;
        } else {
            u16 matFlag;
            const NNSG3dResMatData *pMatItem;

            if (base != 0) {
                pRS->isMatCached[idMat >> 5] |= 1u << (idMat & 0x1f);
                pResult = pRS->pRenderObj->recMatAnm + idMat;
            } else if (opt == 0x40) {
                pRS->isMatCached[idMat >> 5] |= 1u << (idMat & 0x1f);
                pResult = gMatAnmResultScratch + idMat;
            } else {
                pResult = &pRS->tmpMatAnmResult;
            }

            pResult->flag = 0;

            pMatItem = NNSi_G3dGetMatDataByIdx(pRS->pResMat, idMat);
            matFlag = pMatItem->flag;
            if (matFlag & 0x20) {
                pResult->flag |= 0x20;
            }

            pResult->prmMatColor0 = (NNS_G3dGlb.prmMatColor0 & ~gMatColorMaskTable[(pMatData->flag >> 6) & 7])
                   | (pMatData->diffAmb & gMatColorMaskTable[(pMatData->flag >> 6) & 7]);
            pResult->prmMatColor1 = (NNS_G3dGlb.prmMatColor1 & ~gMatColorMaskTable[(pMatData->flag >> 9) & 7])
                   | (pMatData->specEmi & gMatColorMaskTable[(pMatData->flag >> 9) & 7]);
            pResult->prmPolygonAttr = (NNS_G3dGlb.prmPolygonAttr & ~pMatData->polyAttrMask) | (pMatData->polyAttr & pMatData->polyAttrMask);
            pResult->prmTexImage = pMatData->texImageParam;
            pResult->prmTexPltt = pMatData->texPlttBase;

            if (pMatData->flag & 1) {
                const u8 *pEffect = (const u8 *)&pMatData->effectData[0];

                if (!(pMatData->flag & 2)) {
                    const u32 *pWords = (const u32 *)pEffect;
                    pResult->scaleS = pWords[0];
                    pResult->scaleT = pWords[1];
                    pEffect += 2 * sizeof(u32);
                } else {
                    pResult->flag |= 1;
                }
                if (!(pMatData->flag & 4)) {
                    const s16 *pHalves = (const s16 *)pEffect;
                    pResult->sinR = pHalves[0];
                    pResult->cosR = pHalves[1];
                    pEffect += 2 * sizeof(s16);
                } else {
                    pResult->flag |= 2;
                }
                if (!(pMatData->flag & 8)) {
                    const u32 *pWords = (const u32 *)pEffect;
                    pResult->transS = pWords[0];
                    pResult->transT = pWords[1];
                } else {
                    pResult->flag |= 4;
                }
                pResult->flag |= 8;
            }

            if (pRS->pRenderObj->anmMat != 0
                && (pRS->pRenderObj->matAnmExist[idMat >> 5] & (1u << (idMat & 0x1f))) != 0) {
                pRS->pRenderObj->funcBlendMat(pResult, pRS->pRenderObj->anmMat, idMat);
            }
            if (pResult->flag & 0x18) {
                pResult->origWidth = pMatData->origWidth;
                pResult->origHeight = pMatData->origHeight;
                pResult->magW = pMatData->magW;
                pResult->magH = pMatData->magH;
            }
        }
    done:
        pRS->pMatAnmResult = pResult;
    }

    if (timing == 2) {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        pRS->cbVecFunc[NNS_G3D_SBC_MAT](pRS);
        timing = pRS->cbVecFunc[NNS_G3D_SBC_MAT] ? pRS->cbVecTiming[NNS_G3D_SBC_MAT] : 0;
        cbFlag = pRS->flag & NNS_G3D_RSFLAG_SKIP;
    } else {
        cbFlag = 0;
    }

    if (cbFlag == 0) {
        pResult = pRS->pMatAnmResult;
        if (pResult->prmPolygonAttr & 0x1f0000) {
            if (pResult->flag & 0x20) {
                pResult->prmPolygonAttr &= ~0x1f0000u;
            }
            pRS->flag &= ~2u;
            if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD)) {
                pkt[0] = 0x293130;
                pkt[1] = pResult->prmMatColor0;
                pkt[2] = pResult->prmMatColor1;
                pkt[3] = pResult->prmPolygonAttr;
                pkt[4] = 0x2b2a;
                pkt[5] = pResult->prmTexImage;
                pkt[6] = pResult->prmTexPltt;
                NNS_G3dGeBufferOP_N(pkt[0], &pkt[1], 6);
                if (pResult->flag & 0x18) {
                    pRS->matTexMtxFunc(pResult);
                }
            }
        } else {
            pRS->flag |= 2;
        }
    }

    if (timing == 3) {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        pRS->cbVecFunc[NNS_G3D_SBC_MAT](pRS);
    }
}


/* Per-item-type material and shape handlers, indexed by item tag. */
extern void (*gMatHandlerTable[])(NNSG3dRS *, u32, const NNSG3dResMatData *, u32);

extern void (*gShpHandlerTable[])(NNSG3dRS *, u32, const NNSG3dResShpData *, u32);


/*
 * NNSi_G3dFuncSbc_MAT: the two-byte MAT command (opcode, material index).
 * Unless the draw skips Sbc drawing, and when the material is not already
 * current (or the node is visible), it looks the material up in pResMat and
 * dispatches through the material-type table on the item tag with
 * (state, option, material data, material index).  The stream advances by two.
 *
 * Handlers take (state, option) and the dispatched function takes four
 * arguments, which pins data in r2 and index in r3 across the call; the lookup
 * is two static inline accessors, which reproduces the doubled zero arm
 * without gotos.
 */
void NNSi_G3dFuncSbc_MAT(NNSG3dRS *pRS, u32 opt)
{
    if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW)) {
        u32 idxMat = NNS_G3D_SBC_BYTE(pRS, 1);
        if ((pRS->flag & NNS_G3D_RSFLAG_NODE_VISIBLE) || !(pRS->flag & NNS_G3D_RSFLAG_CURRENT_MAT_VALID) || idxMat != pRS->currentMat) {
            const NNSG3dResMatData *mat = NNSi_G3dGetMatDataByIdx(pRS->pResMat, idxMat);
            (*gMatHandlerTable[mat->itemTag])(pRS, opt, mat, idxMat);
        }
    }
    NNS_G3D_SBC_ADVANCE(pRS, 2);
}


/*
 * NNSi_G3dFuncSbc_SHP_InternalDefault: the default body of the SHP command,
 * called as (state, option, shape data, shape index).  Walks the callback
 * timings around one action: unless the draw emits no geometry commands, the
 * shape's display list (offset and size from the shape item) is sent to the
 * geometry engine through NNS_G3dGeSendDL.
 *
 * PINNED ../2.0/sp2 on the re-read/forward tell (docs/FRONTEND-PINS.md): the
 * image loads the callback pointer after the flag store has retired at all
 * three dispatch sites; dsi/1.1p1 hoists that load above the
 * read-modify-write (42 concrete bytes out, same size).
 */
void NNSi_G3dFuncSbc_SHP_InternalDefault(NNSG3dRS *pRS, u32 opt, const NNSG3dResShpData *pShp, u32 idxShp)
{
    u32 timing;
    u32 cbFlag;

    timing = pRS->cbVecFunc[NNS_G3D_SBC_SHP] ? pRS->cbVecTiming[NNS_G3D_SBC_SHP] : 0;
    if (timing == 1) {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        pRS->cbVecFunc[NNS_G3D_SBC_SHP](pRS);
        timing = pRS->cbVecFunc[NNS_G3D_SBC_SHP] ? pRS->cbVecTiming[NNS_G3D_SBC_SHP] : 0;
        cbFlag = pRS->flag & NNS_G3D_RSFLAG_SKIP;
    } else {
        cbFlag = 0;
    }
    if (cbFlag == 0) {
        if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD)) {
            NNS_G3dGeSendDL((const u32 *)((const u8 *)pShp + pShp->ofsDisplayList), pShp->sizeDisplayList);
        }
    }
    if (timing == 2) {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        pRS->cbVecFunc[NNS_G3D_SBC_SHP](pRS);
        timing = pRS->cbVecFunc[NNS_G3D_SBC_SHP] ? pRS->cbVecTiming[NNS_G3D_SBC_SHP] : 0;
    }
    if (timing == 3) {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        pRS->cbVecFunc[NNS_G3D_SBC_SHP](pRS);
    }
}


/*
 * NNSi_G3dFuncSbc_SHP: the two-byte SHP command (opcode, shape index).  When
 * the draw is not skipped, the material is current and not transparent, it
 * looks the shape up in pResShp and dispatches through the shape-type table on
 * the item tag with (state, option, shape data, shape index).  The stream
 * advances by two.
 */
void NNSi_G3dFuncSbc_SHP(NNSG3dRS *pRS, u32 opt)
{
    if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW) && (pRS->flag & NNS_G3D_RSFLAG_NODE_VISIBLE) && !(pRS->flag & NNS_G3D_RSFLAG_MAT_TRANSPARENT)) {
        u32 idxShp = NNS_G3D_SBC_BYTE(pRS, 1);
        const NNSG3dResShpData *shp = NNSi_G3dGetShpDataByIdx(pRS->pResShp, idxShp);
        (*gShpHandlerTable[shp->itemTag])(pRS, opt, shp, idxShp);
    }
    NNS_G3D_SBC_ADVANCE(pRS, 2);
}


/*
 * NNSi_G3dFuncSbc_NODEDESC: the node descriptor command (4 bytes, plus one per
 * MTX_RESTORE or MTX_STORE option), callback slot 6.  Records the node in
 * currentNodeDesc and raises RSFLAG_CURRENT_NODEDESC_VALID; with
 * RSFLAG_OPT_SKIP_SBCMTXCALC it only steps the stream.  Otherwise it resolves
 * the joint's SRT: from the render object's recorded result (recJntAnm, 0x58
 * bytes per node, reused unless RSFLAG_OPT_RECORD), from the joint blend
 * callback (anmJnt, funcBlendJnt), or from the model's own node data:
 * translation, then the rotation as zero, pivot-compressed or full 3x3, then
 * the scale through jntScaleFunc.  Timing B hands the result to jntMtxFunc
 * unless the draw emits no geometry commands.
 *
 * The pivot table gPivotAxisTable is NNS's pivotUtil_[9][4] (u8).  The C and D
 * entries are `if (flag) B = -B;` statements: the ternary form stays branchy
 * and costs 8 bytes.
 * DISCRIMINATING PIN: dsi/1.1p1 compiles the same C to DIFF.
 */
void NNSi_G3dFuncSbc_NODEDESC(NNSG3dRS *pRS, u32 opt)
{
    u32 cmdLen = 4;
    u32 idxNode = NNS_G3D_SBC_BYTE(pRS, 1);
    u32 timing;
    u32 cbFlag;

    pRS->currentNodeDesc = (u8)idxNode;
    pRS->flag |= NNS_G3D_RSFLAG_CURRENT_NODEDESC_VALID;

    if (pRS->flag & NNS_G3D_RSFLAG_OPT_SKIP_SBCMTXCALC) {
        if NNS_G3D_SBC_OPT_RESTORE(opt)
            cmdLen++;
        if NNS_G3D_SBC_OPT_STORE(opt) {
            cmdLen++;
            if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD)) {
                u32 arg = NNS_G3D_SBC_BYTE(pRS, 4);
                NNS_G3dGeBufferOP_N(0x14, &arg, 1);
            }
        }
        NNS_G3D_SBC_ADVANCE(pRS, cmdLen);
        return;
    }

    if NNS_G3D_SBC_OPT_RESTORE(opt) {
        u32 arg;
        if (opt == 0x40)
            arg = NNS_G3D_SBC_BYTE(pRS, 4);
        else
            arg = NNS_G3D_SBC_BYTE(pRS, 5);
        cmdLen++;
        if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD))
            NNS_G3dGeBufferOP_N(0x14, &arg, 1);
    }

    pRS->pJntAnmResult = &pRS->tmpJntAnmResult;
    timing = NNSi_G3dCheckPossibilityOfCallback(pRS, 6);
    if (!NNSi_G3dCallBackCheckA(pRS, 6, &timing)) {
        NNSG3dJntAnmResult *pResult;
        int isRead;

        if (pRS->pRenderObj->recJntAnm) {
            pResult = &pRS->pRenderObj->recJntAnm[idxNode];
            isRead = !(pRS->flag & NNS_G3D_RSFLAG_OPT_RECORD);
        } else {
            pResult = &pRS->tmpJntAnmResult;
            isRead = 0;
        }

        if (!isRead) {
            pResult->flag = 0;
            if (!pRS->pRenderObj->anmJnt ||
                !(*pRS->pRenderObj->funcBlendJnt)(pResult, pRS->pRenderObj->anmJnt, idxNode)) {
                const NNSG3dResNodeData *nd = NNSi_G3dGetNodeDataByIdx(pRS->nodeDict, idxNode);
                const fx32 *p = nd->trans;

                if (nd->flag & NNS_G3D_SRTFLAG_TRANS_ZERO) {
                    pResult->flag |= 4;
                } else {
                    pResult->trans[0] = p[0];
                    pResult->trans[1] = p[1];
                    pResult->trans[2] = p[2];
                    p += 3;
                }

                if (nd->flag & NNS_G3D_SRTFLAG_ROT_ZERO) {
                    pResult->flag |= 2;
                } else if (nd->flag & NNS_G3D_SRTFLAG_PIVOT_EXIST) {
                    fx32 B;
                    fx32 A;
                    u32 idxPivot = (nd->flag & NNS_G3D_SRTFLAG_IDXPIVOT_MASK) >> 4;

                    A = ((const fx16 *)p)[0];
                    B = ((const fx16 *)p)[1];
                    MI_Zero36B(&pResult->rot);
                    ((fx32 *)pResult->rot)[idxPivot] = (nd->flag & NNS_G3D_SRTFLAG_PIVOT_MINUS) ? -0x1000 : 0x1000;
                    ((fx32 *)pResult->rot)[gPivotAxisTable[idxPivot][0]] = A;
                    ((fx32 *)pResult->rot)[gPivotAxisTable[idxPivot][1]] = B;
                    ((fx32 *)pResult->rot)[gPivotAxisTable[idxPivot][2]] = (nd->flag & NNS_G3D_SRTFLAG_PIVOT_REVC) ? -B : B;
                    ((fx32 *)pResult->rot)[gPivotAxisTable[idxPivot][3]] = (nd->flag & NNS_G3D_SRTFLAG_PIVOT_REVD) ? -A : A;
                    p++;
                } else {
                    const fx16 *q = (const fx16 *)p;
                    pResult->rot[0][0] = nd->rotM00;
                    pResult->rot[0][1] = q[0];
                    pResult->rot[0][2] = q[1];
                    pResult->rot[1][0] = q[2];
                    pResult->rot[1][1] = q[3];
                    pResult->rot[1][2] = q[4];
                    pResult->rot[2][0] = q[5];
                    pResult->rot[2][1] = q[6];
                    pResult->rot[2][2] = q[7];
                    p += 4;
                }
                (*pRS->jntScaleFunc)(pResult, p, pRS->c, nd->flag);
            }
        }
        pRS->pJntAnmResult = pResult;
    }

    if (!NNSi_G3dCallBackCheckB(pRS, 6, &timing) && !(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD))
        (*pRS->jntMtxFunc)(pRS->pJntAnmResult);
    pRS->pJntAnmResult = 0;

    cbFlag = NNSi_G3dCallBackCheckC(pRS, 6, timing);

    if NNS_G3D_SBC_OPT_STORE(opt) {
        cmdLen++;
        if (!cbFlag && !(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD)) {
            u32 arg = NNS_G3D_SBC_BYTE(pRS, 4);
            NNS_G3dGeBufferOP_N(0x13, &arg, 1);
        }
    }
    NNS_G3D_SBC_ADVANCE(pRS, cmdLen);
}


/*
 * NNSi_G3dFuncSbc_BB (sbc.c): the billboard Sbc command, callback slot 7
 * (cbVecFunc at +0x28, cbVecTiming at +0x93).  Option 0x40/0x60 adds a
 * MTX_RESTORE of c[2]/c[3] before, option 0x20/0x60 a MTX_STORE of c[2] after.
 * Between them, unless NOGECMD is set or the timing-A callback asked to skip,
 * it reads the clip matrix back, undoes the camera (NNS_G3dGlb.flag bits 0 and
 * 1), stores the translation row and the three row lengths of the result into
 * the static command block gBillboardCmd (billboard command block) and sends that block to the GXFIFO.
 *
 * The block is 0x48 bytes in .data because it is written: packed command,
 * two parameters, the MtxFx43 whose translation row is at +0x30, the scale
 * vector at +0x3c.  The two pointers into it are locals initialised at the
 * top, which is why the image loads them before the skip test.  The skip arm
 * carries its own `c += cmdLen; return;`.
 *
 * DISCRIMINATING PIN: dsi/1.1p1 is DIFF (736 bytes, push list two wider).
 */
void NNSi_G3dFuncSbc_BB(NNSG3dRS *pRS, u32 opt)
{
    u32 cmdLen = 2;
    VecFx32 *trans = (VecFx32 *)&gBillboardCmd.mtx.m[3][0];
    VecFx32 *scale = &gBillboardCmd.scale;

    if (pRS->flag & NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW) {
        if NNS_G3D_SBC_OPT_RESTORE(opt)
            cmdLen++;
        if NNS_G3D_SBC_OPT_STORE(opt)
            cmdLen++;
        NNS_G3D_SBC_ADVANCE(pRS, cmdLen);
        return;
    } else {
        u32 timing;
        u32 cbFlag;

        if NNS_G3D_SBC_OPT_RESTORE(opt) {
            cmdLen++;
            if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD)) {
                u32 arg;
                if (opt == 0x40)
                    arg = NNS_G3D_SBC_BYTE(pRS, 2);
                else
                    arg = NNS_G3D_SBC_BYTE(pRS, 3);
                NNS_G3dGeBufferOP_N(0x14, &arg, 1);
            }
        }

        timing = NNSi_G3dCheckPossibilityOfCallback(pRS, 7);
        cbFlag = NNSi_G3dCallBackCheckA(pRS, 7, &timing);

        if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD) && !cbFlag) {
            MtxFx44 m;

            NNS_G3dGeFlushBuffer();
            REG_GXFIFO = 0x00151110;
            REG_GXFIFO = 0;
            REG_GXFIFO = 0;
            while (G3X_GetClipMtx(&m))
                ;
            if (NNS_G3dGlb.flag & 1) {
                MtxFx44 tmp;
                MTX_Copy43To44_((const MtxFx43 *)NNS_G3dGlbGetWVMtx(), &tmp);
                MTX_Concat44(&m, &tmp, &m);
            } else if (NNS_G3dGlb.flag & 2) {
                MtxFx44 tmp;
                MTX_Copy43To44_(&NNS_G3dGlb.cameraMtx, &tmp);
                MTX_Concat44(&m, &tmp, &m);
            }
            trans->x = m.m[3][0];
            trans->y = m.m[3][1];
            trans->z = m.m[3][2];
            scale->x = VEC_Mag((VecFx32 *)&m.m[0][0]);
            scale->y = VEC_Mag((VecFx32 *)&m.m[1][0]);
            scale->z = VEC_Mag((VecFx32 *)&m.m[2][0]);

            if (NNS_G3dGlb.flag & 1) {
                REG_GXFIFO = 0x00171012;
                MIi_CpuSend32(&gBillboardCmd.params[0], &REG_GXFIFO, 8);
                MIi_CpuSend32(NNS_G3dGlbGetInvWVMtx(), &REG_GXFIFO, 0x30);
                REG_GXFIFO = 0x1b19;
                MIi_CpuSend32(&gBillboardCmd.mtx, &REG_GXFIFO, 0x3c);
            } else if (NNS_G3dGlb.flag & 2) {
                REG_GXFIFO = 0x00171012;
                MIi_CpuSend32(&gBillboardCmd.params[0], &REG_GXFIFO, 8);
                MIi_CpuSend32(NNS_G3dGlbGetInvCameraMtx(), &REG_GXFIFO, 0x30);
                REG_GXFIFO = 0x1b19;
                MIi_CpuSend32(&gBillboardCmd.mtx, &REG_GXFIFO, 0x3c);
            } else {
                MIi_CpuSend32(&gBillboardCmd, &REG_GXFIFO, 0x48);
            }
        }

        cbFlag = NNSi_G3dCallBackCheckC(pRS, 7, timing);

        if NNS_G3D_SBC_OPT_STORE(opt) {
            cmdLen++;
            if (!cbFlag && !(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD)) {
                u32 arg = NNS_G3D_SBC_BYTE(pRS, 2);
                NNS_G3dGeBufferOP_N(0x13, &arg, 1);
            }
        }
    }
    NNS_G3D_SBC_ADVANCE(pRS, cmdLen);
}


/*
 * NNSi_G3dFuncSbc_BBY: the Y-axis billboard command, callback slot 8.  Sibling
 * of NNSi_G3dFuncSbc_BB with its own static command block gBillboardYCmd: after the
 * translation row and row lengths it builds the upper 3x3 of the block's matrix
 * from the clip matrix's second row (row 0 = (m11, -m10, 0), row 1 = m row 1,
 * both normalised, row 2 = their cross product).
 *
 * Levers: a third pointer local for the block's matrix (loaded in the prologue
 * with the other two), and the six row stores written in reverse field order.
 * DISCRIMINATING PIN: dsi/1.1p1 is DIFF.
 */
void NNSi_G3dFuncSbc_BBY(NNSG3dRS *pRS, u32 opt)
{
    u32 cmdLen = 2;
    VecFx32 *trans = (VecFx32 *)&gBillboardYCmd.mtx.m[3][0];
    VecFx32 *scale = &gBillboardYCmd.scale;
    MtxFx43 *mtx = &gBillboardYCmd.mtx;

    if (pRS->flag & NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW) {
        if NNS_G3D_SBC_OPT_RESTORE(opt)
            cmdLen++;
        if NNS_G3D_SBC_OPT_STORE(opt)
            cmdLen++;
        NNS_G3D_SBC_ADVANCE(pRS, cmdLen);
        return;
    } else {
        u32 timing;
        u32 cbFlag;

        if NNS_G3D_SBC_OPT_RESTORE(opt) {
            cmdLen++;
            if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD)) {
                u32 arg;
                if (opt == 0x40)
                    arg = NNS_G3D_SBC_BYTE(pRS, 2);
                else
                    arg = NNS_G3D_SBC_BYTE(pRS, 3);
                NNS_G3dGeBufferOP_N(0x14, &arg, 1);
            }
        }

        timing = NNSi_G3dCheckPossibilityOfCallback(pRS, 8);
        cbFlag = NNSi_G3dCallBackCheckA(pRS, 8, &timing);

        if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD) && !cbFlag) {
            MtxFx44 m;

            NNS_G3dGeFlushBuffer();
            REG_GXFIFO = 0x00151110;
            REG_GXFIFO = 0;
            REG_GXFIFO = 0;
            while (G3X_GetClipMtx(&m))
                ;
            if (NNS_G3dGlb.flag & 1) {
                MtxFx44 tmp;
                MTX_Copy43To44_((const MtxFx43 *)NNS_G3dGlbGetWVMtx(), &tmp);
                MTX_Concat44(&m, &tmp, &m);
            } else if (NNS_G3dGlb.flag & 2) {
                MtxFx44 tmp;
                MTX_Copy43To44_(&NNS_G3dGlb.cameraMtx, &tmp);
                MTX_Concat44(&m, &tmp, &m);
            }
            trans->x = m.m[3][0];
            trans->y = m.m[3][1];
            trans->z = m.m[3][2];
            scale->x = VEC_Mag((VecFx32 *)&m.m[0][0]);
            scale->y = VEC_Mag((VecFx32 *)&m.m[1][0]);
            scale->z = VEC_Mag((VecFx32 *)&m.m[2][0]);

            mtx->m[1][2] = m.m[1][2];
            mtx->m[1][1] = m.m[1][1];
            mtx->m[1][0] = m.m[1][0];
            mtx->m[0][2] = 0;
            mtx->m[0][1] = -m.m[1][0];
            mtx->m[0][0] = m.m[1][1];
            VEC_Normalize((VecFx32 *)&mtx->m[0][0], (VecFx32 *)&mtx->m[0][0]);
            VEC_Normalize((VecFx32 *)&mtx->m[1][0], (VecFx32 *)&mtx->m[1][0]);
            VEC_CrossProduct((VecFx32 *)&mtx->m[0][0], (VecFx32 *)&mtx->m[1][0], (VecFx32 *)&mtx->m[2][0]);

            if (NNS_G3dGlb.flag & 1) {
                REG_GXFIFO = 0x00171012;
                MIi_CpuSend32(&gBillboardYCmd.params[0], &REG_GXFIFO, 8);
                MIi_CpuSend32(NNS_G3dGlbGetInvWVMtx(), &REG_GXFIFO, 0x30);
                REG_GXFIFO = 0x1b19;
                MIi_CpuSend32(&gBillboardYCmd.mtx, &REG_GXFIFO, 0x3c);
            } else if (NNS_G3dGlb.flag & 2) {
                REG_GXFIFO = 0x00171012;
                MIi_CpuSend32(&gBillboardYCmd.params[0], &REG_GXFIFO, 8);
                MIi_CpuSend32(NNS_G3dGlbGetInvCameraMtx(), &REG_GXFIFO, 0x30);
                REG_GXFIFO = 0x1b19;
                MIi_CpuSend32(&gBillboardYCmd.mtx, &REG_GXFIFO, 0x3c);
            } else {
                MIi_CpuSend32(&gBillboardYCmd, &REG_GXFIFO, 0x48);
            }
        }

        cbFlag = NNSi_G3dCallBackCheckC(pRS, 8, timing);

        if NNS_G3D_SBC_OPT_STORE(opt) {
            cmdLen++;
            if (!cbFlag && !(pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD)) {
                u32 arg = NNS_G3D_SBC_BYTE(pRS, 2);
                NNS_G3dGeBufferOP_N(0x13, &arg, 1);
            }
        }
    }
    NNS_G3D_SBC_ADVANCE(pRS, cmdLen);
}


static inline u32 NNSi_G3dBitVecCheck(const u32 *vec, u32 idx)
{
    return vec[idx >> 5] & (1 << (idx & 31));
}


static inline void NNSi_G3dBitVecSet(u32 *vec, u32 idx)
{
    vec[idx >> 5] |= 1 << (idx & 31);
}


/*
 * NNSi_G3dFuncSbc_NODEMIX: the envelope blend command (3 + 3 * numMtx bytes).
 * For each (source stack slot, node, ratio) triple it makes sure the node's
 * envelope matrices are in the static cache gEvpCache (0x64 bytes per node:
 * the 4x4 M, then the 3x3 N; one cached bit per node in isEvpCached): restore
 * the source slot, multiply by the model's inverse bind matrices (evpMtx,
 * 0x54 bytes per node at resMdl + ofsEvpMtx) and read the clip and vector
 * matrices back.  The weighted sums are accumulated with each node's N term
 * deferred by one iteration (overlapping the hardware read-back), then loaded
 * and stored to the destination slot.
 *
 * Levers: the cache addresses are (column base + off) with off = node *
 * sizeof(EvpCache) as a named local; taking &cache[idx].M and &cache[idx].N
 * lets the compiler derive N from M and loses 8 bytes.  The cached bit is read
 * and set through two inline bit-vector helpers; pM is declared before pN;
 * numMtx and the stream pointer are separate reads; the bit test comes before
 * the pM assignment; sumN is declared before sumM.
 * DISCRIMINATING PIN: dsi/1.1p1 compiles the same C to DIFF.
 */
void NNSi_G3dFuncSbc_NODEMIX(NNSG3dRS *pRS, u32 opt)
{
    const NNSG3dEvpMtx *evpMtx;
    u32 numMtx;
    u32 i;
    fx64 w = 0;
    MtxFx33 sumN;
    MtxFx43 sumM;
    u8 *p;
    const NNSG3dResMdl *mdl = pRS->pRenderObj->resMdl;
    MtxFx44 *pM;
    MtxFx33 *pN;

    numMtx = NNS_G3D_SBC_BYTE(pRS, 2);
    evpMtx = (const NNSG3dEvpMtx *)((u8 *)mdl + mdl->ofsEvpMtx);
    p = (u8 *)pRS->c + 3;
    MIi_CpuClearFast(0, &sumM, sizeof(sumM) + sizeof(sumN));
    NNS_G3dGeFlushBuffer();

    REG_MTX_MODE = 0;
    REG_MTX_STORE = 1;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;

    for (i = 0; i < numMtx; ++i) {
        u32 idxNode = p[1];
        u32 off = idxNode * sizeof(NNSG3dEvpCache);
        u32 cached = NNSi_G3dBitVecCheck(pRS->isEvpCached, idxNode);
        pM = (MtxFx44 *)((u8 *)&gEvpCache[0].M + off);

        if (!cached) {
            NNSi_G3dBitVecSet(pRS->isEvpCached, idxNode);
            REG_MTX_RESTORE = p[0];
            REG_MTX_MODE = 1;
            G3_MultMtx43((void *)(&evpMtx[idxNode].invM));
        }

        if (i != 0) {
            sumN.m[0][0] += (w * pN->m[0][0]) >> 12;
            sumN.m[0][1] += (w * pN->m[0][1]) >> 12;
            sumN.m[0][2] += (w * pN->m[0][2]) >> 12;
            sumN.m[1][0] += (w * pN->m[1][0]) >> 12;
            sumN.m[1][1] += (w * pN->m[1][1]) >> 12;
            sumN.m[1][2] += (w * pN->m[1][2]) >> 12;
            sumN.m[2][0] += (w * pN->m[2][0]) >> 12;
            sumN.m[2][1] += (w * pN->m[2][1]) >> 12;
            sumN.m[2][2] += (w * pN->m[2][2]) >> 12;
        }

        if (!cached) {
            while (G3X_GetClipMtx(pM))
                ;
            REG_MTX_MODE = 2;
            G3_MultMtx33((void *)(&evpMtx[idxNode].invN));
        }

        w = p[2] << 4;
        sumM.m[0][0] += (w * pM->m[0][0]) >> 12;
        sumM.m[0][1] += (w * pM->m[0][1]) >> 12;
        sumM.m[0][2] += (w * pM->m[0][2]) >> 12;
        sumM.m[1][0] += (w * pM->m[1][0]) >> 12;
        sumM.m[1][1] += (w * pM->m[1][1]) >> 12;
        sumM.m[1][2] += (w * pM->m[1][2]) >> 12;
        sumM.m[2][0] += (w * pM->m[2][0]) >> 12;
        sumM.m[2][1] += (w * pM->m[2][1]) >> 12;
        sumM.m[2][2] += (w * pM->m[2][2]) >> 12;
        sumM.m[3][0] += (w * pM->m[3][0]) >> 12;
        sumM.m[3][1] += (w * pM->m[3][1]) >> 12;
        sumM.m[3][2] += (w * pM->m[3][2]) >> 12;

        p += 3;
        pN = (MtxFx33 *)((u8 *)&gEvpCache[0].N + off);
        if (!cached) {
            while (G3X_GetVectorMtx(pN))
                ;
        }
    }

    sumN.m[0][0] += (w * pN->m[0][0]) >> 12;
    sumN.m[0][1] += (w * pN->m[0][1]) >> 12;
    sumN.m[0][2] += (w * pN->m[0][2]) >> 12;
    sumN.m[1][0] += (w * pN->m[1][0]) >> 12;
    sumN.m[1][1] += (w * pN->m[1][1]) >> 12;
    sumN.m[1][2] += (w * pN->m[1][2]) >> 12;
    sumN.m[2][0] += (w * pN->m[2][0]) >> 12;
    sumN.m[2][1] += (w * pN->m[2][1]) >> 12;
    sumN.m[2][2] += (w * pN->m[2][2]) >> 12;

    G3_LoadMtx43(&sumN);
    REG_MTX_MODE = 1;
    G3_LoadMtx43(&sumM);

    REG_MTX_MODE = 0;
    REG_MTX_RESTORE = 1;
    REG_MTX_MODE = 2;
    REG_MTX_STORE = NNS_G3D_SBC_BYTE(pRS, 1);
    NNS_G3D_SBC_ADVANCE(pRS, 3 * (NNS_G3D_SBC_BYTE(pRS, 2) + 1));
}


/*
 * NNSi_G3dFuncSbc_CALLDL: the nine-byte call-display-list command (offset and
 * size, both little-endian words assembled byte by byte because the stream is
 * unaligned).  Runs the callback at timing 1, sends the list to NNS_G3dGeSendDL
 * unless the draw emits no geometry commands or the callback asked to skip,
 * runs the callback at timing 3, and advances the stream by nine.
 *
 * PIN ../2.0/sp2: the image loads the callback pointer after the flag store
 * has retired (re-read/forward tell); dsi/1.1p1 hoists the load above the
 * read-modify-write (28 concrete bytes out).  Neither volatile, a compound
 * `&= ~` spelling nor named locals change it.
 */
void NNSi_G3dFuncSbc_CALLDL(NNSG3dRS *pRS)
{
    u32 m;
    u32 g;
    const u8 *p;
    if (pRS->cbVecFunc[NNS_G3D_SBC_CALLDL] != 0) m = pRS->cbVecTiming[NNS_G3D_SBC_CALLDL]; else m = 0;
    if (m == 1) {
        pRS->flag = pRS->flag & ~NNS_G3D_RSFLAG_SKIP;
        pRS->cbVecFunc[NNS_G3D_SBC_CALLDL](pRS);
        if (pRS->cbVecFunc[NNS_G3D_SBC_CALLDL] != 0) m = pRS->cbVecTiming[NNS_G3D_SBC_CALLDL]; else m = 0;
        g = pRS->flag & NNS_G3D_RSFLAG_SKIP;
    } else {
        g = 0;
    }
    if ((pRS->flag & NNS_G3D_RSFLAG_OPT_NOGECMD) == 0 && g == 0) {
        p = (const u8 *)pRS->c;
        NNS_G3dGeSendDL((const u32 *)(p + (p[1] | (p[2] << 8) | (p[3] << 16) | (p[4] << 24))),
                      p[5] | (p[6] << 8) | (p[7] << 16) | (p[8] << 24));
    }
    if (m == 3) {
        pRS->flag = pRS->flag & ~NNS_G3D_RSFLAG_SKIP;
        pRS->cbVecFunc[NNS_G3D_SBC_CALLDL](pRS);
    }
    NNS_G3D_SBC_ADVANCE(pRS, 9);
}


/*
 * NNSi_G3dFuncSbc_POSSCALE: the position-scale command.  Unless the draw emits
 * no geometry commands or skips Sbc drawing, sends MTX_SCALE with the model's
 * posScale (option 0) or invPosScale (otherwise) on all three axes.  Steps the
 * stream by one.
 *
 * PIN ../2.0/sp2, the "kept branches" tell: the image keeps the compare and
 * branch over the four-instruction arm; dsi/1.1p1 predicates both arms (104
 * bytes against 112).  The field must be bound to a local before the three
 * stores, or 2.0 reloads it before every store.
 */
void NNSi_G3dFuncSbc_POSSCALE(NNSG3dRS *pRS, u32 which)
{
    u32 flags;
    u32 buf[3];

    flags = pRS->flag;
    if ((flags & 0x100) == 0 && (flags & 0x200) == 0) {
        u32 v;
        if (which == 0) {
            v = pRS->posScale;
            buf[2] = v;
            buf[1] = v;
            buf[0] = v;
        } else {
            v = pRS->invPosScale;
            buf[2] = v;
            buf[1] = v;
            buf[0] = v;
        }
        NNS_G3dGeBufferOP_N(0x1b, buf, 3);
    }
    NNS_G3D_SBC_ADVANCE(pRS, 1);
}


/*
 * NNSi_G3dFuncSbc_ENVMAP: the environment-map command (3 bytes), callback slot
 * 12.  Forces the material's TEXGEN field to NORMAL in prmTexImage and re-sends
 * TEXIMAGE_PARAM through the static command pair gTexImageParamCmd; then in texture
 * matrix mode: timing A = MTX_SCALE by (w << 15, -h << 15, 16.0) and a TEXCOORD
 * of (w << 3, h << 3) from the material's original size; timing B = the
 * material's effect matrix (NNS_G3D_MATFLAG_EFFECTMTX, skipping the optional
 * scale, rotation and translation words); timing C = MTX_MULT_3x3 by the
 * camera (and the base rotation when flag bit 0) and the current vector
 * matrix.  Ends in position/vector matrix mode.
 *
 * Levers: w and h are `int` (u16 swaps r4 and r5); the 3x3 matrix and the scale
 * vector are declared at the top of the gated block.
 * DISCRIMINATING PIN: dsi/1.1p1 is 848 bytes, push {r3-r8,lr}.
 */
void NNSi_G3dFuncSbc_ENVMAP(NNSG3dRS *pRS, u32 opt)
{
    if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW) && (pRS->flag & 1)) {
        MtxFx33 n;
        VecFx32 scale;
        u32 timing;

        if ((pRS->pMatAnmResult->prmTexImage & 0xc0000000) != 0x80000000) {
            pRS->pMatAnmResult->prmTexImage &= ~0xc0000000;
            pRS->pMatAnmResult->prmTexImage |= 0x80000000;
            gTexImageParamCmd.param1 = pRS->pMatAnmResult->prmTexImage;
            NNS_G3dGeBufferOP_N(gTexImageParamCmd.op1, &gTexImageParamCmd.param1, 1);
        }
        {
            u32 arg = 3;
            NNS_G3dGeBufferOP_N(0x10, &arg, 1);
        }

        timing = NNSi_G3dCheckPossibilityOfCallback(pRS, 12);
        if (!NNSi_G3dCallBackCheckA(pRS, 12, &timing)) {
            int w = pRS->pMatAnmResult->origWidth;
            int h = pRS->pMatAnmResult->origHeight;
            u32 arg;
            scale.x = w << 15;
            scale.y = -h << 15;
            scale.z = 0x10000;
            NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
            arg = (u32)(u16)(s16)(w << 3) | ((u32)(u16)(s16)(h << 3) << 16);
            NNS_G3dGeBufferOP_N(0x22, &arg, 1);
        }

        if (!NNSi_G3dCallBackCheckB(pRS, 12, &timing)) {
            const NNSG3dResMatData *mat = NNSi_G3dGetMatDataByIdx(pRS->pResMat, NNS_G3D_SBC_BYTE(pRS, 1));
            if (mat->flag & NNS_G3D_MATFLAG_EFFECTMTX) {
                const u8 *p = (const u8 *)mat->effectData;
                if (!(mat->flag & NNS_G3D_MATFLAG_TEXMTX_SCALEONE)) p += 8;
                if (!(mat->flag & NNS_G3D_MATFLAG_TEXMTX_ROTZERO)) p += 4;
                if (!(mat->flag & NNS_G3D_MATFLAG_TEXMTX_TRANSZERO)) p += 8;
                NNS_G3dGeBufferOP_N(0x18, p, 16);
            }
        }

        if (!NNSi_G3dCallBackCheckC(pRS, 12, timing)) {
            {
                u32 arg = 2;
                NNS_G3dGeBufferOP_N(0x10, &arg, 1);
            }
            NNS_G3dGeResetGX(0, &n);
            {
                u32 arg = 3;
                NNS_G3dGeBufferOP_N(0x10, &arg, 1);
            }
            if (NNS_G3dGlb.flag & 1) {
                NNS_G3dGeBufferOP_N(0x1a, &NNS_G3dGlb.cameraMtx, 9);
                NNS_G3dGeBufferOP_N(0x1a, &NNS_G3dGlb.prmBaseRot, 9);
                NNS_G3dGeBufferOP_N(0x1a, &n, 9);
            } else if (NNS_G3dGlb.flag & 2) {
                NNS_G3dGeBufferOP_N(0x1a, &NNS_G3dGlb.cameraMtx, 9);
                NNS_G3dGeBufferOP_N(0x1a, &n, 9);
            } else {
                NNS_G3dGeBufferOP_N(0x1a, &n, 9);
            }
        }
        {
            u32 arg = 2;
            NNS_G3dGeBufferOP_N(0x10, &arg, 1);
        }
    }
    NNS_G3D_SBC_ADVANCE(pRS, 3);
}


/*
 * NNSi_G3dFuncSbc_PRJMAP: the projection-map command (3 bytes), callback slot
 * 13.  Saves the current position matrix to slot 30, forces TEXGEN VERTEX
 * through the static TEXIMAGE_PARAM pair gTexImageParamCmd, then in texture matrix
 * mode: timing A = MTX_LOAD_4x4 of the static matrix gPrjMapTexMtx with
 * (w << 15, -h << 15) scale and (w << 15, h << 15) translation; timing B = the
 * material's effect matrix; timing C = camera terms (base translation and
 * rotation), the saved matrix, a clip-matrix read-back into the texture matrix
 * and a TEXCOORD of its translation.  Restores slot 30 at the end.
 *
 * Lever: the TEXCOORD pair goes through named fx32 locals s = m30 >> 4 and
 * t = m31 >> 4 before the (s16)(v >> 8) narrowing; as one expression the
 * compiler folds the two shifts into one (8 bytes short).
 * DISCRIMINATING PIN: dsi/1.1p1 compiles the same C to DIFF.
 */
void NNSi_G3dFuncSbc_PRJMAP(NNSG3dRS *pRS, u32 opt)
{
    if (!(pRS->flag & NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW) && (pRS->flag & 1)) {
        MtxFx43 m;
        MtxFx44 clip;
        u32 timing;

        NNS_G3dGeResetGX(&m, 0);
        {
            u32 arg = 30;
            NNS_G3dGeBufferOP_N(0x13, &arg, 1);
        }
        if ((pRS->pMatAnmResult->prmTexImage & 0xc0000000) != 0xc0000000) {
            pRS->pMatAnmResult->prmTexImage &= ~0xc0000000;
            pRS->pMatAnmResult->prmTexImage |= 0xc0000000;
            gTexImageParamCmd.param0 = pRS->pMatAnmResult->prmTexImage;
            NNS_G3dGeBufferOP_N(gTexImageParamCmd.op0, &gTexImageParamCmd.param0, 1);
        }

        timing = NNSi_G3dCheckPossibilityOfCallback(pRS, 13);
        if (!NNSi_G3dCallBackCheckA(pRS, 13, &timing)) {
            int w = pRS->pMatAnmResult->origWidth;
            int h = pRS->pMatAnmResult->origHeight;
            gPrjMapTexMtx.m[0][0] = w << 15;
            gPrjMapTexMtx.m[1][1] = -h << 15;
            gPrjMapTexMtx.m[3][0] = w << 15;
            gPrjMapTexMtx.m[3][1] = h << 15;
            NNS_G3dGeBufferOP_N(0x16, &gPrjMapTexMtx, 16);
        }

        if (!NNSi_G3dCallBackCheckB(pRS, 13, &timing)) {
            const NNSG3dResMatData *mat = NNSi_G3dGetMatDataByIdx(pRS->pResMat, NNS_G3D_SBC_BYTE(pRS, 1));
            if (mat->flag & NNS_G3D_MATFLAG_EFFECTMTX) {
                const u8 *p = (const u8 *)mat->effectData;
                if (!(mat->flag & NNS_G3D_MATFLAG_TEXMTX_SCALEONE)) p += 8;
                if (!(mat->flag & NNS_G3D_MATFLAG_TEXMTX_ROTZERO)) p += 4;
                if (!(mat->flag & NNS_G3D_MATFLAG_TEXMTX_TRANSZERO)) p += 8;
                NNS_G3dGeBufferOP_N(0x18, p, 16);
            }
        }

        if (!NNSi_G3dCallBackCheckC(pRS, 13, timing)) {
            if (NNS_G3dGlb.flag & 1) {
                NNS_G3dGeBufferOP_N(0x1c, &NNS_G3dGlb.prmBaseTrans, 3);
                NNS_G3dGeBufferOP_N(0x1a, &NNS_G3dGlb.prmBaseRot, 9);
                NNS_G3dGeBufferOP_N(0x19, &m, 12);
            } else if (NNS_G3dGlb.flag & 2) {
                NNS_G3dGeBufferOP_N(0x19, &m, 12);
            } else {
                NNS_G3dGeBufferOP_N(0x19, NNS_G3dGlbGetInvCameraMtx(), 12);
                NNS_G3dGeBufferOP_N(0x19, &m, 12);
            }
            NNS_G3dGeFlushBuffer();
            *(volatile u32 *)0x04000440 = 0;
            *(volatile u32 *)0x04000444 = 0;
            *(volatile u32 *)0x04000454 = 0;
            while (G3X_GetClipMtx(&clip))
                ;
            *(volatile u32 *)0x04000448 = 1;
            *(volatile u32 *)0x04000440 = 3;
            NNS_G3dGeBufferOP_N(0x16, &clip, 16);
            {
                fx32 s = clip.m[3][0] >> 4;
                fx32 t = clip.m[3][1] >> 4;
                u32 arg = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
                NNS_G3dGeBufferOP_N(0x22, &arg, 1);
            }
        }
        {
            u32 arg = 2;
            NNS_G3dGeBufferOP_N(0x10, &arg, 1);
        }
        {
            u32 arg = 30;
            NNS_G3dGeBufferOP_N(0x14, &arg, 1);
        }
    }
    NNS_G3D_SBC_ADVANCE(pRS, 3);
}
