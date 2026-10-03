/*
 * function: func_021B52FC
 * address:  0x021B52FC
 * packet:   pkt_ov021_021B52FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159144  0x02159144  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F818  0x0218F818  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_021B55C8  0x021B55C8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
struct Desc;
extern void func_0215897C(void *vm, void *task);
extern void func_02159144(int n);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_02188C58(void *a);
extern u32 func_02188C5C(u8 *p);
extern u32 func_02188CFC(u8 *p);
extern int func_0218F0F8(u8 *a);
extern void func_0218F0A8(u8 *a);
extern void func_0218F818(u8 *a);
extern void func_021BB260(u32 a, u32 b);
extern int func_021B55C8(void *a);

int func_021B52FC(u32 a, u32 b)
{
    void *r6;
    void *r4;
    void *r5;

    r6 = func_0215A5DC((void *)b);
    r4 = func_0201210C((void *)r6);
    r5 = func_02188C58(r4);
    func_02159144(0);
    if (func_0218F0F8(r5) != 0) {
        func_0218F0A8(r5);
        r5 = func_0215A5F4((void *)b);
        func_0215897C(r5, func_020122C0(r6, 0, (void *)func_021B55C8, 0));
        if (func_02188CFC(r4) == 1) {
            func_021BB260(func_02188C5C(r4), 0);
        }
    } else {
        func_0218F818(r5);
    }
    return 1;
}
