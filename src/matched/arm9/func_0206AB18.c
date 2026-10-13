/*
 * function: MTX_Inverse44
 * address:  0x0206AB18
 * packet:   pkt_0206A17C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_Copy64B        0x02082BA0  arm
 *   MTX_Identity44_   0x0207BDB4  arm
 *   FX_InvFx64c       0x0207C788  arm
 *
 * 4x4 fx32 matrix inverse, Gauss-Jordan with partial pivoting (a game-side
 * MTX_Inverse44: the SDK in this image carries only MTX_Inverse33/43).
 * Copies pSrc into a stack MtxFx44 (MI_Copy64B), sets pDst to identity,
 * returns -1 on a zero pivot column, else 0.  Row normalisation is
 * FX_Mul32x64c(v, FX_InvFx64c(pivot)) (rounded, >> 32); elimination is an
 * UNROUNDED (fx64)a * b >> 12.  (The sdk name FX_InvFx64c for 0x0207C788 is
 * libmatch's; it takes one argument.)
 *
 * WHAT CLOSED IT: VARIABLE IDENTITY, not spelling.  With a dedicated loop
 * variable for the elimination row the compile is 520/520 with a 17-byte
 * three-register rotation (j/a/a>>31 in r2/ip/r3 against ip/r3/r2) that
 * hill (252 singles) and anneal (700) could not move.  The image's allocation
 * appears when the elimination row variable is the SAME variable that
 * recorded the pivot row (here j), so its live ranges merge.  A sweep of 90
 * role assignments found ten EXACT, all sharing the elimination row
 * variable with an earlier role.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/MTX_Inverse44.c
 *       --func MTX_Inverse44 --addr 0x0206AB18 --arm --cc ../2.0/sp2
 */

typedef int s32;
typedef s32 fx32;
typedef long long fx64;
typedef long long fx64c;

typedef struct { fx32 m[4][4]; } MtxFx44;

extern void MI_Copy64B(const void *src, void *dst);
extern void MTX_Identity44_(MtxFx44 *pDst);
extern fx64c FX_InvFx64c(fx32 v);

static inline fx32 FX_Mul32x64c(fx32 v32, fx64c v64c)
{
    fx64 tmp = v64c * v32 + 0x80000000LL;
    return (fx32)(tmp >> 32);
}

int MTX_Inverse44(const MtxFx44 *pSrc, MtxFx44 *pDst)
{
    MtxFx44 tmp;
    int i, j, k, r;
    fx32 max;

    MI_Copy64B(pSrc, &tmp);
    MTX_Identity44_(pDst);

    for (i = 0; i < 4; ++i) {
        j = i;
        max = 0;
        for (r = i; r < 4; ++r) {
            fx32 ftmp = tmp.m[r][i];
            if (ftmp < 0)
                ftmp = -ftmp;
            if (ftmp > max) {
                max = ftmp;
                j = r;
            }
        }
        if (max == 0)
            return -1;
        if (j != i) {
            for (k = 0; k < 4; ++k) {
                fx32 x;
                x = tmp.m[i][k];
                tmp.m[i][k] = tmp.m[j][k];
                tmp.m[j][k] = x;
                x = pDst->m[i][k];
                pDst->m[i][k] = pDst->m[j][k];
                pDst->m[j][k] = x;
            }
        }
        {
            fx64c recip = FX_InvFx64c(tmp.m[i][i]);
            for (k = 0; k < 4; ++k) {
                tmp.m[i][k] = FX_Mul32x64c(tmp.m[i][k], recip);
                pDst->m[i][k] = FX_Mul32x64c(pDst->m[i][k], recip);
            }
        }
        for (j = 0; j < 4; ++j) {
            if (j != i) {
                fx32 a = tmp.m[j][i];
                for (k = 0; k < 4; ++k) {
                    tmp.m[j][k] -= (fx32)(((fx64)a * tmp.m[i][k]) >> 12);
                    pDst->m[j][k] -= (fx32)(((fx64)a * pDst->m[i][k]) >> 12);
                }
            }
        }
    }
    return 0;
}
