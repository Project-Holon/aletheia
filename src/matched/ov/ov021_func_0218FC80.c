/*
 * function: FIELD_CAMERA_UpdateFreeMove
 * address:  0x0218FC80
 * packet:   pkt_ov021_0218FC80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame callback armed by FIELD_CAMERA_StartFreeMove; the three-channel twin of
 * FIELD_CAMERA_UpdateMove (+0x48 and +0x24 vectors, the +0x80 angle, the +0x60 vector).
 *
 * symbols:
 *   FIELD_CAMERA_LerpAngle  0x0218FDF0  thumb  ov021
 *   FIELD_CAMERA_LerpVec  0x0218FD88  thumb  ov021
 *   FIELD_CAMERA_ClearMoveCallback  0x0218FE40  thumb  ov021
 *   G3D_CAMERA_SetFovySin  0x02048B80  arm
 *   G3D_CAMERA_SetFovyCos  0x02048B94  arm
 *   FX_SinCosTable_     0x020A1B38  data   a2
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01348.h"
#include "../include/Obj01491.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

extern u16 FIELD_CAMERA_LerpAngle(u16 *a, u16 *b, s32 d, s32 n);
extern void FIELD_CAMERA_LerpVec(s32 *a, s32 *b, s32 d, s32 n, s32 *out);
extern void FIELD_CAMERA_ClearMoveCallback(u8 *p);
struct Light;
extern void G3D_CAMERA_SetFovySin(struct Light *l, u32 v);
extern void G3D_CAMERA_SetFovyCos(struct Light *l, u32 v);
extern s16 FX_SinCosTable_[];

void FIELD_CAMERA_UpdateFreeMove(u8 *p)
{
    u8 *q;
    u8 *s;
    u8 *t;

    q = p + 0xf0;
    if (((struct Obj01348 *)q)->f9C == 0) {
        return;
    }
    (((struct Obj01348 *)q)->f96)++;
    s = q + 0x34;
    t = q + 0x64;
    if (((struct Obj01348 *)q)->fB4 != 0) {
        FIELD_CAMERA_LerpVec((s32 *)(s + 0xc), (s32 *)(t + 0xc),
                      ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96, (s32 *)(p + 0x48));
        FIELD_CAMERA_LerpVec((s32 *)s, (s32 *)t,
                      ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96, (s32 *)(p + 0x24));
    }
    if (((struct Obj01348 *)q)->fB0 != 0) {
        ((struct Obj01491 *)p)->f80 = FIELD_CAMERA_LerpAngle((u16 *)(s + 0x2c), (u16 *)(t + 0x2c),
                                           ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96);
        G3D_CAMERA_SetFovySin(((struct Obj01491 *)p)->fC, FX_SinCosTable_[(((struct Obj01491 *)p)->f80 >> 4) * 2]);
        G3D_CAMERA_SetFovyCos(((struct Obj01491 *)p)->fC, FX_SinCosTable_[(((struct Obj01491 *)p)->f80 >> 4) * 2 + 1]);
    }
    if (((struct Obj01348 *)q)->fA0 != 0) {
        FIELD_CAMERA_LerpVec((s32 *)(s + 0x18), (s32 *)(t + 0x18),
                      ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96, (s32 *)(p + 0x60));
    }
    if (((struct Obj01348 *)q)->f96 >= ((struct Obj01348 *)q)->f94) {
        ((struct Obj01348 *)q)->f9C = 0;
        FIELD_CAMERA_ClearMoveCallback(p);
    }
}
