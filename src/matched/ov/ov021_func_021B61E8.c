/*
 * function: func_021B61E8
 * address:  0x021B61E8
 * packet:   pkt_ov021_021B61E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A0E8  0x0215A0E8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021B6048  0x021B6048  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(u32 a, u32 b);
extern void *func_0215A5F4(u32 a);
extern void *func_0215A5DC(u32 a);
extern void *func_0215A0E8(void *t, u16 *o1, u16 *o2, u8 c, u32 v);
extern void func_0215897C(void *s, void *v);
extern int func_021B6048(u32 a, u32 b, u32 mode, u8 *out, int z);

int func_021B61E8(u32 a, u32 b)
{
    u32 mode;
    u16 *o1;
    u16 *o2;
    void *s;
    void *t;
    u32 v;
    u8 c;

    mode = func_02159B10(a, b);
    o1 = func_02159AE8(a, b);
    o2 = func_02159AE8(a, b);
    s = func_0215A5F4(b);
    t = func_0215A5DC(b);
    if (func_021B6048(a, b, mode, &c, 0)) {
        *o1 = 0;
    } else {
        switch (mode) {
        case 1:
            v = 0xfffe;
            break;
        case 2:
            v = 0xfffd;
            break;
        case 0:
            v = 0x1b2;
            break;
        default:
            v = 0xa5;
            break;
        }
        func_0215897C(s, func_0215A0E8(t, o1, o2, c, v));
    }
    return 1;
}
