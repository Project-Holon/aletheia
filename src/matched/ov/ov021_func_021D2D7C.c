/*
 * function: FIELD_CAMERA_ShakeTask
 * address:  0x021D2D7C
 * packet:   pkt_ov021_021D2D7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task step: case 2 swings the object on a sine of tick/steps. The zero
 * vector is a block-scoped `= {0, 0, 0}` (base pointer then three stores);
 * the offset's products are named locals stored after the position copy.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetEyeShift  0x0218ED04  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   FX_SinCosTable_     0x020A1B38  data   a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct Work {
    s16 x;
    s16 y;
    s16 dx;
    s16 dy;
    u16 thresh;
    u16 cnt;
    u16 period;
    u8  total;
    u8  left;
    u32 steps;
    u32 tick;
    Vec *pos;
} Work;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *func_020124E8(struct Obj *p);
extern void *FIELDMAP_GetCamera(void *o);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *p);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_CAMERA_SetEyeShift(u8 *p, const struct Vec *v);
extern void FIELD_CAMERA_SetTraceTarget(void *h, Vec *v);
extern void FIELD_CAMERA_RestartDelay(unsigned char *a);
extern void FIELD_CAMERA_SetTarget(void *h, Vec *v);
extern const s16 FX_SinCosTable_[];

int FIELD_CAMERA_ShakeTask(void *task, int *state)
{
    Work *w;
    void *o;
    void *h;
    int done;
    u16 ang;
    int s;

    done = 0;
    o = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(task));
    w = func_020124E8(task);
    h = FIELDMAP_GetCamera(o);

    switch (*state) {
    case 0:
        FIELD_CAMERA_EndDelay(h);
        (*state)++;
        break;
    case 1:
        if (FIELD_CAMERA_IsDelayEnabled(h) == 0) {
            w->pos = (Vec *)FIELD_CAMERA_GetTraceTarget(h);
            FIELD_CAMERA_StopTargetTrace(h);
            (*state)++;
        }
        break;
    case 2:
        w->tick++;
        ang = (w->tick << 16) / w->steps;
        if (w->thresh != 0 && w->total - w->left >= w->thresh) {
            w->cnt++;
            if (w->cnt >= w->period) {
                w->cnt = 0;
                w->y -= w->dy;
                w->x -= w->dx;
                if (w->y <= 0) {
                    w->y = 1;
                }
                if (w->x <= 0) {
                    w->x = 1;
                }
            }
        }
        if (w->tick >= w->steps) {
            w->left--;
            w->tick = 0;
        }
        if (w->left == 0) {
            w->tick = 0;
            done = 1;
        }
        if (done) {
            Vec zero = {0, 0, 0};
            FIELD_CAMERA_SetEyeShift(h, &zero);
            FIELD_CAMERA_SetTraceTarget(h, w->pos);
            FIELD_CAMERA_RestartDelay(h);
            (*state)++;
        } else {
            Vec pos;
            Vec ofs;
            int ox, oy;
            s = FX_SinCosTable_[(ang >> 4) * 2];
            ox = w->x * s;
            oy = w->y * s;
            pos = *w->pos;
            pos.x += ox;
            pos.y += oy;
            ofs.x = ox;
            ofs.y = oy;
            ofs.z = 0;
            FIELD_CAMERA_SetTarget(h, &pos);
            FIELD_CAMERA_SetEyeShift(h, &ofs);
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
