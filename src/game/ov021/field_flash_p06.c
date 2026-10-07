/*
 * file:     field_flash_p06.c
 * unit:     yes
 * function: func_021C754C, func_021C7584, func_021C7684
 * address:  0x021C754C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
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
 *   func_021C7730  0x021C7730  thumb  ov021
 */
#define FX32_ONE 0x1000
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))
struct Obj00020;
struct Vec3;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Q Q;

typedef struct { u32 x, y, z; } V;

typedef struct { u8 f0; u32 f4; u32 f8; u32 fC; u8 pad[0xc]; V f1C; } X;

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

typedef struct {
    u8    st;
    u32   w4;
    u16   h8;
    u16   ha;
    float fc;
    u32   w10;
} Fx;

extern u16 func_02188C84(u8 *p);
extern Q *func_021C6C70(u32 heap, u32 size, void *fn);
extern u32 func_021C6CCC(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern int func_02164010(int a);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *dst);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *c);
extern void func_021C7730(void);
Q *func_021C754C(u32 a, u32 b, V *v);
int func_021C7584(Work *w);
void *func_021C7684(u32 a, u32 b, int c, int d);

static inline void set3(V *d, u32 x, u32 y, u32 z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

Q *func_021C754C(u32 a, u32 b, V *v)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 0x28, func_021C7584);
    X *x = (X *)func_021C6CCC((u8 *)q);
    x->f0 = 0;
    x->f4 = a;
    x->f8 = 0;
    x->fC = b;
    set3(&x->f1C, v->x, v->y, v->z);
    return q;
}


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
        func_020520A4((const struct Vec3 *)(&w->from), FX32_ONE - t, (struct Vec3 *)(&a));
        func_020520A4((const struct Vec3 *)(&w->to), t, (struct Vec3 *)(&b));
        func_0207C9D0(&a, &b, &c);
        func_021A3044(o, &c);
        func_02164010((int)m);
        if (w->max <= w->cnt)
            return 1;
        break;
    }
    return 0;
}


void *func_021C7684(u32 a, u32 b, int c, int d)
{
    void *o;
    Fx *p;

    o = func_021C6C70(func_02188C84((u8 *)a), 0x14, (void *)func_021C7730);
    p = (Fx *)func_021C6CCC(o);
    p->st = 0;
    p->w4 = a;
    p->h8 = 0;
    p->ha = c;
    p->fc = (float)d;
    p->w10 = b;
    return o;
}
