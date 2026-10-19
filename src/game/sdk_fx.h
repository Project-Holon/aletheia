#ifndef GAME_SDK_FX_H
#define GAME_SDK_FX_H

#include "types.h"

/*
 * Fixed-point vectors and matrices of the SDK math library (libfx).  Matrices
 * are row-major; each one is readable by element (_rc), by row and column (m)
 * or as a flat array (a).
 */

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct VecFx16 {
    fx16 x, y, z;
} VecFx16;

typedef union MtxFx22 {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22;

typedef union MtxFx33 {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;

typedef union MtxFx43 {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
        fx32 _30, _31, _32;
    };
    fx32 m[4][3];
    fx32 a[12];
} MtxFx43;

typedef union MtxFx44 {
    struct {
        fx32 _00, _01, _02, _03;
        fx32 _10, _11, _12, _13;
        fx32 _20, _21, _22, _23;
        fx32 _30, _31, _32, _33;
    };
    fx32 m[4][4];
    fx32 a[16];
} MtxFx44;

#endif
