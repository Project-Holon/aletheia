/*
 * function: FIELD_TASK_UpdateCameraTargetTween
 * address:  0x021C7B1C
 * packet:   pkt_ov021_021C7B1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 *   BUTTON_MAN_ScaleVec  0x020520A4  arm
 *   VEC_Add  0x0207C9D0  arm
 *   _fgr           0x0209BBB0  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef int fx32;
typedef float f32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

typedef struct {
    u8 state;
    u8 pad[3];
    void *id;
    int cnt;
    int max;
    VecFx32 from;
    VecFx32 to;
} Work;

extern void *FIELDMAP_GetCamera(void *o);
extern void FIELD_CAMERA_GetTargetShift(void *o, VecFx32 *out);
extern void FIELD_CAMERA_SetTargetShift(void *o, VecFx32 *v);
struct Vec3;
extern void BUTTON_MAN_ScaleVec(const struct Vec3 *v, int s, struct Vec3 *dst);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *c);

#define FX32_ONE 0x1000
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

int FIELD_TASK_UpdateCameraTargetTween(Work *w)
{
    void *o;
    fx32 t;
    VecFx32 a;
    VecFx32 b;
    VecFx32 c;

    o = FIELDMAP_GetCamera(w->id);
    switch (w->state) {
    case 0:
        FIELD_CAMERA_GetTargetShift(o, &w->from);
        w->state++;
        break;
    case 1:
        w->cnt++;
        t = FX_F32_TO_FX32((f32)w->cnt / (f32)w->max);
        BUTTON_MAN_ScaleVec((const struct Vec3 *)(&w->from), FX32_ONE - t, (struct Vec3 *)(&a));
        BUTTON_MAN_ScaleVec((const struct Vec3 *)(&w->to), t, (struct Vec3 *)(&b));
        VEC_Add(&a, &b, &c);
        FIELD_CAMERA_SetTargetShift(o, &c);
        if (w->max <= w->cnt)
            return 1;
        break;
    }
    return 0;
}
