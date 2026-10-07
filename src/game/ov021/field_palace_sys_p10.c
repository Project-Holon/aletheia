/*
 * file:     field_palace_sys_p10.c
 * unit:     yes
 * function: func_021D2D7C, func_021D2EDC, func_021D2F44
 * address:  0x021D2D7C
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
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218ED04  0x0218ED04  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   d_020A1B38     0x020A1B38  data   a2
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021F3CFC  0x021F3CFC  thumb  ov059
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021F37B8  0x021F37B8  thumb  ov064
 */
struct Ctx;
struct Obj;
struct Actor;
struct VecFx32;
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

extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_020124E8(struct Obj *p);
extern void *func_02188C58(void *o);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC54(u8 *p);
extern void func_0218ED04(u8 *p, const struct Vec *v);
extern void func_0218EC30(void *h, Vec *v);
extern void func_0218F05C(unsigned char *a);
extern void func_0218EC90(void *h, Vec *v);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_0215A5EC(void *p);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void *func_021F3CFC(void *a, int *v, u32 b, u32 c);
extern void func_0215897C(void *a, void *b);
extern void *func_021F37B8(int a);
int func_021D2D7C(void *task, int *state);
u32 func_021D2EDC(u32 a, u32 b);
int func_021D2F44(u32 a, u32 b);
extern const s16 d_020A1B38[];


/*
 * Task step: case 2 swings the object on a sine of tick/steps. The zero
 * vector is a block-scoped `= {0, 0, 0}` (base pointer then three stores);
 * the offset's products are named locals stored after the position copy.
 *
 * Addresses are Black-image addresses.
 */
int func_021D2D7C(void *task, int *state)
{
    Work *w;
    void *o;
    void *h;
    int done;
    u16 ang;
    int s;

    done = 0;
    o = func_0201210C(func_020124E4(task));
    w = func_020124E8(task);
    h = func_02188C58(o);

    switch (*state) {
    case 0:
        func_0218F0A8(h);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8(h) == 0) {
            w->pos = (Vec *)func_0218EC5C(h);
            func_0218EC54(h);
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
            func_0218ED04(h, &zero);
            func_0218EC30(h, w->pos);
            func_0218F05C(h);
            (*state)++;
        } else {
            Vec pos;
            Vec ofs;
            int ox, oy;
            s = d_020A1B38[(ang >> 4) * 2];
            ox = w->x * s;
            oy = w->y * s;
            pos = *w->pos;
            pos.x += ox;
            pos.y += oy;
            ofs.x = ox;
            ofs.y = oy;
            ofs.z = 0;
            func_0218EC90(h, &pos);
            func_0218ED04(h, &ofs);
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021D2EDC(u32 a, u32 b)
{
    int v[3];
    void *r7;
    void *s0;
    u32 r6;
    u32 r5;
    void *r;

    r7 = func_0215A5F4((void *)b);
    s0 = func_0215A5DC((void *)b);
    func_0201210C(s0);
    r6 = func_02159B10((void *)a, (void *)b);
    r5 = func_02159B10((void *)a, (void *)b);
    func_0216D88C((const struct Actor *)func_0216DE94(func_0215A5EC((void *)b), r6), (struct VecFx32 *)v);
    r = func_021F3CFC(s0, v, r6, r5);
    if (r == 0) {
        return 1;
    }
    func_0215897C(r7, r);
    return 1;
}


/*
 * func_021F37B8 resolves in ov064 (2026-10-02, lane gA2). Starts exist at
 * 0x021F37B8 in ov041, ov050, ov060 and ov064. ov050 is void(void) and ov060
 * takes two arguments. ov041 is out on two counts: its body ends in a tail
 * call to func_021BE418, which is void (src/matched/ov/ov021_func_021BE418.c,
 * EXACT), so it returns no value for the `t == 0` test; and it hands its
 * argument straight to func_02188D2C and func_021897A0, the type that
 * func_0201210C returns, while this call passes func_0215A5DC(b), which the
 * sibling func_021D2F6C feeds to func_0201210C. ov064's function applies
 * func_0201210C to its argument and returns func_020122C0(arg, 0, cb, 0), a
 * task, which is what func_0215897C(x, t) receives here and in the same-shape
 * siblings func_021D3068 (ov064-only func_021F3ADC) and func_021D3090
 * (func_021F3AC0, ov064). func_021D2F6C and func_021D3018 also call ov064.
 */
int func_021D2F44(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *t = func_021F37B8((int)func_0215A5DC((void *)b));

    if (t == 0) {
        return 1;
    }
    func_0215897C(x, t);
    return 1;
}
