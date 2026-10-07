/*
 * file:     fldmmdl_blact_p02.c
 * unit:     yes
 * function: func_0219C780, func_0219C7B4, func_0219C7EC
 * address:  0x0219C780
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
 *   func_0219C6B8  0x0219C6B8  thumb  ov021
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_02050894  0x02050894  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219C74C  0x0219C74C  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } V3;

typedef signed int     s32;

extern u32 func_0219C6B8(u32 a, V3 *b, int c, u32 d, u16 e);
extern u32 func_0216D520(void *p);
extern int func_02050894(void *p, int idx, int j);
extern void *func_0216D67C(void *a0);
extern void *func_0216E3C4(void *p);
extern void func_02197CCC(u8 *p, s32 *out);
extern int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
extern void func_0219C74C(u32 a, u16 e);
u32 func_0219C780(u32 a, V3 *b, int c, u32 d, u16 e, u16 g);
void func_0219C7B4(u32 a, u16 e, u16 g);
void func_0219C7EC(u32 a, u32 b);


u32 func_0219C780(u32 a, V3 *b, int c, u32 d, u16 e, u16 g)
{
    u32 r = func_0219C6B8(a, b, c, d, e);
    if (g != 0xFFFF) {
        func_02050894((void *)(*(u32 *)(func_0216D520((void *)a) + 4)), r, g);
    }
    return r;
}


void func_0219C7B4(u32 a, u16 e, u16 g)
{
    u32 o = (u32)func_0216D67C((void *)a);
    u8 *d = func_0216E3C4((void *)a);
    V3 v;
    func_02197CCC((u8 *)a, (s32 *)(&v));
    func_0219C780(o, &v, d[7], d[9], e, g);
}


void func_0219C7EC(u32 a, u32 b)
{
    u16 t[2];
    func_0219CBD4(func_0216D520(func_0216D67C((void *)a)), b, (u32)(&t[1]), (u32)(&t[0]));
    func_0219C74C(a, t[1]);
}
