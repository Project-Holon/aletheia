/*
 * function: GIMMICK43_StartCameraShake
 * address:  0x021F41B8
 * packet:   pkt_ov043_021F41B8
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 */
#include "../include/Obj02756.h"

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *p);
extern void FIELD_CAMERA_GetTargetShift(int p, void *v);

void GIMMICK43_StartCameraShake(int a0, int a1, int a2, int a3, u8 *s)
{
    s[0] = 0;
    s[1] = 0;
    ((struct Obj02756 *)s)->f8 = a3;
    ((struct Obj02756 *)s)->fC = FIELD_CAMERA_GetTraceTarget((u8 *)a3);
    FIELD_CAMERA_GetTargetShift(a3, s + 0x10);
    if (a2) {
        ((struct Obj02756 *)s)->f4 = 0x1000;
        s[2] = 2;
    } else {
        if (a0 == 5) {
            ((struct Obj02756 *)s)->f4 = 0x4000;
        } else {
            ((struct Obj02756 *)s)->f4 = 0x2000;
        }
        s[2] = 4;
    }
    if (a1 < 0) {
        ((struct Obj02756 *)s)->f4 *= -1;
    }
}
