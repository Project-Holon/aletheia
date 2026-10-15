/*
 * function: G3i_LookAt_
 * address:  0x0207D7C4
 * packet:   pkt_0207D7C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G3i_LookAt_ (libgx.TWL.HYB.a g3_util.o)
 *
 * symbols:
 *   MTX_LookAt     0x0207BCA0  arm
 *   G3_LoadMtx43   0x0207D8E0  arm
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

extern void MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx);
extern void G3_LoadMtx43(const MtxFx43 *m);

void G3i_LookAt_(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, BOOL draw, MtxFx43 *mtx)
{
    MtxFx43 tmp[1];

    if (!mtx) {
        mtx = tmp;
    }
    MTX_LookAt(camPos, camUp, target, mtx);
    if (draw) {
        reg_G3_MTX_MODE = 2;
        G3_LoadMtx43(mtx);
    }
}
