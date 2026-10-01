/*
 * function: func_021B0A40
 * address:  0x021B0A40
 * packet:   pkt_ov021_021B0A40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct T { int a; int b; int c; } T;
typedef struct Q { int f0; int f4; int f8; } Q;

extern void func_0216D88C(u32 a, T *t);

int func_021B0A40(u32 a, Q *q)
{
    T t;
    int r = 2;

    func_0216D88C(a, &t);
    if (q->f8 < t.c)
        r = 1;
    return r;
}
