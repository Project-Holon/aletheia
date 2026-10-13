/*
 * function: NNSi_G3dFuncSbc_PRJMAP
 * address:  0x0206D778
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem G3D NNSi_G3dFuncSbc_PRJMAP (sbc.c): the SBC projection-map
 * opcode (3 bytes), callback slot 13 (cbVecFunc +0x40, cbVecTiming +0x99).
 * Saves the current position matrix to slot 30 (MTX_STORE), forces TEXGEN
 * VERTEX (0xc0000000) through the static TEXIMAGE_PARAM pair at 0x020A82B8
 * (+0 op, +4 param; NNSi_G3dFuncSbc_ENVMAP uses the +8/+0xc pair), then in texture
 * matrix mode: timing A = MTX_LOAD_4x4 of the static matrix at 0x020A82E8
 * with (w<<15, -h<<15) scale and (w<<15, h<<15) translation; timing B = the
 * material's effect matrix; timing C = camera terms (NNS_G3dGlb +0xe0 trans,
 * +0xbc 3x3), the saved matrix, a clip-matrix read-back into the texture
 * matrix and a TEXCOORD of its translation. Restores slot 30 at the end.
 *
 * Lever: the TEXCOORD pair goes through named fx32 locals s = _30 >> 4,
 * t = _31 >> 4 before the (s16)(v >> 8) narrowing; written as one expression
 * mwcc folds the two shifts into one (8 bytes short).
 * The w/h are int as in NNSi_G3dFuncSbc_ENVMAP.
 * DISCRIMINATING PIN: dsi/1.1p1 compiles the same C to DIFF.
 *
 * symbols:
 *   g_renderState     0x02148B4C  data
 *   gTexImageParamCmd     0x020A82B8  data
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   NNS_G3dGeResetGX  0x0206DE88  arm
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   G3X_GetClipMtx  0x0207DC98  arm
 *   NNS_G3dGlbGetInvCameraMtx  0x0206AAD4  arm
 *   gPrjMapTexMtx     0x020A82E8  data
 */

#include "../include/G_TexImageCmd.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22; } MtxFx33;
typedef struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22, _30, _31, _32; } MtxFx43;
typedef struct { fx32 _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33; } MtxFx44;

typedef struct {
    u32 cmd0;
    u32 mtxmode;
    MtxFx44 prjMtx;
    u32 cmd1;
    MtxFx43 cameraMtx;
    u8 pad7c[0xbc - 0x7c];
    MtxFx33 unkBC;
    VecFx32 unkE0;
    u8 padec[0xfc - 0xec];
    u32 flag;
} Glb;
extern Glb g_renderState;

typedef struct {
    u32 w0;
    u32 w4;
    u32 op;
    u32 prm;
} TexImageCmd;
extern struct TexImageCmd gTexImageParamCmd;

typedef struct {
    u8  pad00[0x10];
    u32 prmTexImage;
    u8  pad14[0x2c - 0x14];
    u16 origWidth;
    u16 origHeight;
} MatAnmResult;

typedef struct {
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} Dict;
typedef struct { u16 sizeUnit; u16 sizeHeader; } DictEntryHeader;
typedef struct { u16 ofsDictTexToMatList; u16 ofsDictPlttToMatList; Dict dict; } ResMat;
typedef struct {
    u16 itemTag;
    u16 size;
    u8  pad04[0x1e - 0x04];
    u16 flag;
} ResMatData;

typedef struct RS RS;
typedef void (*CbFunc)(RS *);
struct RS {
    u8 *c;
    void *pRenderObj;
    u32 flag;
    CbFunc cbVecFunc[32];
    u8 cbVecTiming[32];
    u8 currentNode;
    u8 currentMat;
    u8 currentNodeDesc;
    u8 dummy_;
    MatAnmResult *pMatAnmResult;
    u8 padb4[0xd8 - 0xb4];
    ResMat *pResMat;
};

extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
extern void NNS_G3dGeResetGX(void *a, void *b);
extern void NNS_G3dGeFlushBuffer(void);
extern int  G3X_GetClipMtx(MtxFx44 *m);
extern u32 *NNS_G3dGlbGetInvCameraMtx(void);
extern MtxFx44 gPrjMapTexMtx;

static inline void *GetResDataByIdx(const Dict *dict, u32 idx)
{
    if (dict && idx < dict->numEntry) {
        const DictEntryHeader *hdr = (const DictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (void *)((u32)hdr + sizeof(DictEntryHeader) + hdr->sizeUnit * idx);
    }
    return 0;
}

static inline ResMatData *GetMatDataByIdx(const ResMat *mat, u32 idx)
{
    if (mat) {
        const u32 *data = (const u32 *)GetResDataByIdx(&mat->dict, idx);
        if (data)
            return (ResMatData *)((u8 *)mat + *data);
    }
    return 0;
}

static inline u32 CheckPossibilityOfCallback(RS *rs, u32 cmd)
{
    return rs->cbVecFunc[cmd] ? rs->cbVecTiming[cmd] : 0;
}

static inline u32 CallBackCheck_A(RS *rs, u32 cmd, u32 *pTiming)
{
    if (*pTiming == 1) {
        rs->flag &= ~0x40;
        (*rs->cbVecFunc[cmd])(rs);
        *pTiming = CheckPossibilityOfCallback(rs, cmd);
        return rs->flag & 0x40;
    }
    return 0;
}

static inline u32 CallBackCheck_B(RS *rs, u32 cmd, u32 *pTiming)
{
    if (*pTiming == 2) {
        rs->flag &= ~0x40;
        (*rs->cbVecFunc[cmd])(rs);
        *pTiming = CheckPossibilityOfCallback(rs, cmd);
        return rs->flag & 0x40;
    }
    return 0;
}

static inline u32 CallBackCheck_C(RS *rs, u32 cmd, u32 timing)
{
    if (timing == 3) {
        rs->flag &= ~0x40;
        (*rs->cbVecFunc[cmd])(rs);
        return rs->flag & 0x40;
    }
    return 0;
}

void NNSi_G3dFuncSbc_PRJMAP(RS *rs, u32 opt)
{
    if (!(rs->flag & 0x200) && (rs->flag & 1)) {
        MtxFx43 m;
        MtxFx44 clip;
        u32 timing;

        NNS_G3dGeResetGX(&m, 0);
        {
            u32 arg = 30;
            NNS_G3dGeBufferOP_N(0x13, &arg, 1);
        }
        if ((rs->pMatAnmResult->prmTexImage & 0xc0000000) != 0xc0000000) {
            rs->pMatAnmResult->prmTexImage &= ~0xc0000000;
            rs->pMatAnmResult->prmTexImage |= 0xc0000000;
            gTexImageParamCmd.w4 = rs->pMatAnmResult->prmTexImage;
            NNS_G3dGeBufferOP_N(gTexImageParamCmd.w0, &gTexImageParamCmd.w4, 1);
        }

        timing = CheckPossibilityOfCallback(rs, 13);
        if (!CallBackCheck_A(rs, 13, &timing)) {
            int w = rs->pMatAnmResult->origWidth;
            int h = rs->pMatAnmResult->origHeight;
            gPrjMapTexMtx._00 = w << 15;
            gPrjMapTexMtx._11 = -h << 15;
            gPrjMapTexMtx._30 = w << 15;
            gPrjMapTexMtx._31 = h << 15;
            NNS_G3dGeBufferOP_N(0x16, &gPrjMapTexMtx, 16);
        }

        if (!CallBackCheck_B(rs, 13, &timing)) {
            ResMatData *mat = GetMatDataByIdx(rs->pResMat, rs->c[1]);
            if (mat->flag & 0x2000) {
                u8 *p = (u8 *)mat + 0x2c;
                if (!(mat->flag & 2)) p += 8;
                if (!(mat->flag & 4)) p += 4;
                if (!(mat->flag & 8)) p += 8;
                NNS_G3dGeBufferOP_N(0x18, p, 16);
            }
        }

        if (!CallBackCheck_C(rs, 13, timing)) {
            if (g_renderState.flag & 1) {
                NNS_G3dGeBufferOP_N(0x1c, &g_renderState.unkE0, 3);
                NNS_G3dGeBufferOP_N(0x1a, &g_renderState.unkBC, 9);
                NNS_G3dGeBufferOP_N(0x19, &m, 12);
            } else if (g_renderState.flag & 2) {
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
                fx32 s = clip._30 >> 4;
                fx32 t = clip._31 >> 4;
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
    rs->c += 3;
}
