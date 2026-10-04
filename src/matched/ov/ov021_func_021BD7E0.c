/*
 * function: func_021BD7E0
 * address:  0x021BD7E0
 * packet:   pkt_ov021_021BD7E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021A7E3C  0x021A7E3C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Args;
struct Evt;
extern void *func_02188C58(void *p);
extern int func_0218F0F8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_0218F0A8(u8 *a);
extern void func_0218EC54(u8 *p);
extern void *func_021A7E3C(struct Args *a);
extern void func_02012374(struct Evt *evt, struct Evt **out);

u32 func_021BD7E0(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 h = (u32)func_02188C58((void *)(*(u32 *)(p + 0xc)));

    switch (*st) {
    case 0:
        if (func_0218F0F8((u8 *)h) && func_0218F0E8((u8 *)h)) {
            func_0218F0A8((u8 *)h);
            *st = 1;
        } else {
            *st = 2;
        }
        return 0x21;
    case 1:
        if (!func_0218F0F8((u8 *)h)) {
            *st = 2;
            return 0x21;
        }
        if (func_0218F0E8((u8 *)h))
            break;
        func_0218EC54((u8 *)h);
        *st = 2;
        return 0x21;
    case 2:
        func_02012374((struct Evt *)a, func_021A7E3C((struct Args *)((u32)p)));
        *st = 3;
        return 0x21;
    case 3:
        return 1;
    }
    return 0;
}
