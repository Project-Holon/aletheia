/*
 * function: G3i_OrthoW_
 * address:  0x0207D760
 * packet:   pkt_0207D760
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G3i_FrustumW_ (libgx.TWL.HYB.a g3_util.o)
 *
 * symbols:
 *   MTX_FrustumW   0x0207C554  arm
 *   G3_LoadMtx44   0x0207D8C4  arm
 */

typedef long fx32;
typedef unsigned long u32;
typedef int BOOL;
typedef volatile u32 vu32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

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

typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
        fx32 _30, _31, _32;
    };
    fx32 m[4][3];
    fx32 a[12];
} MtxFx43;

typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;

#define reg_G3X_GXFIFO      (*(vu32 *)0x04000400)
#define reg_G3_MTX_MODE     (*(vu32 *)0x04000440)
#define reg_G3_MTX_MULT_3x3 (*(vu32 *)0x04000468)

extern void MTX_FrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
extern void G3_LoadMtx44(const MtxFx44 *m);

void G3i_OrthoW_(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, BOOL draw, MtxFx44 *mtx)
{
    MtxFx44 tmp[1];

    if (!mtx) {
        mtx = tmp;
    }
    MTX_FrustumW(t, b, l, r, n, f, scaleW, mtx);
    if (draw) {
        reg_G3_MTX_MODE = 0;
        G3_LoadMtx44(mtx);
    }
}
