/*
 * file:     scrcmd_screeneffects_p23.c
 * unit:     yes
 * function: func_021B0AB0, func_021B0ADC, func_021B0B08
 * address:  0x021B0AB0
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
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_0219131C  0x0219131C  thumb  ov021
 *   func_02159144  0x02159144  thumb  ov010
 *   func_0219129C  0x0219129C  thumb  ov021
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A63C  0x0215A63C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_0215A66C  0x0215A66C  thumb  ov010
 *   func_021B0960  0x021B0960  thumb
 */
struct Ent;
struct Ctx;
struct Actor;
struct VecFx32;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct V3 {
    int x, y, z;
} V3;

typedef struct S {
    u16 id;
    u16 pad;
    V3 sum;
    V3 a;
    V3 b;
} S;

extern int func_02159190(int a0);
extern int func_0215A61C(int a0);
extern int func_0219131C(u32 a);
extern void func_0215A614(u8 *p, u32 v);
extern void func_02159168(int n);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern void func_02159144(int n);
extern void *func_0215A5EC(void *);
extern unsigned char *func_0215A63C(unsigned char *p);
extern void *func_0216DE94(void *map, u32 id);
extern u16 func_0216D5F8(void *p);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern u8 func_0215A66C(u8 *p);
extern void func_021B0960(V3 *, V3 *, int, int, int);
void func_021B0AB0(u32 a);
void func_021B0ADC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_021B0B08(void *a, int b);


void func_021B0AB0(u32 a)
{
    u32 id = 2;

    if (func_02159190(id)) {
        func_0219131C(func_0215A61C(a));
        func_0215A614((u8 *)a, 0);
        func_02159168(id);
    }
}


void func_021B0ADC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    func_0215A614((u8 *)a, (u32)func_0219129C((u8 *)b, c, d, e, f, g));
    func_02159144(2);
}


void func_021B0B08(void *a, int b)
{
    void *t = func_0215A5EC(a);
    S *s = (S *)func_0215A63C(a);
    void *o = func_0216DE94(t, s->id);
    V3 v;
    if (o != 0) {
        func_0216D5F8(o);
        func_0216D88C(o, (struct VecFx32 *)&v);
        if (b == 1 || v.x != s->a.x || v.y != s->a.y || v.z != s->a.z) {
            int p, q;
            s->a = v;
            p = (int)func_02188C58(func_0201210C(func_0215A5DC(a)));
            q = func_0218EC2C((void *)p);
            func_021B0960(&s->a, &s->b, q, p, func_0215A66C(a));
        }
        s->sum.x = s->a.x + s->b.x;
        s->sum.y = s->a.y + s->b.y;
        s->sum.z = s->a.z + s->b.z;
    }
}
