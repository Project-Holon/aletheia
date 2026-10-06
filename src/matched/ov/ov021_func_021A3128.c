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

extern u32 func_02188CFC(u8 *p);
extern u32 func_02188C98(u8 *p);
extern u32 func_02188C5C(u8 *p);
extern void func_021A3364(u32 *a, int b, int *out);
extern void *func_021A3074(unsigned char *p);
extern int func_021AB0D4(void *a, void *b);
extern int func_0219E664(void *o, u32 k, void *buf);
extern u32 func_021BB3C4(u8 *p, char *a1);

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
