/*
 * function: FIELDMAP_TCB_CAMERA_ZOOM_Step
 * address:  0x021C6BB4
 * packet:   pkt_ov021_021C6BB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: `t = 1.0f; t *= a / b;` keeps the fmul by 1.0f; a plain `1.0f * x`
 * or `x * 1.0f` folds away. The FX32 round (x > 0 ? x*4096+0.5 : x*4096-0.5)
 * must go through one float temp so the _ffix and the call are shared.
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fadd          0x0209C95C  arm
 *   _ffix          0x0209C494  arm
 *   _fflt          0x0209BDBC  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   _dsqrt         0x0209C5E0  arm
 *   _fgr           0x0209BBB0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03145.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELDMAP_GetCamera(void *p);
extern void FIELD_CAMERA_SetDistance(u8 *p, u32 v);
extern double _dsqrt(double x);

void FIELDMAP_TCB_CAMERA_ZOOM_Step(u8 *p)
{
    u32 h = (u32)FIELDMAP_GetCamera((void *)(((struct Obj03145 *)p)->f0));
    u32 n = ((struct Obj03145 *)p)->f6;
    float t, a, b, v;

    if (((struct Obj03145 *)p)->f4 <= n) {
        t = 1.0f;
        t *= (float)(u32)((struct Obj03145 *)p)->f4 / (float)n;
        t = (float)_dsqrt((double)t);
        a = (float)((struct Obj03145 *)p)->f8 / 4096.0f;
        b = (float)((struct Obj03145 *)p)->fC / 4096.0f;
        v = (1.0f - t) * a + t * b;
        if (v > 0.0f)
            v = 4096.0f * v + 0.5f;
        else
            v = 4096.0f * v - 0.5f;
        FIELD_CAMERA_SetDistance((u8 *)h, (int)v);
    }
}
