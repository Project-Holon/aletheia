/*
 * function: NNSi_G3dFuncSbc_BB
 * address:  0x0206C524
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem G3D NNSi_G3dFuncSbc_BB (sbc.c): the SBC billboard opcode,
 * callback slot 7 (cbVecFunc at +0x28, cbVecTiming at +0x93). opt 0x40/0x60
 * adds a MTX_RESTORE (0x14) of c[2]/c[3] before, opt 0x20/0x60 a MTX_STORE
 * (0x13) of c[2] after; between them, unless NOGECMD (0x100) or the timing-A
 * callback asked to skip, it reads the clip matrix back (G3X_GetClipMtx),
 * undoes the camera (flag bits 0/1 of NNS_G3dGlb+0xfc), stores the
 * translation row and the three row lengths (VEC_Mag, func_0207CBD0) into the
 * static command block at 0x020A8328 and sends that block to GXFIFO.
 *
 * The static block (0x48 bytes, .data because it is written):
 *   +0x00 packed command, +0x04 two params, +0x0c MtxFx43 (translation row
 *   at +0x30 = 0x020A8358), +0x3c VecFx32 scale (0x020A8364).
 * The two pointers into it are locals initialised at the top, which is why
 * the image loads them before the SKIP test. The skip arm carries its own
 * `rs->c += cmdLen; return;`.
 * DISCRIMINATING PIN: dsi/1.1p1 is DIFF (736 bytes, push list two wider).
 *
 * symbols:
 *   g_renderState     0x02148B4C  data
 *   gBillboardCmd     0x020A8328  data
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
extern BBData gBillboardCmd;

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

void NNSi_G3dFuncSbc_BB(RS *rs, u32 opt)
{
    u32 cmdLen = 2;
    VecFx32 *trans = (VecFx32 *)&gBillboardCmd.mtx._30;
    VecFx32 *scale = &gBillboardCmd.scale;

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

        timing = CheckPossibilityOfCallback(rs, 7);
        cbFlag = CallBackCheck_A(rs, 7, &timing);

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

            if (g_renderState.flag & 1) {
                GXFIFO = 0x00171012;
                MIi_CpuSend32(&gBillboardCmd.prm[0], &GXFIFO, 8);
                MIi_CpuSend32(NNS_G3dGlbGetInvWVMtx(), &GXFIFO, 0x30);
                GXFIFO = 0x1b19;
                MIi_CpuSend32(&gBillboardCmd.mtx, &GXFIFO, 0x3c);
            } else if (g_renderState.flag & 2) {
                GXFIFO = 0x00171012;
                MIi_CpuSend32(&gBillboardCmd.prm[0], &GXFIFO, 8);
                MIi_CpuSend32(NNS_G3dGlbGetInvCameraMtx(), &GXFIFO, 0x30);
                GXFIFO = 0x1b19;
                MIi_CpuSend32(&gBillboardCmd.mtx, &GXFIFO, 0x3c);
            } else {
                MIi_CpuSend32(&gBillboardCmd, &GXFIFO, 0x48);
            }
        }

        cbFlag = CallBackCheck_C(rs, 7, timing);

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
