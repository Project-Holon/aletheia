/*
 * function: func_021C7584
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02164010  0x02164010  thumb  ov010
 *   func_020520A4  0x020520A4  arm
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

extern void *func_02188CB4(void *p);
extern void *func_021A3074(void *p);
extern void func_021A3038(void *p, VecFx32 *out);
extern void func_021A3044(void *p, const VecFx32 *v);
extern void func_02164010(void *m);
extern void func_020520A4(const VecFx32 *v, fx32 s, VecFx32 *o);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *c);

#define FX32_ONE 0x1000
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

int func_021C7584(Work *w)
{
    void *o;
    void *m;
    fx32 t;
    VecFx32 a;
    VecFx32 b;
    VecFx32 c;

    o = func_02188CB4(w->id);
    m = func_021A3074(o);
    switch (w->state) {
    case 0:
        func_021A3038(o, &w->from);
        w->state++;
        break;
    case 1:
        w->cnt++;
        t = FX_F32_TO_FX32((f32)w->cnt / (f32)w->max);
        func_020520A4(&w->from, FX32_ONE - t, &a);
        func_020520A4(&w->to, t, &b);
        func_0207C9D0(&a, &b, &c);
        func_021A3044(o, &c);
        func_02164010(m);
        if (w->max <= w->cnt)
            return 1;
        break;
    }
    return 0;
}
