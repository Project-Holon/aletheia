/*
 * function: MTX_FrustumW
 * address:  0x0207C1D0
 * packet:   pkt_0207C1D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfx fx_mtx44.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  The
 * divider registers are written through plain (non-volatile) u64 lvalues:
 * only that lets the numerator high word and the denominator low word merge
 * into the image's single stmib.
 *
 * symbols:
 *   FX_InvAsync                    0x0207C8A0  arm
 *   FX_GetDivResultFx64c           0x0207C848  arm
 *   _ll_sdiv                       0x0209BE5C  arm
 */

typedef long fx32;
typedef long long fx64;
typedef long long fx64c;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef volatile u64 vu64;

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

void FX_InvAsync(fx32 denom);
fx64c FX_GetDivResultFx64c(void);

static inline void FX_InvAsyncImm(fx32 denom)
{
    REG_DIV_NUMER = (fx64)FX32_ONE << 32;
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

void MTX_FrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx)
{
    fx64c inv1;
    fx64c inv2;
    fx32 dblN;

    FX_InvAsync(r - l);

    mtx->_01 = 0;
    mtx->_02 = 0;
    mtx->_03 = 0;
    mtx->_10 = 0;
    mtx->_12 = 0;
    mtx->_13 = 0;
    mtx->_23 = -scaleW;
    mtx->_30 = 0;
    mtx->_31 = 0;
    mtx->_33 = 0;

    dblN = n << 1;

    inv1 = FX_GetDivResultFx64c();
    FX_InvAsyncImm(t - b);
    if (scaleW != FX32_ONE) {
        inv1 = (inv1 * scaleW) / FX32_ONE;
    }
    mtx->_00 = FX_Mul32x64c(dblN, inv1);

    inv2 = FX_GetDivResultFx64c();
    FX_InvAsyncImm(n - f);
    if (scaleW != FX32_ONE) {
        inv2 = (inv2 * scaleW) / FX32_ONE;
    }
    mtx->_11 = FX_Mul32x64c(dblN, inv2);
    mtx->_20 = FX_Mul32x64c(r + l, inv1);
    mtx->_21 = FX_Mul32x64c(t + b, inv2);

    inv1 = FX_GetDivResultFx64c();
    if (scaleW != FX32_ONE) {
        inv1 = (inv1 * scaleW) / FX32_ONE;
    }
    mtx->_22 = FX_Mul32x64c(f + n, inv1);
    mtx->_32 = FX_Mul32x64c(FX_Mul(dblN, f), inv1);
}
