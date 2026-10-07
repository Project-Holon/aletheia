/*
 * file:     unit_0219B508_p04.c
 * unit:     yes
 * function: func_0219BAE0, func_0219BB08
 * address:  0x0219BAE0
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
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0219BC48  0x0219BC48  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   d_021D538C  0x021D538C  data  a4
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int (*Step)(u32, u8 *);

extern u8 *func_0216D684(u32, u32);
extern int func_0219BC48(int a, u8 *b);
extern void func_0216D674(void *p, u16 v);
extern void func_0216DA50(u8 *p);
extern void *func_0216D69C(void *p);
void func_0219BAE0(u32 a);
void func_0219BB08(u32 a);
extern Step d_021D538C[];


void func_0219BAE0(u32 a)
{
    u8 *p = func_0216D684(a, 12);
    func_0219BC48(a, p);
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
    p[1] = 0;
}


void func_0219BB08(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    if (func_0219BC48(a, p)) {
        while (d_021D538C[p[0]](a, p) == 1) {
        }
    }
}
