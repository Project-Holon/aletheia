/*
 * function: FIELD_GIMMICK_CANNONS_UpdateBounce
 * address:  0x021F4000
 * packet:   pkt_ov041_021F4000
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Extent after the 0x80-byte function and pool is rodata, not a follower.
 * symbols:
 *   FIELD_CAMERA_GetEyeRaw  0x0218ECE4  thumb  ov021
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb  ov021
 */
#include "../include/Obj02115.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 a, b, c; } Vec3;
extern void FIELD_CAMERA_GetEyeRaw(u8 *a, Vec3 *out);
extern void FIELD_CAMERA_SetEyeRaw(u8 *a, const Vec3 *p);

void FIELD_GIMMICK_CANNONS_UpdateBounce(u8 *p, u8 *obj)
{
    int step;
    Vec3 v;

    if (((struct Obj02115 *)p)->f0 != 0) {
        p[15]++;
        if (p[12] == 0) {
            if (p[13] % 2 == 0) {
                step = 0x8000;
            } else {
                step = -0x8000;
                p[14]++;
            }
            p[13] = (p[13] + 1) % 2;
            FIELD_CAMERA_GetEyeRaw(obj, &v);
            v.b += step;
            FIELD_CAMERA_SetEyeRaw(obj, &v);
            p[12] = 1;
        } else {
            p[12]--;
        }
        if (p[14] >= 2) {
            ((struct Obj02115 *)p)->f0 = 0;
            ((struct Obj02115 *)p)->f4 = 1;
        }
    }
}
