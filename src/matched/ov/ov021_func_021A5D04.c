/*
 * function: func_021A5D04
 * address:  0x021A5D04
 * packet:   pkt_ov021_021A5D04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Same body as ov021_func_021A60DC with func_021A5CA4 as the e == 9 path.
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A5CA4  0x021A5CA4  thumb  ov021
 *   func_021A5B6C  0x021A5B6C  thumb  ov021
 *   func_0219E664  0x0219E664  thumb  ov021
 *   func_0219D724  0x0219D724  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB158  0x021AB158  thumb  ov021
 *   func_021AB164  0x021AB164  thumb  ov021
 *   func_021AB170  0x021AB170  thumb  ov021
 *   func_021AB17C  0x021AB17C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D3CC(int a0);
extern int func_021A5CA4(void *a, void *b, int c, int d, int e, int f);
extern int func_021A5B6C(u32 a, u32 b, u32 c, u32 d);
extern int func_0219E664(void *o, u32 k, void *buf);
extern int func_0219D724(u32 a, u32 b);
extern u16 func_021AB0F0(u32);
extern u16 func_021AB0F8(u32 attr);
extern int func_021AB158(u16);
extern int func_021AB164(u16);
extern int func_021AB170(u16);
extern int func_021AB17C(u16);

int func_021A5D04(void *a, void *b, int c, int d, int e, int f)
{
    u8 buf[8];
    u32 r;
    u32 t;
    u16 k;
    int cls;

    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A5CA4(a, b, c, d, e, f);
    }
    r = func_021A5B6C((u32)a, (u32)b, e, 0);
    if (f == 1 && (r & 2)) {
        r = 0;
    }
    if (r == 0) {
        return 2;
    }
    if (r & 2) {
        func_0219E664(b, e, buf);
        t = func_0219D724((u32)b, (u32)buf);
        cls = 9;
        k = func_021AB0F0(t);
        func_021AB0F8(t);
        if (func_021AB158(k)) {
            cls = 0;
        } else if (func_021AB164(k)) {
            cls = 1;
        } else if (func_021AB170(k)) {
            cls = 2;
        } else if (func_021AB17C(k)) {
            cls = 3;
        }
        if (cls != 9 && cls == e) {
            return 5;
        }
    }
    return 4;
}
