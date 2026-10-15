/*
 * function: WEATHER_TASK_GetCameraScroll
 * address:  0x021A244C
 * packet:   pkt_ov021_021A244C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_0207C768 is FX_Div, VEC_Distance VEC_Distance.
 *
 * symbols:
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   VEC_Distance  0x0207CF3C  arm
 *   WEATHER_TASK_GetViewScale  0x021A2D30  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   g_DefaultProjectionMtx  0x02148B54  data
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00954.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef s32 fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

extern u8 g_DefaultProjectionMtx[];
extern void *FIELD_CAMERA_GetG3dCamera(void);
extern void func_02048B30(void *cam, VecFx32 *out);
extern void func_02048AE8(void *cam, VecFx32 *out);
extern fx32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern void WEATHER_TASK_GetViewScale(void *p, fx32 dist, fx32 *w, fx32 *h);
extern u32 func_0207C768(u32 a, u32 b);

void WEATHER_TASK_GetCameraScroll(u8 *o, s32 *outX, s32 *outY)
{
    VecFx32 pos;
    VecFx32 tgt;
    fx32 w;
    fx32 h;
    fx32 dx;
    fx32 dz;
    fx32 sx;
    fx32 sy;
    void *cam;

    if (((struct Obj00954 *)o)->f14 == 0) {
        *outX = 0;
        *outY = 0;
        return;
    }
    cam = FIELD_CAMERA_GetG3dCamera();
    func_02048B30(cam, &pos);
    func_02048AE8(cam, &tgt);
    dx = pos.x - ((VecFx32 *)(o + 0x68))->x;
    dz = pos.z - ((VecFx32 *)(o + 0x68))->z;
    if ((dx < 0 ? -dx : dx) > 0x3E8000 || (dz < 0 ? -dz : dz) > 0x64000) {
        *(VecFx32 *)(o + 0x68) = pos;
        *outX = 0;
        *outY = 0;
        return;
    }
    WEATHER_TASK_GetViewScale(g_DefaultProjectionMtx, VEC_Distance(&pos, &tgt), &w, &h);
    w = func_0207C768(w, 0x100000);
    h = func_0207C768(h, 0xC0000);
    sx = 0x1000;
    if (dx < 0) {
        sx = -0x1000;
        dx = -dx;
    }
    dx = func_0207C768(dx, w);
    if (sx < 0) {
        dx = 0 - dx;
        dx += 0x1000;
    }
    sy = 0x1000;
    if (dz < 0) {
        sy = -0x1000;
        dz = -dz;
    }
    dz = func_0207C768(dz, h);
    if (sy < 0) {
        dz = 0 - dz;
        dz += 0x1000;
    }
    if (dx + dz != 0) {
        *(VecFx32 *)(o + 0x68) = pos;
    }
    *outX = dx >> 12;
    *outY = dz >> 12;
}
