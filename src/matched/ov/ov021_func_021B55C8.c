/*
 * function: func_021B55C8
 * address:  0x021B55C8
 * packet:   pkt_ov021_021B55C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F818  0x0218F818  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Ctx;

struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C58(void *o);
extern u32 func_0218F0E8(u8 *a);
extern void func_0218F818(u8 *a);

int func_021B55C8(void *a)
{
    u8 *x = func_02188C58(func_0201210C(func_020124E4(a)));

    if (func_0218F0E8(x) == 0) {
        func_0218F818(x);
        return 1;
    }
    return 0;
}
