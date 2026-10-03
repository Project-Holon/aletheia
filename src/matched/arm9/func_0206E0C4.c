/*
 * function: func_0206E0C4
 * address:  0x0206E0C4
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem G3D NNS_G3dScrPosToWorldLine (util.c): screen pixel to the
 * world-space near point (and, when pFar is non-null, far point) through the
 * inverse view-projection matrix func_0206AE2C returns. FX_Div is
 * func_0207C768, FX_InvAsync func_0207C8A0, FX_GetInvResultFx64c
 * func_0207C848, the viewport unpack func_0206AE94. Returns -1 when the
 * pixel is outside the viewport, else 0.
 *
 * Two levers: the viewport extents are named locals dx/dy (dy = y2 - y1 is
 * computed before the first FX_Div and lives in r5 across it), and the far
 * point's spilled words are declared fw, fx, fy (fw at sp+8, fy at sp+0).
 * DISCRIMINATING PIN: dsi/1.1p1 compiles the same C to 648 bytes (the rval
 * arms are laid out differently); ../2.0/sp2 is byte-exact.
 *
 * symbols:
 *   func_0206AE94  0x0206AE94  arm
 *   func_0207C768  0x0207C768  arm
 *   func_0206AE2C  0x0206AE2C  arm
 *   func_0207C8A0  0x0207C8A0  arm
 *   func_0207C848  0x0207C848  arm
 */

typedef int fx32;
typedef long long fx64;
typedef long long fx64c;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct {
    fx32 _00, _01, _02, _03;
    fx32 _10, _11, _12, _13;
    fx32 _20, _21, _22, _23;
    fx32 _30, _31, _32, _33;
} MtxFx44;

extern void func_0206AE94(int *x1, int *y1, int *x2, int *y2);
typedef unsigned int   u32;
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_0206AE2C(void);
extern void func_0207C8A0(fx32 d);
extern fx64c func_0207C848(void);

static inline fx32 FX_Mul32x64c(fx32 v32, fx64c v64c)
{
    fx64 tmp = v64c * v32 + 0x80000000LL;
    return (fx32)(tmp >> 32);
}

int func_0206E0C4(int px, int py, VecFx32 *pNear, VecFx32 *pFar)
{
    int x1, y1, x2, y2;
    fx32 x, y;
    int rval;
    const MtxFx44 *m;
    fx32 w, nx, ny, nz, fw, fx, fy, fz;
    fx64c invW;

    func_0206AE94(&x1, &y1, &x2, &y2);
    {
        int dx = x2 - x1;
        int dy = y2 - y1;
        x = func_0207C768((px - x1) << 12, dx << 12);
        y = func_0207C768((py + y1 - 191) << 12, -dy << 12);
    }
    if (x < 0 || y < 0 || x > 0x1000 || y > 0x1000)
        rval = -1;
    else
        rval = 0;
    x = (x - 0x800) * 2;
    y = (y - 0x800) * 2;

    m = func_0206AE2C();
    w = (fx32)(((fx64)x * m->_03 + (fx64)y * m->_13) >> 12) + m->_33;
    func_0207C8A0(w - m->_23);
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
    invW = func_0207C848();
    if (pFar)
        func_0207C8A0(fw);
    pNear->x = FX_Mul32x64c(nx, invW);
    pNear->y = FX_Mul32x64c(ny, invW);
    pNear->z = FX_Mul32x64c(nz, invW);
    if (pFar) {
        invW = func_0207C848();
        pFar->x = FX_Mul32x64c(fx, invW);
        pFar->y = FX_Mul32x64c(fy, invW);
        pFar->z = FX_Mul32x64c(fz, invW);
    }
    return rval;
}
