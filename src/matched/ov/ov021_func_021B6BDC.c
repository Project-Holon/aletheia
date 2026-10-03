/*
 * function: func_021B6BDC
 * address:  0x021B6BDC
 * packet:   pkt_ov021_021B6BDC
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
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200A300  0x0200A300  thumb
 *   func_0200A338  0x0200A338  thumb
 *   func_021B7834  0x021B7834  thumb  ov021
 *   func_021B7864  0x021B7864  thumb  ov021
 *   func_021B785C  0x021B785C  thumb  ov021
 *   func_021B6D0C  0x021B6D0C  thumb  ov021
 *   func_021B6D30  0x021B6D30  thumb  ov021
 *   func_021B6D64  0x021B6D64  thumb  ov021
 *   func_021B6D98  0x021B6D98  thumb  ov021
 *   func_021B6DC0  0x021B6DC0  thumb  ov021
 *   func_021B6DE4  0x021B6DE4  thumb  ov021
 *   func_021B6E0C  0x021B6E0C  thumb  ov021
 *   func_021B6EB0  0x021B6EB0  thumb  ov021
 *   func_02012F08  0x02012F08  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0216BF74  0x0216BF74  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   d_021D9970     0x021D9970  data   ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Ent {
    int id;
    u32 f4[5];
} Ent;

extern int func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern u32 func_0215A5CC(u32 a);
extern void *func_0215A5DC(void *a0);
extern u32 func_02012EBC(void *a);
extern void *func_0200A300(u32 a, u32 b, u32 c);
extern void func_0200A338(void *h);
extern u8 *func_021B7834(void *h, u32 *x, u8 *buf);
struct Ctx;
extern u8 func_021B7864(void *a);
extern void func_021B785C(u8 *p, u32 i);
extern u16 func_021B6D0C(int k, u32 b, void *sv, u8 *p);
extern u16 func_021B6D30(int k, u8 *p, u32 b);
extern u16 func_021B6D64(int k, u8 *p, u32 b);
extern int func_021B6D98(int k, u32 b, void *sv, u8 *p);
extern u16 func_021B6DC0(int k, u32 b, void *sv, u8 *p);
extern u16 func_021B6DE4(void *a, void *sv);
extern u16 func_021B6E0C(void *a);
extern int func_021B6EB0(u8 *p, int k);
extern u32 func_02012F08(void *sv);
extern u32 func_02012944(void *sv);
extern void func_0216BF74(u32 a, u32 b, u32 c);
extern void *func_0201210C(const struct Ctx *p);
extern Ent d_021D9970[];

int func_021B6BDC(u32 a, u32 b)
{
    int mode;
    u16 *out;
    void *sv;
    void *h;
    u32 heap;
    u8 *p;
    int k;
    u8 buf[0xcc];
    u32 x;

    mode = func_02159B10(a, b);
    out = func_02159AE8((void *)a, (void *)b);
    sv = func_0215A5E4((void *)b);
    heap = func_0215A5CC(b);
    h = func_0200A300(func_02012EBC(sv), 0, heap);
    p = func_021B7834(h, &x, buf);
    k = func_021B7864(h);
    if (k != d_021D9970[k].id) {
        func_0200A338(h);
        return 0;
    }
    switch (mode) {
    case 0:
        if (k != 0) {
            *out = 1;
        } else {
            *out = 0;
        }
        break;
    case 1:
        *out = func_021B6D0C(k, b, sv, p);
        break;
    case 2:
        *out = func_021B6D30(k, p, b);
        break;
    case 3:
        *out = func_021B6D64(k, p, b);
        break;
    case 4:
        if (func_021B6D98(k, b, sv, p) == 1) {
            func_021B785C(h, x);
            if (func_021B6EB0(p, k) == 1) {
                func_0216BF74(func_02012F08(sv), 1, func_02012944(sv));
            }
        }
        *out = 0;
        break;
    case 5:
        *out = func_021B6DE4(func_0201210C(func_0215A5DC((void *)b)), sv);
        break;
    case 6:
        *out = func_021B6E0C(func_0201210C(func_0215A5DC((void *)b)));
        break;
    case 7:
        *out = func_021B6DC0(k, b, sv, p);
        break;
    }
    func_0200A338(h);
    return 0;
}
