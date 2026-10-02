/*
 * function: func_021A3250
 * address:  0x021A3250
 * packet:   pkt_ov021_021A3250
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C7C  0x02188C7C  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_021A3460  0x021A3460  thumb
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_021A3960  0x021A3960  thumb
 *   func_0219E634  0x0219E634  thumb
 *   func_0219E570  0x0219E570  thumb
 * Addresses are Black-image addresses.
 * func_0216DDC0 forwards r0-r3 to func_0216DD60, so it takes four
 * arguments; the fourth is the literal 0 whose register the compiler also
 * uses as the v[0] index.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_02188C7C(unsigned char *p);
extern int func_02188CFC();
extern void func_021A3460();
extern void func_0216DDC0(void *, int, int, int);
extern void *func_021A3960(unsigned char *p);
extern void func_0219E634();
extern void func_0219E570();

void func_021A3250(u32 *a)
{
    s16 v[8];
    void *h = func_02188C7C((u8 *)a[0]);

    if (func_02188CFC(a[0]) == 0) {
        func_021A3460(a, &v[2], &v[1], &v[0]);
        func_0216DDC0(h, v[2], v[0], 0);
        return;
    }
    func_0219E634(func_021A3960((u8 *)a[1]), &v[3]);
    func_0219E570(h, &v[3], 0);
}
