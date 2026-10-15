/*
 * file:     g3_util.c
 * unit:     yes
 * function: G3i_PerspectiveW_, G3i_OrthoW_, G3i_LookAt_, G3_RotX, G3_RotY, G3_RotZ
 * address:  0x0207D704
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MTX_PerspectiveW   0x0207C408  arm
 *   G3_LoadMtx44       0x0207D8C4  arm
 *   MTX_FrustumW   0x0207C554  arm
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

extern void MTX_PerspectiveW(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
extern void G3_LoadMtx44(const MtxFx44 *m);
extern void MTX_FrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
extern void MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx);
extern void G3_LoadMtx43(const MtxFx43 *m);
void G3i_PerspectiveW_(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, BOOL draw, MtxFx44 *mtx);
void G3i_OrthoW_(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, BOOL draw, MtxFx44 *mtx);
void G3i_LookAt_(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, BOOL draw, MtxFx43 *mtx);
void G3_RotX(fx32 s, fx32 c);
void G3_RotY(fx32 s, fx32 c);
void G3_RotZ(fx32 s, fx32 c);


#define reg_G3X_GXFIFO      (*(vu32 *)0x04000400)

#define reg_G3_MTX_MODE     (*(vu32 *)0x04000440)

#define reg_G3_MTX_MULT_3x3 (*(vu32 *)0x04000468)


/*
 * sdk:      G3i_PerspectiveW_ (libgx.TWL.HYB.a g3_util.o)
 */
void G3i_PerspectiveW_(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, BOOL draw, MtxFx44 *mtx)
{
    MtxFx44 tmp[1];

    if (!mtx) {
        mtx = tmp;
    }
    MTX_PerspectiveW(fovySin, fovyCos, aspect, n, f, scaleW, mtx);
    if (draw) {
        reg_G3_MTX_MODE = 0;
        G3_LoadMtx44(mtx);
    }
}


#define reg_G3X_GXFIFO      (*(vu32 *)0x04000400)

#define reg_G3_MTX_MODE     (*(vu32 *)0x04000440)

#define reg_G3_MTX_MULT_3x3 (*(vu32 *)0x04000468)


/*
 * sdk:      G3i_FrustumW_ (libgx.TWL.HYB.a g3_util.o)
 */
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


#define reg_G3X_GXFIFO      (*(vu32 *)0x04000400)

#define reg_G3_MTX_MODE     (*(vu32 *)0x04000440)

#define reg_G3_MTX_MULT_3x3 (*(vu32 *)0x04000468)


/*
 * sdk:      G3i_LookAt_ (libgx.TWL.HYB.a g3_util.o)
 */
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


#define reg_G3X_GXFIFO      (*(vu32 *)0x04000400)

#define reg_G3_MTX_MODE     (*(vu32 *)0x04000440)

#define reg_G3_MTX_MULT_3x3 (*(vu32 *)0x04000468)


/*
 * sdk:      G3_RotX (libgx.TWL.HYB.a g3_util.o)
 */
void G3_RotX(fx32 s, fx32 c)
{
    reg_G3_MTX_MULT_3x3 = 0x1000;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = (u32)c;
    reg_G3_MTX_MULT_3x3 = (u32)s;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = (u32)-s;
    reg_G3_MTX_MULT_3x3 = (u32)c;
}


#define reg_G3X_GXFIFO      (*(vu32 *)0x04000400)

#define reg_G3_MTX_MODE     (*(vu32 *)0x04000440)

#define reg_G3_MTX_MULT_3x3 (*(vu32 *)0x04000468)


/*
 * sdk:      G3_RotY (libgx.TWL.HYB.a g3_util.o)
 */
void G3_RotY(fx32 s, fx32 c)
{
    reg_G3_MTX_MULT_3x3 = (u32)c;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = (u32)-s;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = 0x1000;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = (u32)s;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = (u32)c;
}


#define reg_G3X_GXFIFO      (*(vu32 *)0x04000400)

#define reg_G3_MTX_MODE     (*(vu32 *)0x04000440)

#define reg_G3_MTX_MULT_3x3 (*(vu32 *)0x04000468)


/*
 * sdk:      G3_RotZ (libgx.TWL.HYB.a g3_util.o)
 */
void G3_RotZ(fx32 s, fx32 c)
{
    reg_G3_MTX_MULT_3x3 = (u32)c;
    reg_G3_MTX_MULT_3x3 = (u32)s;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = (u32)-s;
    reg_G3_MTX_MULT_3x3 = (u32)c;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = 0;
    reg_G3_MTX_MULT_3x3 = 0x1000;
}
