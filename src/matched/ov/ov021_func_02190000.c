/*
 * function: func_02190000
 * address:  0x02190000
 * packet:   pkt_ov021_02190000
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
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_02189A18  0x02189A18  thumb  ov021
 *   func_021AB75C  0x021AB75C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021901E8(u8 *p);
extern u32 func_02188CFC(u8 *p);
extern u32 func_02188C5C(u8 *p);
extern void func_021BB260(u32 a, u32 b);
extern void func_0218EC30(u32 a, u32 b);
extern void func_0218E13C(u8 *a, u32 s);
extern void func_0218F1AC(u32 a, u32 b);
extern u32 func_02189A18(u8 *p);
extern void func_021AB75C(u8 *p, u32 v);

void func_02190000(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];
    u8 *r = (u8 *)func_021901E8((u8 *)p);
    func_021AB75C((u8 *)func_02189A18((u8 *)a), 1);
    if (*(u32 *)(r + 0x48) != 0)
        func_0218F1AC(b, p[5]);
    if (p[7] != 0)
        func_0218EC30(b, p[6]);
    func_0218E13C((u8 *)b, p[4]);
    if (func_02188CFC((u8 *)a) == 1)
        func_021BB260(func_02188C5C((u8 *)a), 1);
}
