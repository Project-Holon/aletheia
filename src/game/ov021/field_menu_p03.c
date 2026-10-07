/*
 * file:     field_menu_p03.c
 * unit:     yes
 * function: func_021A8140, func_021A8198
 * address:  0x021A8140
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3484  0x021A3484  thumb  ov021
 *   func_0207CEE4  0x0207CEE4  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021A36C8  0x021A36C8  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 */
struct Obj00020;
struct VecFx32;
typedef struct V {
    int x;
    int y;
    int z;
} V;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned int   u32;

extern void *func_02188CB4(struct Obj00020 *p);
extern u16 func_021A3050(u8 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3484(unsigned char **a, int b, s32 *c);
extern void func_0207CEE4(int a, V *b, V *c, V *d);
extern void *func_021A3074(u8 *p);
extern void func_02163E58(void *p, V *in, int *out);
extern u32 func_02188C5C(u8 *p);
extern void *func_021BB480(void *p);
extern int func_021A36C8(u8 *p, u32 k, void *buf);
extern void func_021B7D38(void *p, int *in, V *out);
void func_021A8140(void *a, V *out);
void func_021A8198(void *a, V *out);


void func_021A8140(void *a, V *out)
{
    void *ctx;
    int k;
    V v0;
    V v1;
    V v2;
    int t;

    ctx = func_02188CB4(a);
    k = func_021A3050(ctx);
    func_021A3038(ctx, (struct VecFx32 *)&v0);
    func_021A3484(ctx, k, (s32 *)(&v1));
    func_0207CEE4(0x10000, &v1, &v0, &v2);
    func_02163E58(func_021A3074(ctx), &v2, &t);
    v2.y = t;
    *out = v2;
}


void func_021A8198(void *a, V *out)
{
    void *ctx;
    int k;
    void *h;
    V res;
    int in[2];

    ctx = func_02188CB4(a);
    k = func_021A3050(ctx);
    h = func_021BB480((void *)func_02188C5C(a));
    func_021A36C8(ctx, k, in);
    func_021B7D38(h, in, &res);
    *out = res;
}
