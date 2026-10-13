/*
 * function: FIELD_CAMERA_GetG3dUp
 * address:  0x0218ED20
 * packet:   pkt_ov021_0218ED20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf: forwards the handle at +0xc to G3D_CAMERA_GetTarget.
 * Filed as the only unmatched callee of ov056 func_021F392C.
 *
 * symbols:
 *   G3D_CAMERA_GetTarget  0x02048B0C  arm
 */
#include "../include/Obj19565.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void G3D_CAMERA_GetTarget(u32 h, void *out);

void FIELD_CAMERA_GetG3dUp(void *p, void *out)
{
    G3D_CAMERA_GetTarget(((struct Obj19565 *)p)->fC, out);
}
