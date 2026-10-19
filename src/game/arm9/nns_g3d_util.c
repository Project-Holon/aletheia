/*
 * file:     nns_g3d_util.c
 * unit:     yes
 * function: NNS_G3dWorldPosToScrPos, NNS_G3dScrPosToWorldLine
 * address:  0x0206DF3C
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_renderState     0x02148B4C  data
 *   MTX_MultVec43  0x0207BC08  arm
 *   FX_InvAsync  0x0207C8A0  arm
 *   FX_GetDivResultFx64c  0x0207C848  arm
 *   NNS_G3dGlbGetViewPort  0x0206AE94  arm
 *   FX_Div  0x0207C768  arm
 *   NNS_G3dGlbGetInvVPMtx  0x0206AE2C  arm
 */
#include "nns_g3d_glb_types.h"

typedef long long fx64;

typedef long long fx64c;

extern void MTX_MultVec43(const VecFx32 *src, const MtxFx43 *m, VecFx32 *dst);
extern void FX_InvAsync(fx32 d);
extern fx64c FX_GetDivResultFx64c(void);
extern void NNS_G3dGlbGetViewPort(u32 *x1, u32 *y1, u32 *x2, u32 *y2);
extern u32 FX_Div(u32 a, u32 b);
extern void *NNS_G3dGlbGetInvVPMtx(void);
int NNS_G3dWorldPosToScrPos(const VecFx32 *pWorld, int *px, int *py);
int NNS_G3dScrPosToWorldLine(int px, int py, VecFx32 *pNear, VecFx32 *pFar);
extern NNSG3dGlb g_renderState;

inline static fx32 FX_Mul32x64c(fx32 v32, fx64c v64c)
{
  fx64 tmp = (v64c * v32) + 0x80000000LL;
  return (fx32) (tmp >> 32);
}


/*
 * NitroSystem G3D NNS_G3dWorldPosToScrPos (util.c): world position to screen
 * pixel. The camera matrix and projection matrix are members of the G3D
 * global state object at 0x02148B4C (NNS_G3dGlb: projMtx at +8, cameraMtx at
 * +0x4c, viewport word at +0xa0 which NNS_G3dGlbGetViewPort unpacks). Returns -1 when
 * the point projects outside [0, FX32_ONE] in x or y, else 0.
 *
 * Levers found by tools/permuter.py (hill + anneal, 149 -> 25 bytes) and by
 * hand (25 -> 0): the projection pointer is taken BEFORE the MultVec43 call
 * (so it lives in r6 across it), the w and x/y dot products each go through
 * a named temporary, the matrix pointer m is the LAST declared local, and the viewport
 * extents x2-x1 / y2-y1 are named locals computed before the *px store.
 * Byte-identical under dsi/1.1p1 as well; pinned ../2.0/sp2 with the cluster.
 */
int NNS_G3dWorldPosToScrPos(const VecFx32 *pWorld, int *px, int *py)
{
    VecFx32 vec;
    int x1, y1, x2, y2;
    int ret;
    fx32 w, x, y;
    fx64c invW;
    const MtxFx44 *m;
    fx32 ty;

    m = &g_renderState.projMtx;
    MTX_MultVec43(pWorld, &g_renderState.cameraMtx, &vec);   /* MTX_MultVec43 */

    {
        fx32 tw = (fx32)(((fx64)vec.x * m->_03 + (fx64)vec.y * m->_13 + (fx64)vec.z * m->_23) >> 12);
        w = tw + m->_33;
    }
    FX_InvAsync(w);                                    /* FX_InvAsync */

    {
        fx64 tx = ((fx64)vec.x * m->_00 + (fx64)vec.y * m->_10 + (fx64)vec.z * m->_20) >> 12;
        ty = (fx32)(((fx64)vec.x * m->_01 + (fx64)vec.y * m->_11 + (fx64)vec.z * m->_21) >> 12);
        x = (fx32)tx + m->_30;
        y = ty + m->_31;
    }

    invW = FX_GetDivResultFx64c();                              /* FX_GetInvResultFx64c */
    x = (FX_Mul32x64c(x, invW) + 0x1000) / 2;
    y = (FX_Mul32x64c(y, invW) + 0x1000) / 2;

    ret = 0;
    if (x < 0 || y < 0 || x > 0x1000 || y > 0x1000)
        ret = -1;

    NNS_G3dGlbGetViewPort((u32 *)(&x1), (u32 *)(&y1), (u32 *)(&x2), (u32 *)(&y2));                   /* NNS_G3dGlbGetViewPort */
    {
        int dx = x2 - x1;
        int dy = y2 - y1;
        *px = x1 + ((x * dx + 0x800) >> 12);
        *py = 191 - y1 - ((y * dy + 0x800) >> 12);
    }
    return ret;
}


/*
 * NitroSystem G3D NNS_G3dScrPosToWorldLine (util.c): screen pixel to the
 * world-space near point (and, when pFar is non-null, far point) through the
 * inverse view-projection matrix NNS_G3dGlbGetInvVPMtx returns. FX_Div is
 * FX_Div, FX_InvAsync FX_InvAsync, FX_GetInvResultFx64c
 * FX_GetDivResultFx64c, the viewport unpack NNS_G3dGlbGetViewPort. Returns -1 when the
 * pixel is outside the viewport, else 0.
 *
 * Two levers: the viewport extents are named locals dx/dy (dy = y2 - y1 is
 * computed before the first FX_Div and lives in r5 across it), and the far
 * point's spilled words are declared fw, fx, fy (fw at sp+8, fy at sp+0).
 * DISCRIMINATING PIN: dsi/1.1p1 compiles the same C to 648 bytes (the rval
 * arms are laid out differently); ../2.0/sp2 is byte-exact.
 */
int NNS_G3dScrPosToWorldLine(int px, int py, VecFx32 *pNear, VecFx32 *pFar)
{
    int x1, y1, x2, y2;
    fx32 x, y;
    int rval;
    const MtxFx44 *m;
    fx32 w, nx, ny, nz, fw, fx, fy, fz;
    fx64c invW;

    NNS_G3dGlbGetViewPort((unsigned int *)(&x1), (unsigned int *)(&y1), (unsigned int *)(&x2), (unsigned int *)(&y2));
    {
        int dx = x2 - x1;
        int dy = y2 - y1;
        x = FX_Div((px - x1) << 12, dx << 12);
        y = FX_Div((py + y1 - 191) << 12, -dy << 12);
    }
    if (x < 0 || y < 0 || x > 0x1000 || y > 0x1000)
        rval = -1;
    else
        rval = 0;
    x = (x - 0x800) * 2;
    y = (y - 0x800) * 2;

    m = NNS_G3dGlbGetInvVPMtx();
    w = (fx32)(((fx64)x * m->_03 + (fx64)y * m->_13) >> 12) + m->_33;
    FX_InvAsync(w - m->_23);
    nx = (fx32)(((fx64)x * m->_00 + (fx64)y * m->_10) >> 12) + m->_30;
    ny = (fx32)(((fx64)x * m->_01 + (fx64)y * m->_11) >> 12) + m->_31;
    nz = (fx32)(((fx64)x * m->_02 + (fx64)y * m->_12) >> 12) + m->_32;
    if (pFar) {
        fx = nx + m->_20;
        fy = ny + m->_21;
        fz = nz + m->_22;
        fw = w + m->_23;
    }
    nx -= m->_20;
    ny -= m->_21;
    nz -= m->_22;
    invW = FX_GetDivResultFx64c();
    if (pFar)
        FX_InvAsync(fw);
    pNear->x = FX_Mul32x64c(nx, invW);
    pNear->y = FX_Mul32x64c(ny, invW);
    pNear->z = FX_Mul32x64c(nz, invW);
    if (pFar) {
        invW = FX_GetDivResultFx64c();
        pFar->x = FX_Mul32x64c(fx, invW);
        pFar->y = FX_Mul32x64c(fy, invW);
        pFar->z = FX_Mul32x64c(fz, invW);
    }
    return rval;
}
