/*
 * function: MTX_PerspectiveW
 * address:  0x0207C408
 * packet:   pkt_0207C408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfx fx_mtx44.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  A
 * perspective projection from the sine and cosine of half the field of
 * view, scaled by scaleW, with the same divider inlines as MTX_FrustumW.
 *
 * symbols:
 *   FX_Div                         0x0207C768  arm
 *   FX_GetDivResultFx64c           0x0207C848  arm
 *   FX_GetDivResult                0x0207C86C  arm
 *   _ll_sdiv                       0x0209BE5C  arm
 */

typedef long fx32;
typedef long long fx64;
typedef long long fx64c;
typedef unsigned long u32;
typedef unsigned long long u64;

#define FX32_ONE 4096

typedef union {
    struct {
        fx32 _00, _01, _02, _03;
        fx32 _10, _11, _12, _13;
        fx32 _20, _21, _22, _23;
        fx32 _30, _31, _32, _33;
    };
    fx32 m[4][4];
    fx32 a[16];
} MtxFx44;

#define REG_DIV_NUMER (*(u64 *)0x04000290)
#define REG_DIV_DENOM (*(u64 *)0x04000298)

fx32 FX_Div(fx32 numer, fx32 denom);
fx64c FX_GetDivResultFx64c(void);
fx32 FX_GetDivResult(void);

static inline void FX_InvAsyncImm(fx32 denom)
{
    REG_DIV_NUMER = (fx64)FX32_ONE << 32;
    REG_DIV_DENOM = (u32)denom;
}

static inline void FX_DivAsyncImm(fx32 numer, fx32 denom)
{
    REG_DIV_NUMER = (fx64)numer << 32;
    REG_DIV_DENOM = (u32)denom;
}

static inline fx32 FX_Mul(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}

static inline fx32 FX_Mul32x64c(fx32 v32, fx64c v64c)
{
    return (fx32)((v64c * v32 + 0x80000000LL) >> 32);
}

void MTX_PerspectiveW(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx)
{
    fx32 one_tan;
    fx64c t;

    one_tan = FX_Div(fovyCos, fovySin);
    FX_InvAsyncImm(n - f);
    if (scaleW != FX32_ONE) {
        one_tan = (one_tan * scaleW) / FX32_ONE;
    }

    mtx->_01 = 0;
    mtx->_02 = 0;
    mtx->_03 = 0;
    mtx->_10 = 0;
    mtx->_11 = one_tan;
    mtx->_12 = 0;
    mtx->_13 = 0;
    mtx->_20 = 0;
    mtx->_21 = 0;
    mtx->_23 = -scaleW;
    mtx->_30 = 0;
    mtx->_31 = 0;
    mtx->_33 = 0;

    t = FX_GetDivResultFx64c();
    FX_DivAsyncImm(one_tan, aspect);
    if (scaleW != FX32_ONE) {
        t = (t * scaleW) / FX32_ONE;
    }
    mtx->_22 = FX_Mul32x64c(f + n, t);
    mtx->_32 = FX_Mul32x64c(FX_Mul(n << 1, f), t);

    mtx->_00 = FX_GetDivResult();
}
