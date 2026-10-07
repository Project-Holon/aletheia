/*
 * file:     weather_task_p29.c
 * unit:     yes
 * function: func_021A32A8, func_021A330C, func_021A3364
 * address:  0x021A32A8
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
 *   func_02188C7C  0x02188C7C  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_021A3460  0x021A3460  thumb
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_021A3960  0x021A3960  thumb
 *   func_0219E634  0x0219E634  thumb
 *   func_0219E570  0x0219E570  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

extern void *func_02188C7C(unsigned char *p);
extern u32 func_02188CFC(u8 *p);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern void *func_021A3960(unsigned char *p);
extern void func_0219E634();
extern u32 func_0219E570(u32 o, u32 k, u32 flag);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D83C(void *p);
extern int func_0216D854(void *p);
extern int func_0216D86C(void *p);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
extern void func_02164280(int x, int y, int *p);
extern u32 func_02188C5C(u8 *p);
extern void *func_021BB480(void *p);
extern void func_0219E2F4(void *o, void *out);
extern void func_021B7D38(u32, s16 *, int *);
extern void func_0219E784(u32 o, u32 idx, s16 *v);
extern int func_021B7C38(u8 *o);
void func_021A32A8(unsigned char **a, u32 b);
void func_021A330C(unsigned char **a, u32 b, s16 *c, s16 *d, s16 *e);
void func_021A3364(u32 *a, int b, int *out);


/*
 * Addresses are Black-image addresses.
 */
void func_021A32A8(unsigned char **a, u32 b)
{
    s16 v[8];
    void *h = func_02188C7C(a[0]);

    if (func_02188CFC(a[0]) == 0) {
        func_021A3460((u32)a, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
        func_0216DDDC((u32)h, v[2], v[0], v[1] << 16, b, 0);
        return;
    }
    func_0219E634(func_021A3960(a[1]), &v[3]);
    func_0219E570((u32)h, (u32)(&v[3]), 0);
}


void func_021A330C(unsigned char **a, u32 b, s16 *c, s16 *d, s16 *e)
{
    void *t = func_021A3074((unsigned char *)a);

    if (func_02188CFC(a[0]) == 0) {
        *c = func_0216D83C(t);
        *d = func_0216D854(t);
        *e = func_0216D86C(t);
        *c = *c + func_021641E8(b);
        *e = *e + func_021641F8(b);
    }
}


void func_021A3364(u32 *a, int b, int *out)
{
    int v[3];
    s16 d[3];
    s16 r[4];
    s16 z;
    s16 y;
    s16 x;
    void *e;
    u32 h;
    int m;

    e = func_021A3960((void *)a[1]);
    if (func_02188CFC((u8 *)a[0]) == 0) {
        func_021A330C((unsigned char **)a, b, &z, &y, &x);
        func_02164280(z, x, out);
        out[1] = y << 16;
        return;
    }
    h = (u32)func_021BB480((void *)func_02188C5C((u8 *)a[0]));
    func_0219E2F4(e, r);
    func_021B7D38(h, r, v);
    func_0219E784((u32)e, b, d);
    m = func_021B7C38((u8 *)h);
    out[0] = v[0] + (int)(((long long)d[0] * m + 0x800) >> 12);
    out[1] = v[1] + (int)(((long long)d[1] * m + 0x800) >> 12);
    out[2] = v[2] + (int)(((long long)d[2] * m + 0x800) >> 12);
}
