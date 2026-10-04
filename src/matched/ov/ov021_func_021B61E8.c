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

extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A0E8(void *t, u16 *o1, u16 *o2, u8 c, u32 v);
extern void func_0215897C(void *s, void *v);
extern int func_021B6048(u32 a, u32 b, u32 key, u8 *mask, u32 flag);

int func_021B61E8(u32 a, u32 b)
{
    u32 mode;
    u16 *o1;
    u16 *o2;
    void *s;
    void *t;
    u32 v;
    u8 c;

    mode = func_02159B10((void *)a, (void *)b);
    o1 = func_02159AE8((void *)a, (void *)b);
    o2 = func_02159AE8((void *)a, (void *)b);
    s = func_0215A5F4((void *)b);
    t = func_0215A5DC((void *)b);
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
