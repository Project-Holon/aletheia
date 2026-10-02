/*
 * function: func_021A3128
 * address:  0x021A3128
 * packet:   pkt_ov021_021A3128
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CFC  0x02188CFC  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_02188C5C  0x02188C5C  thumb
 *   func_021A3364  0x021A3364  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_0219E664  0x0219E664  thumb
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_02188CFC();
extern u32 func_02188C98();
extern u32 func_02188C5C();
extern void func_021A3364();
extern void *func_021A3074(unsigned char *p);
extern u32 func_021AB0D4();
extern void func_0219E664();
extern u32 func_021BB3C4();

u32 func_021A3128(u32 *a, u32 b)
{
    u32 r;
    u8 d[12];
    u8 c[8];

    if (func_02188CFC(a[0]) == 0) {
        u32 h = func_02188C98(a[0]);

        func_021A3364(a, b, d);
        r = func_021AB0D4(h, d);
    } else if (func_02188CFC(a[0]) == 1) {
        void *t = func_021A3074(a);
        u32 h = func_02188C5C(a[0]);

        func_0219E664(t, b, c);
        r = func_021BB3C4(h, c);
    }
    return r;
}
