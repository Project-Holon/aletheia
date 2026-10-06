/*
 * function: func_0206C82C
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
 * func_0206C524 (BB) with its own static command block at 0x020A8370: after
 * the translation row and row lengths it builds the upper 3x3 of the block's
 * matrix from the clip matrix's second row (row0 = (m._11, -m._10, 0),
 * row1 = m row 1, both VEC_Normalize'd by func_0207CCA4, row2 = their
 * VEC_CrossProduct, func_0207CAE8).
 *
 * Levers: a third pointer local for the block's matrix (loaded into r7 in the
 * prologue with the other two), and the six row stores written in reverse
 * field order (_12 first, _00 last).
 * DISCRIMINATING PIN: dsi/1.1p1 is DIFF.
 *
 * symbols:
 *   g_02148B4C     0x02148B4C  data
 *   g_020A8370     0x020A8370  data
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207DC98  0x0207DC98  arm
 *   func_0206ADBC  0x0206ADBC  arm
 *   func_0206ADF4  0x0206ADF4  arm
 *   func_0206AAD4  0x0206AAD4  arm
 *   func_0207B5C0  0x0207B5C0  arm
 *   func_0207BE14  0x0207BE14  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_02082AA8  0x02082AA8  arm
 *   func_0207CCA4  0x0207CCA4  arm
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
extern Glb g_02148B4C;

typedef struct {
    u32 cmd;
    u32 prm[2];
    MtxFx43 mtx;
    VecFx32 scale;
} BBData;
extern BBData g_020A8370;

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

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_0206DB80(void);
extern int  func_0207DC98(MtxFx44 *m);
extern u32 *func_0206ADBC(void);
extern u32 *func_0206ADF4(void);
extern u32 *func_0206AAD4(void);
extern void func_0207B5C0(const MtxFx43 *src, MtxFx44 *dst);
extern void func_0207BE14(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
extern fx32 func_0207CBD0(const VecFx32 *v);
extern void func_0207CCA4(const VecFx32 *src, VecFx32 *dst);
extern void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern void func_02082AA8(const void *src, volatile void *dst, u32 n);

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

void func_0206C82C(RS *rs, u32 opt)
{
    u32 cmdLen = 2;
    VecFx32 *trans = (VecFx32 *)&g_020A8370.mtx._30;
    VecFx32 *scale = &g_020A8370.scale;
    MtxFx43 *mtx = &g_020A8370.mtx;

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
                func_0206DDA4(0x14, &arg, 1);
            }
        }

        timing = CheckPossibilityOfCallback(rs, 8);
        cbFlag = CallBackCheck_A(rs, 8, &timing);

        if (!(rs->flag & 0x100) && !cbFlag) {
            MtxFx44 m;

            func_0206DB80();
            GXFIFO = 0x00151110;
            GXFIFO = 0;
            GXFIFO = 0;
            while (func_0207DC98(&m))
                ;
            if (g_02148B4C.flag & 1) {
                MtxFx44 tmp;
                func_0207B5C0((const MtxFx43 *)func_0206ADBC(), &tmp);
                func_0207BE14(&m, &tmp, &m);
            } else if (g_02148B4C.flag & 2) {
                MtxFx44 tmp;
                func_0207B5C0(&g_02148B4C.cameraMtx, &tmp);
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
            func_0207CCA4((VecFx32 *)&mtx->_00, (VecFx32 *)&mtx->_00);
            func_0207CCA4((VecFx32 *)&mtx->_10, (VecFx32 *)&mtx->_10);
            func_0207CAE8((VecFx32 *)&mtx->_00, (VecFx32 *)&mtx->_10, (VecFx32 *)&mtx->_20);

            if (g_02148B4C.flag & 1) {
                GXFIFO = 0x00171012;
                func_02082AA8(&g_020A8370.prm[0], &GXFIFO, 8);
                func_02082AA8(func_0206ADF4(), &GXFIFO, 0x30);
                GXFIFO = 0x1b19;
                func_02082AA8(&g_020A8370.mtx, &GXFIFO, 0x3c);
            } else if (g_02148B4C.flag & 2) {
                GXFIFO = 0x00171012;
                func_02082AA8(&g_020A8370.prm[0], &GXFIFO, 8);
                func_02082AA8(func_0206AAD4(), &GXFIFO, 0x30);
                GXFIFO = 0x1b19;
                func_02082AA8(&g_020A8370.mtx, &GXFIFO, 0x3c);
            } else {
                func_02082AA8(&g_020A8370, &GXFIFO, 0x48);
            }
        }

        cbFlag = CallBackCheck_C(rs, 8, timing);

        if (opt == 0x20 || opt == 0x60) {
            cmdLen++;
            if (!cbFlag && !(rs->flag & 0x100)) {
                u32 arg = rs->c[2];
                func_0206DDA4(0x13, &arg, 1);
            }
        }
    }
    rs->c += cmdLen;
}
