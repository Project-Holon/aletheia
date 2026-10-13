/*
 * function: FIELD_CAMERA_ApplyDelayToG3d
 * address:  0x0218F004
 * packet:   pkt_ov021_0218F004
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fetches three vectors from the owner, calls the solver, writes two back.
 *
 * symbols:
 *   G3D_CAMERA_GetUp  0x02048B30  arm
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   G3D_CAMERA_SetUp  0x02048B44  arm
 *   G3D_CAMERA_SetEye  0x02048AFC  arm
 *   FIELD_CAMERA_StepDelay  0x0218ED9C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00428.h"

typedef unsigned char u8;

extern void G3D_CAMERA_GetUp(int, void *);
extern void G3D_CAMERA_GetEye(int, void *);
extern void G3D_CAMERA_SetUp(int, void *);
extern void G3D_CAMERA_SetEye(int, void *);
extern void FIELD_CAMERA_StepDelay(int a, void *b, void *c, void *d, void *e);

void FIELD_CAMERA_ApplyDelayToG3d(u8 *a)
{
    if (*(int *)&((struct Obj00428 *)a)->f1C != 0) {
        u8 d[12];
        u8 v[12];
        u8 c[12];
        u8 b[12];

        G3D_CAMERA_GetUp(((struct Obj00428 *)a)->fC, v);
        G3D_CAMERA_GetEye(((struct Obj00428 *)a)->fC, d);
        FIELD_CAMERA_StepDelay(((struct Obj00428 *)a)->fEC, v, d, b, c);
        G3D_CAMERA_SetUp(((struct Obj00428 *)a)->fC, b);
        G3D_CAMERA_SetEye(((struct Obj00428 *)a)->fC, c);
    }
}
