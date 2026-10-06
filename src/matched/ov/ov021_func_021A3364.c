/*
 * function: func_021A3364
 * address:  0x021A3364
 * packet:   pkt_ov021_021A3364
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A330C  0x021A330C  thumb  ov021
 *   func_02164280  0x02164280  thumb  ov010
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_021A3960(unsigned char *p);
extern u32 func_02188CFC(u8 *p);
extern void func_021A330C(unsigned char **a, u32 b, s16 *c, s16 *d, s16 *e);
extern void func_02164280(int x, int y, int *p);
extern u32 func_02188C5C(u8 *p);
extern void *func_021BB480(void *p);
extern void func_0219E2F4(void *o, void *out);
extern void func_021B7D38(u32, s16 *, int *);
extern void func_0219E784(u32 o, u32 idx, s16 *v);
extern int func_021B7C38(u8 *o);

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
