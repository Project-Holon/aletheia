/*
 * function: NNS_G3dWorldPosToScrPos
 * address:  0x0206DF3C
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem G3D NNS_G3dWorldPosToScrPos (util.c): world position to screen
 * pixel. The camera matrix and projection matrix are members of the G3D
 * global state object at 0x02148B4C (NNS_G3dGlb: prjMtx at +8, cameraMtx at
 * +0x4c, viewport word at +0xa0 which NNS_G3dGlbGetViewPort unpacks). Returns -1 when
 * the point projects outside [0, FX32_ONE] in x or y, else 0.
 *
 * Levers found by tools/permuter.py (hill + anneal, 149 -> 25 bytes) and by
 * hand (25 -> 0): the projection pointer is taken BEFORE the MultVec43 call
 * (so it lives in r6 across it), the w and x/y dot products each go through
 * a named temporary, the matrix pointer m is the LAST declared local, and the viewport
 * extents x2-x1 / y2-y1 are named locals computed before the *px store.
 * Byte-identical under dsi/1.1p1 as well; pinned ../2.0/sp2 with the cluster.
 *
 * symbols:
 *   g_renderState     0x02148B4C  data
 *   MTX_MultVec43  0x0207BC08  arm
 *   FX_InvAsync  0x0207C8A0  arm
 *   func_0207C848  0x0207C848  arm
 *   NNS_G3dGlbGetViewPort  0x0206AE94  arm
 */
typedef int s32;
typedef int fx32;
typedef long long fx64;
typedef long long fx64c;
typedef struct 
{
  fx32 x;
  fx32 y;
  fx32 z;
} VecFx32;
typedef struct 
{
  fx32 _00;
  fx32 _01;
  fx32 _02;
  fx32 _03;
  fx32 _10;
  fx32 _11;
  fx32 _12;
  fx32 _13;
  fx32 _20;
  fx32 _21;
  fx32 _22;
  fx32 _23;
  fx32 _30;
  fx32 _31;
  fx32 _32;
  fx32 _33;
} MtxFx44;
typedef struct 
{
  fx32 m[4][3];
} MtxFx43;
typedef struct 
{
  int cmd0;
  int mtxmode;
  MtxFx44 prjMtx;
  int cmd1;
  MtxFx43 cameraMtx;
} Glb;
extern Glb g_renderState;
extern void MTX_MultVec43(const VecFx32 *src, const MtxFx43 *m, VecFx32 *dst);
extern void FX_InvAsync(fx32 d);
extern fx64c func_0207C848(void);
typedef unsigned int   u32;
extern void NNS_G3dGlbGetViewPort(u32 *a0, u32 *a1, u32 *a2, u32 *a3);
inline static fx32 FX_Mul32x64c(fx32 v32, fx64c v64c)
{
  fx64 tmp = (v64c * v32) + 0x80000000LL;
  return (fx32) (tmp >> 32);
}

int NNS_G3dWorldPosToScrPos(const VecFx32 *pWorld, int *px, int *py)
{
    VecFx32 vec;
    int x1, y1, x2, y2;
    int ret;
    fx32 w, x, y;
    fx64c invW;
    const MtxFx44 *m;
    fx32 ty;

    m = &g_renderState.prjMtx;
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

    invW = func_0207C848();                              /* FX_GetInvResultFx64c */
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
