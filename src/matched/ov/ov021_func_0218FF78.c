/*
 * function: func_0218FF78
 * address:  0x0218FF78
 * packet:   pkt_ov021_0218FF78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021901E8  0x021901E8  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218F1B4  0x0218F1B4  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_02189A18  0x02189A18  thumb  ov021
 *   func_021AB75C  0x021AB75C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *func_021901E8(u32 *p);
extern u32 func_02188CFC(u32 a);
extern u32 func_02188C5C(u32 a);
extern void func_021BB260(u32 a, u32 b);
extern u32 func_0218EC5C(u32 a);
extern void func_0218EC54(u32 a);
extern u32 func_0218F1B4(u32 a);
extern void func_0218F1AC(u32 a, u32 b);
extern u32 func_02189A18(u32 a);
extern void func_021AB75C(u32 a, u32 b);

void func_0218FF78(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];
    u8 *r = func_021901E8(p);
    if (func_02188CFC(a) == 1)
        func_021BB260(func_02188C5C(a), 0);
    if (*(u32 *)(r + 0x44) != 0) {
        if (func_0218EC5C(p[1]) != 0) {
            p[7] = 1;
            p[6] = func_0218EC5C(b);
            func_0218EC54(b);
        }
    }
    if (*(u32 *)(r + 0x48) != 0) {
        p[5] = func_0218F1B4(b);
        func_0218F1AC(b, 0);
    }
    func_021AB75C(func_02189A18(a), 0);
    p[3] = 1;
}
