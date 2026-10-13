/*
 * function: FLD_SCENEAREA_LOADER_ApplySectorCamera
 * address:  0x021AB908
 * packet:   pkt_ov021_021AB908
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever (wave A3): the position is copied field by field with its y kept in
 * the vector (`a.y = p->y`), y is saved by reading it back (`y = a.y`), and
 * a.y is zeroed before the copy of *q. The read keeps the first a.y store
 * alive and puts the zero ahead of the q copy, which gives the colouring
 * (y r7, zero r6, table r4) and lets the final a.y reload become `mov r1, r7`.
 *
 * symbols:
 *   FLD_SCENEAREA_GetCamera  0x021AB760  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   _ll_mul        0x0209C054  arm
 *   FX_SinCosTable_   0x020A1B38  data  a2
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04239.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef int            s32;

typedef struct Vec { s32 x, y, z; } Vec;

extern u32 FLD_SCENEAREA_GetCamera(u8 *p);
extern void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
extern void func_0207CA00(const Vec *a, const Vec *b, Vec *out);
extern void VEC_Normalize(const Vec *v, Vec *out);
extern void FIELD_CAMERA_SetTarget(u32 a, Vec *v);
extern void FIELD_CAMERA_SetEyeRaw(u32 a, Vec *v);
extern s16 FX_SinCosTable_[];

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}

void FLD_SCENEAREA_LOADER_ApplySectorCamera(u32 a0, const u8 *p, const Vec *q)
{
    Vec b;
    Vec a;
    Vec n;
    Vec out;
    u32 obj;
    s32 y;
    s32 c;
    s16 t0;
    s16 t1;

    obj = FLD_SCENEAREA_GetCamera((u8 *)a0);
    FIELD_CAMERA_EnterMode((u8 *)obj, 2);
    a.x = *(const s32 *)&((struct Obj04239 *)p)->f10;
    a.y = *(const s32 *)&((struct Obj04239 *)p)->f14;
    a.z = *(const s32 *)&((struct Obj04239 *)p)->f18;
    y = a.y;
    a.y = 0;
    b = *q;
    b.y = 0;
    func_0207CA00(&b, &a, &b);
    VEC_Normalize(&b, &n);
    t0 = FX_SinCosTable_[(*(const s32 *)&((struct Obj04239 *)p)->f1C >> 4) * 2];
    a.y = y;
    out.y = FX_Mul(t0, *(const s32 *)&((struct Obj04239 *)p)->f20);
    t1 = FX_SinCosTable_[(*(const s32 *)&((struct Obj04239 *)p)->f1C >> 4) * 2 + 1];
    c = FX_Mul(t1, *(const s32 *)&((struct Obj04239 *)p)->f20);
    out.x = FX_Mul(n.x, c);
    out.z = FX_Mul(n.z, c);
    out.x += a.x;
    out.y += a.y;
    out.z += a.z;
    FIELD_CAMERA_SetTarget(obj, &a);
    FIELD_CAMERA_SetEyeRaw(obj, &out);
}
