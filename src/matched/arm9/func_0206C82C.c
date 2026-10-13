/*
 * function: NNSi_G3dFuncSbc_BBY
 * address:  0x0206C82C
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem G3D NNSi_G3dFuncSbc_BBY (sbc.c): the Y-axis billboard opcode,
 * callback slot 8 (cbVecFunc +0x2c, cbVecTiming +0x94). The sibling of
 * NNSi_G3dFuncSbc_BB (BB) with its own static command block at 0x020A8370: after
 * the translation row and row lengths it builds the upper 3x3 of the block's
 * matrix from the clip matrix's second row (row0 = (m._11, -m._10, 0),
 * row1 = m row 1, both VEC_Normalize'd by VEC_Normalize, row2 = their
 * VEC_CrossProduct, func_0207CAE8).
 *
 * Levers: a third pointer local for the block's matrix (loaded into r7 in the
 * prologue with the other two), and the six row stores written in reverse
 * field order (_12 first, _00 last).
 * DISCRIMINATING PIN: dsi/1.1p1 is DIFF.
 *
 * symbols:
 *   g_renderState     0x02148B4C  data
 *   gBillboardYCmd     0x020A8370  data
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   G3X_GetClipMtx  0x0207DC98  arm
 *   NNS_G3dGlbGetWVMtx  0x0206ADBC  arm
 *   NNS_G3dGlbGetInvWVMtx  0x0206ADF4  arm
 *   NNS_G3dGlbGetInvCameraMtx  0x0206AAD4  arm
 *   func_0207B5C0  0x0207B5C0  arm
 *   func_0207BE14  0x0207BE14  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   MIi_CpuSend32  0x02082AA8  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33; } MtxFx44;
typedef struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22, _30, _31, _32; } MtxFx43;

typedef struct {
    u32 cmd0;
    u32 mtxmode;
    MtxFx44 prjMtx;
    u32 cmd1;
    MtxFx43 cameraMtx;
    u8 pad7c[0xfc - 0x7c];
    u32 flag;
} Glb;
extern Glb g_renderState;

typedef struct {
    u32 cmd;
    u32 prm[2];
    MtxFx43 mtx;
    VecFx32 scale;
} BBData;
extern BBData gBillboardYCmd;

typedef struct RS RS;
typedef void (*CbFunc)(RS *);
struct RS {
    u8 *c;
    void *pRenderObj;
    u32 flag;
    CbFunc cbVecFunc[32];
    u8 cbVecTiming[32];
};

#define GXFIFO (*(volatile u32 *)0x04000400)

extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
extern void NNS_G3dGeFlushBuffer(void);
extern int  G3X_GetClipMtx(MtxFx44 *m);
extern u32 *NNS_G3dGlbGetWVMtx(void);
extern u32 *NNS_G3dGlbGetInvWVMtx(void);
extern u32 *NNS_G3dGlbGetInvCameraMtx(void);
extern void func_0207B5C0(const MtxFx43 *src, MtxFx44 *dst);
extern void func_0207BE14(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
extern fx32 func_0207CBD0(const VecFx32 *v);
extern void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
extern void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern void MIi_CpuSend32(const void *src, volatile void *dst, u32 n);

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

static inline u32 CallBackCheck_C(RS *rs, u32 cmd, u32 timing)
{
    if (timing == 3) {
        rs->flag &= ~0x40;
        (*rs->cbVecFunc[cmd])(rs);
        return rs->flag & 0x40;
    }
    return 0;
}

void NNSi_G3dFuncSbc_BBY(RS *rs, u32 opt)
{
    u32 cmdLen = 2;
    VecFx32 *trans = (VecFx32 *)&gBillboardYCmd.mtx._30;
    VecFx32 *scale = &gBillboardYCmd.scale;
    MtxFx43 *mtx = &gBillboardYCmd.mtx;

    if (rs->flag & 0x200) {
        if (opt == 0x40 || opt == 0x60)
            cmdLen++;
        if (opt == 0x20 || opt == 0x60)
            cmdLen++;
        rs->c += cmdLen;
        return;
    } else {
        u32 timing;
        u32 cbFlag;

        if (opt == 0x40 || opt == 0x60) {
            cmdLen++;
            if (!(rs->flag & 0x100)) {
                u32 arg;
                if (opt == 0x40)
                    arg = rs->c[2];
                else
                    arg = rs->c[3];
                NNS_G3dGeBufferOP_N(0x14, &arg, 1);
            }
        }

        timing = CheckPossibilityOfCallback(rs, 8);
        cbFlag = CallBackCheck_A(rs, 8, &timing);

        if (!(rs->flag & 0x100) && !cbFlag) {
            MtxFx44 m;

            NNS_G3dGeFlushBuffer();
            GXFIFO = 0x00151110;
            GXFIFO = 0;
            GXFIFO = 0;
            while (G3X_GetClipMtx(&m))
                ;
            if (g_renderState.flag & 1) {
                MtxFx44 tmp;
                func_0207B5C0((const MtxFx43 *)NNS_G3dGlbGetWVMtx(), &tmp);
                func_0207BE14(&m, &tmp, &m);
            } else if (g_renderState.flag & 2) {
                MtxFx44 tmp;
                func_0207B5C0(&g_renderState.cameraMtx, &tmp);
                func_0207BE14(&m, &tmp, &m);
            }
            trans->x = m._30;
            trans->y = m._31;
            trans->z = m._32;
            scale->x = func_0207CBD0((VecFx32 *)&m._00);
            scale->y = func_0207CBD0((VecFx32 *)&m._10);
            scale->z = func_0207CBD0((VecFx32 *)&m._20);

            mtx->_12 = m._12;
            mtx->_11 = m._11;
            mtx->_10 = m._10;
            mtx->_02 = 0;
            mtx->_01 = -m._10;
            mtx->_00 = m._11;
            VEC_Normalize((VecFx32 *)&mtx->_00, (VecFx32 *)&mtx->_00);
            VEC_Normalize((VecFx32 *)&mtx->_10, (VecFx32 *)&mtx->_10);
            func_0207CAE8((VecFx32 *)&mtx->_00, (VecFx32 *)&mtx->_10, (VecFx32 *)&mtx->_20);

            if (g_renderState.flag & 1) {
                GXFIFO = 0x00171012;
                MIi_CpuSend32(&gBillboardYCmd.prm[0], &GXFIFO, 8);
                MIi_CpuSend32(NNS_G3dGlbGetInvWVMtx(), &GXFIFO, 0x30);
                GXFIFO = 0x1b19;
                MIi_CpuSend32(&gBillboardYCmd.mtx, &GXFIFO, 0x3c);
            } else if (g_renderState.flag & 2) {
                GXFIFO = 0x00171012;
                MIi_CpuSend32(&gBillboardYCmd.prm[0], &GXFIFO, 8);
                MIi_CpuSend32(NNS_G3dGlbGetInvCameraMtx(), &GXFIFO, 0x30);
                GXFIFO = 0x1b19;
                MIi_CpuSend32(&gBillboardYCmd.mtx, &GXFIFO, 0x3c);
            } else {
                MIi_CpuSend32(&gBillboardYCmd, &GXFIFO, 0x48);
            }
        }

        cbFlag = CallBackCheck_C(rs, 8, timing);

        if (opt == 0x20 || opt == 0x60) {
            cmdLen++;
            if (!cbFlag && !(rs->flag & 0x100)) {
                u32 arg = rs->c[2];
                NNS_G3dGeBufferOP_N(0x13, &arg, 1);
            }
        }
    }
    rs->c += cmdLen;
}
