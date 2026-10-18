/*
 * function: FIELD_CAMERA_ApplyToG3d
 * address:  0x0218E540
 * packet:   pkt_ov021_0218E540
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds two 12-byte vectors from matrix pairs and pushes them to the owner.
 *
 * symbols:
 *   VEC_Add  0x0207C9D0  arm
 *   G3D_CAMERA_SetCamTarget  0x02048B44  arm
 *   G3D_CAMERA_SetEye  0x02048AFC  arm
 *   FIELD_CAMERA_ApplyDelayToG3d  0x0218F004  thumb  ov021
 *   FIELD_CAMERA_UpdateViewAngles  0x0218E764  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00428.h"

typedef unsigned char u8;

extern void VEC_Add(void *a, void *b, void *c);
extern void G3D_CAMERA_SetCamTarget(int, void *);
extern void G3D_CAMERA_SetEye(int, void *);
extern void FIELD_CAMERA_ApplyDelayToG3d(u8 *a);
extern void FIELD_CAMERA_UpdateViewAngles(u8 *a, void *b, void *c);

void FIELD_CAMERA_ApplyToG3d(u8 *a)
{
    u8 t1[12];
    u8 t0[12];

    VEC_Add(a + 0x54, a + 0x60, t1);
    VEC_Add(a + 0x3C, a + 0x30, t0);
    G3D_CAMERA_SetCamTarget(((struct Obj00428 *)a)->fC, t1);
    G3D_CAMERA_SetEye(((struct Obj00428 *)a)->fC, t0);
    FIELD_CAMERA_ApplyDelayToG3d(a);
    FIELD_CAMERA_UpdateViewAngles(a, t1, a + 0x3C);
}
