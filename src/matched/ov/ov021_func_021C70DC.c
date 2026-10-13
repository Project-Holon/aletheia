/*
 * function: FIELD_TASK_StepCameraAngleTween
 * address:  0x021C70DC
 * packet:   pkt_ov021_021C70DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   _ffixu         0x0209C4C8  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef float f32;

typedef struct {
    u32 w0;
    void *obj;
    u32 mode;
    u16 hc;
    u16 cnt;
    u16 max;
    u16 pad;
    u32 from;
    u32 to;
} Work;

extern u32 FIELD_CAMERA_GetMode(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
extern void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
extern void FIELD_CAMERA_SetYaw(u8 *p, u32 v);

void FIELD_TASK_StepCameraAngleTween(Work *w)
{
    u16 max;
    void *o;
    f32 t;
    f32 s;
    u16 v;
    u32 save;

    max = w->max;
    o = w->obj;
    w->cnt++;
    if (w->cnt > max)
        return;
    t = (f32)w->cnt / (f32)max;
    s = (3.0f + -2.0f * t) * (t * t);
    v = (u16)((1.0f - s) * (f32)w->from + s * (f32)w->to);
    save = FIELD_CAMERA_GetMode(o);
    FIELD_CAMERA_SetMode(o, 0);
    switch (w->mode) {
    case 0:
        FIELD_CAMERA_SetYaw(o, v);
        break;
    case 1:
        FIELD_CAMERA_SetPitch(o, v);
        break;
    }
    FIELD_CAMERA_SetMode(o, save);
}
