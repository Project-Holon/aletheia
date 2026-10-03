/*
 * function: ov021_func_021A4768
 * address:  0x021A4768
 * packet:   pkt_ov021_021A4768
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A47B4  0x021A47B4  thumb  ov021
 *   func_021A482C  0x021A482C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_0216D5F8(u32);
extern int func_0216D3CC(int a0);
extern int func_021A47B4(u32, u32, u32);
extern int func_021A482C(u32, u32, u32);

int ov021_func_021A4768(u32 a, u32 b, u8 *c)
{
    if (func_0216D3CC(b) == 1) {
        if (*(u16 *)(c + 8) != 9) {
            u32 r = func_0216D5F8(b);
            if (*(u16 *)(c + 8) != r && *(u32 *)(c + 16) == 0) {
                return 3;
            }
            return func_021A47B4(a, b, (u32)c);
        }
        return func_021A482C(a, b, (u32)c);
    }
    return 0;
}
