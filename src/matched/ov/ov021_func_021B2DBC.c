/*
 * function: func_021B2DBC
 * address:  0x021B2DBC
 * packet:   pkt_ov021_021B2DBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021B2BD8  0x021B2BD8  thumb  ov021
 *   func_0218BA98  0x0218BA98  thumb  ov021
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_0218C990  0x0218C990  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */

extern unsigned int func_02159B10(void *, void *);
typedef unsigned int   u32;
extern int func_021B2BD8(u32 a);
extern int func_0218BA98(int a, int b);
extern void func_0218C88C(int a, int b, int c);
extern int func_0218C990(int a, unsigned short *b);
extern void func_020061E4(u32 a);

int func_021B2DBC(int a, int b)
{
    unsigned short v;
    int p = func_02159B10((void *)a, (void *)b);
    int q = func_02159B10((void *)a, (void *)b);
    int h = func_0218BA98(func_021B2BD8(b), p);

    if (h) {
        func_0218C88C(h, q, 0);
        if (func_0218C990(h, &v)) {
            func_020061E4(v);
        }
    }
    return 0;
}
