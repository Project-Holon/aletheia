/*
 * function: FIELD_GIMMICK_LIFT_ELEVATOR_UpdateCameraShake
 * address:  0x021F4210
 * packet:   pkt_ov043_021F4210
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 */
#include "../include/Obj01223.h"

typedef unsigned char u8;

extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_CAMERA_SetTraceTarget(int p, int v);
extern void FIELD_CAMERA_GetTargetShift(int p, int *v);
extern void FIELD_CAMERA_SetTargetShift(int p, void *v);

int FIELD_GIMMICK_LIFT_ELEVATOR_UpdateCameraShake(u8 *s)
{
    int v[3];

    switch (s[0]) {
    case 0:
        FIELD_CAMERA_StopTargetTrace((u8 *)(((struct Obj01223 *)s)->f8));
        s[0]++;
    case 1:
        if (s[3] % 2 == 0) {
            FIELD_CAMERA_GetTargetShift(((struct Obj01223 *)s)->f8, v);
            v[1] = v[1] + ((struct Obj01223 *)s)->f4;
            FIELD_CAMERA_SetTargetShift(((struct Obj01223 *)s)->f8, v);
            ((struct Obj01223 *)s)->f4 *= -1;
            s[1]++;
            if (s[1] >= s[2] * 2) {
                if (((struct Obj01223 *)s)->fC) {
                    FIELD_CAMERA_SetTraceTarget(((struct Obj01223 *)s)->f8, ((struct Obj01223 *)s)->fC);
                }
                FIELD_CAMERA_SetTargetShift(((struct Obj01223 *)s)->f8, s + 0x10);
                return 1;
            }
        }
        s[3] = (s[3] + 1) % 2;
    }
    return 0;
}
