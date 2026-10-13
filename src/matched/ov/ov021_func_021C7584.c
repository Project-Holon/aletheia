/*
 * function: FIELD_TASK_UpdatePlayerPosTween
 * address:  0x021C7584
 * packet:   pkt_ov021_021C7584
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   BUTTON_MAN_ScaleVec  0x020520A4  arm
 *   func_0207C9D0  0x0207C9D0  arm
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

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
struct Vec3;
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern int FLDMMDL_MOVE_UpdateHeight(int a);
extern void BUTTON_MAN_ScaleVec(const struct Vec3 *v, int s, struct Vec3 *dst);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *c);

#define FX32_ONE 0x1000
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

int FIELD_TASK_UpdatePlayerPosTween(Work *w)
{
    void *o;
    void *m;
    fx32 t;
    VecFx32 a;
    VecFx32 b;
    VecFx32 c;

    o = FIELDMAP_GetFieldPlayer(w->id);
    m = FIELD_PLAYER_GetMmdl(o);
    switch (w->state) {
    case 0:
        FIELD_PLAYER_GetPos(o, &w->from);
        w->state++;
        break;
    case 1:
        w->cnt++;
        t = FX_F32_TO_FX32((f32)w->cnt / (f32)w->max);
        BUTTON_MAN_ScaleVec((const struct Vec3 *)(&w->from), FX32_ONE - t, (struct Vec3 *)(&a));
        BUTTON_MAN_ScaleVec((const struct Vec3 *)(&w->to), t, (struct Vec3 *)(&b));
        func_0207C9D0(&a, &b, &c);
        FIELD_PLAYER_SetPos(o, &c);
        FLDMMDL_MOVE_UpdateHeight((int)m);
        if (w->max <= w->cnt)
            return 1;
        break;
    }
    return 0;
}
