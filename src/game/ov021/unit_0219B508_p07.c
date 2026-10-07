/*
 * file:     unit_0219B508_p07.c
 * unit:     yes
 * function: func_0219BE3C, func_0219BE60, func_0219BE70
 * address:  0x0219BE3C
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
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   d_021D537C  0x021D537C  data  a4
 *   func_0219BF48  0x0219BF48  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   d_021D5480     0x021D5480  data   ov021  a4
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int (*Step)(u32, u8 *);

typedef struct { u32 a, b, c; } T12;

extern void *func_0216D69C(void *p);
extern int func_0219BF48(u32 a);
extern void func_021AC154(u32);
extern void func_0219BF3C(int a, u32 v);
extern void func_0216D8C0(u32, void *);
extern void *func_0216D568(void *p, u32 v);
void func_0219BE3C(u32 a);
void func_0219BE60(u32 a);
void func_0219BE70(u32 a);
extern Step d_021D537C[];
extern T12 d_021D5480;


void func_0219BE3C(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D537C[p[0]](a, p) == 1) {
    }
}


void func_0219BE60(u32 a)
{
    u32 r = func_0219BF48(a);
    if (r != 0) {
        func_021AC154(r);
    }
}


void func_0219BE70(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    T12 t;
    p[0] = 0;
    func_0219BF3C(a, 0);
    if (p[2] == 0) {
        t = d_021D5480;
        func_0216D8C0(a, &t);
        func_0216D568((void *)a, 2 << 14);
    }
}
