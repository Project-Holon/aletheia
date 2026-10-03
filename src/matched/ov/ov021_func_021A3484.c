/*
 * function: func_021A3484
 * address:  0x021A3484
 * packet:   pkt_ov021_021A3484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0219E784  0x0219E784  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_021A3960(unsigned char *p);
extern u32 func_02188CFC(u8 *p);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
extern void func_0207CCA4();
extern void func_0219E784();

void func_021A3484(unsigned char **a, u32 b, s32 *c)
{
    s16 v[4];
    s32 t1;
    s32 t2;
    s32 t3;
    void *h = func_021A3960(a[1]);

    if (func_02188CFC(a[0]) == 0) {
        s32 t;

        c[1] = 0;
        c[0] = func_021641E8(b);
        t = func_021641F8(b);
        c[0] = c[0] << 16;
        c[2] = t << 16;
        func_0207CCA4(c, c);
        return;
    }
    func_0219E784(h, b, v);
    t3 = v[2];
    t2 = v[1];
    t1 = v[0];
    c[0] = t1;
    c[1] = t2;
    c[2] = t3;
}
