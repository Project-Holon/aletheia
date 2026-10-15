/*
 * function: FIELD_CAMERA_PrepareEyeMode
 * address:  0x0218E6F0
 * packet:   pkt_ov021_0218E6F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of FIELD_CAMERA_PrepareTargetMode with mode 0 and the other matrix pair.
 *
 * symbols:
 *   VEC_Subtract  0x0207CA00  arm
 *   FIELD_CAMERA_SetAnglesFromVector  0x0218E674  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01848.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void VEC_Subtract(void *a, void *b, void *c);
typedef unsigned int   u32;
extern void FIELD_CAMERA_SetAnglesFromVector(u8 *a, u32 b);

void FIELD_CAMERA_PrepareEyeMode(u8 *a)
{
    u8 tmp[12];

    if (((struct Obj01848 *)a)->f14 == 0) {
        ((struct Obj01848 *)a)->f7A = ((struct Obj01848 *)a)->f7A + 0x8000;
        ((struct Obj01848 *)a)->f78 = ((struct Obj01848 *)a)->f78 + 0x8000;
    } else {
        VEC_Subtract(a + 0x48, a + 0x3C, tmp);
        FIELD_CAMERA_SetAnglesFromVector(a, (u32)tmp);
    }
}
