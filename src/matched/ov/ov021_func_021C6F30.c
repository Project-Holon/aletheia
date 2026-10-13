/*
 * function: FIELD_TASK_UpdateCameraDistanceTween
 * address:  0x021C6F30
 * packet:   pkt_ov021_021C6F30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb
 *   FIELD_CAMERA_GetDistance  0x0218ED54  thumb
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb
 *   _fgr           0x0209BBB0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef int fx32;
typedef float f32;

typedef struct {
    void *f0;
    u8 f4;
    u8 pad5;
    u16 f6;
    u16 f8;
    u16 padA;
    fx32 fC;
    fx32 f10;
} Work;

extern void *FIELDMAP_GetCamera(void *o);
extern u32 FIELD_CAMERA_GetDistance(u8 *p);
extern u32 FIELD_CAMERA_GetMode(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
extern void FIELD_CAMERA_SetDistance(u8 *p, u32 v);

#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

int FIELD_TASK_UpdateCameraDistanceTween(Work *w)
{
    void *o;
    u32 save;
    f32 t;
    f32 a;
    f32 b;
    f32 v;

    o = FIELDMAP_GetCamera(w->f0);
    switch (w->f4) {
    case 0:
        w->fC = FIELD_CAMERA_GetDistance(o);
        w->f4++;
        break;
    case 1:
        w->f6++;
        save = FIELD_CAMERA_GetMode(o);
        FIELD_CAMERA_SetMode(o, 0);
        t = (f32)w->f6 / (f32)w->f8;
        a = FX_FX32_TO_F32(w->fC);
        b = FX_FX32_TO_F32(w->f10);
        v = (1.0f - t) * a + t * b;
        FIELD_CAMERA_SetDistance(o, FX_F32_TO_FX32(v));
        FIELD_CAMERA_SetMode(o, save);
        if (w->f8 <= w->f6)
            return 1;
        break;
    }
    return 0;
}
