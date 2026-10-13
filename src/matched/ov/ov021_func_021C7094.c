/*
 * function: FIELD_TASK_InitCameraAngleTween
 * address:  0x021C7094
 * packet:   pkt_ov021_021C7094
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_GetYaw  0x0218ED40  thumb  ov021
 *   FIELD_CAMERA_GetPitch  0x0218ED2C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FIELD_CAMERA_GetYaw(u8 *p);
extern u16 FIELD_CAMERA_GetPitch(u8 *p);

void FIELD_TASK_InitCameraAngleTween(u32 *p)
{
    u32 m = p[2];
    u32 a = p[1];
    u32 b = p[6];
    u32 d;

    if (m == 0 || m != 1)
        a = FIELD_CAMERA_GetYaw((u8 *)a);
    else
        a = FIELD_CAMERA_GetPitch((u8 *)a);
    if (a < b) {
        d = b - a;
        if (d > 0x8000)
            a += 0x10000;
    } else if (b < a) {
        d = a - b;
        if (d > 0x8000)
            b += 0x10000;
    }
    p[5] = a;
    p[6] = b;
}
