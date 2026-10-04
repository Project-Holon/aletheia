/*
 * function: ov021_func_021A482C
 * address:  0x021A482C
 * packet:   pkt_ov021_021A482C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A5390  0x021A5390  thumb  ov021
 *   func_021A56F4  0x021A56F4  thumb  ov021
 *   func_0219F7CC  0x0219F7CC  thumb  ov021
 *   func_021A5708  0x021A5708  thumb  ov021
 *   func_021A53A4  0x021A53A4  thumb  ov021
 *   func_021A47B4  0x021A47B4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_021A5390(u32 a);
extern int func_021A56F4(u8 *);
extern int func_0219F7CC(u32, u32);
extern int func_021A5708(u32 a);
extern void func_021A53A4(u32 *p, int on);
extern int func_021A47B4(u8 *, u32, u8 *);

int ov021_func_021A482C(u8 *a, u32 b, u8 *c)
{
    if (*(u16 *)(c + 8) == 9) {
        if (func_021A5390((u32)a) == 0) {
            func_021A56F4(a);
        }
        if (*(u8 *)(a + 22) == 1) {
            if (func_0219F7CC(b, *(u16 *)(a + 20)) != 0) {
                *(u8 *)(a + 22) = 0;
            }
        }
        *(u16 *)(a + 20) = *(u16 *)(a + 20) + 1;
        if (*(u16 *)(a + 20) == 60) {
            func_021A5708((u32)a);
            func_021A53A4((u32 *)a, 1);
            return 7;
        }
    } else {
        func_021A5708((u32)a);
        return func_021A47B4(a, b, c);
    }
    return 6;
}
