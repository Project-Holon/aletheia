/*
 * function: func_021B627C
 * address:  0x021B627C
 * packet:   pkt_ov021_021B627C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_02159AE8(u32 a, u32 b);
extern u32 func_0215A5E4(u32 a);
extern u32 func_02012934(u32 a);
extern u32 func_0201AA18(u32 a);
extern u32 func_0201AB28(u32 a, u32 i);
extern u32 func_02017E1C(u32 a, u32 b, u32 c);

int func_021B627C(u32 a, u32 b)
{
    u16 *o;
    u32 lst;
    u32 n;
    u32 i;

    o = func_02159AE8(a, b);
    *o = 0;
    lst = func_02012934(func_0215A5E4(b));
    n = func_0201AA18(lst);
    for (i = 0; i < n; i++) {
        if (func_02017E1C(func_0201AB28(lst, i), 0x97, 0) != 0) {
            *o = 1;
            break;
        }
    }
    return 0;
}
