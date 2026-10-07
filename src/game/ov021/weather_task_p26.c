/*
 * file:     weather_task_p26.c
 * unit:     yes
 * function: func_021A30C8, func_021A3128
 * address:  0x021A30C8
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
 *   func_02188C5C  0x02188C5C  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021BB3C4  0x021BB3C4  thumb
 *   func_021A3364  0x021A3364  thumb
 *   func_0219E664  0x0219E664  thumb
 */
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;

typedef struct { s32 a, b; } Pair;

extern u32 func_02188CFC(u8 *p);
extern u16 func_02188C98(void *p);
extern void func_021A3038(unsigned char *ctx, struct VecFx32 *out);
extern int func_021AB0D4(void *a, void *b);
extern void *func_021A3074(u8 *p);
extern u32 func_02188C5C(u8 *p);
extern void func_0219E2F4(void *o, void *out);
extern u32 func_021BB3C4(u8 *p, char *a1);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_0219E664(void *o, u32 k, void *buf);
u32 func_021A30C8(void **ctx);
u32 func_021A3128(u32 *a, u32 b);


/*
 * Addresses are Black-image addresses.
 */
u32 func_021A30C8(void **ctx)
{
    u32 r;

    if (func_02188CFC(ctx[0]) == 0) {
        VecFx32 pos;
        u16 z = func_02188C98(ctx[0]);
        func_021A3038((unsigned char *)ctx, (struct VecFx32 *)&pos);
        r = func_021AB0D4((void *)z, &pos);
    } else if (func_02188CFC(ctx[0]) == 1) {
        Pair v;
        void *o = func_021A3074((u8 *)ctx);
        void *w = (void *)func_02188C5C(ctx[0]);
        func_0219E2F4(o, &v);
        r = func_021BB3C4(w, (char *)(&v));
    }
    return r;
}


u32 func_021A3128(u32 *a, u32 b)
{
    u32 r;
    u8 d[12];
    u8 c[8];

    if (func_02188CFC((u8 *)a[0]) == 0) {
        u32 h = func_02188C98((u8 *)a[0]);

        func_021A3364(a, b, (int *)d);
        r = func_021AB0D4((void *)h, d);
    } else if (func_02188CFC((u8 *)a[0]) == 1) {
        void *t = func_021A3074((u8 *)a);
        u32 h = func_02188C5C((u8 *)a[0]);

        func_0219E664(t, b, c);
        r = func_021BB3C4((u8 *)h, (char *)c);
    }
    return r;
}
