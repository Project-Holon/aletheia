/*
 * function: ov021_func_021A4B54
 * address:  0x021A4B54
 * packet:   pkt_ov021_021A4B54
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
 *   func_021A4B98  0x021A4B98  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_0216D5F8(u32);
extern int func_0216D3CC(u32);
extern int func_021A4B98(u32, u32, u32);

int ov021_func_021A4B54(u32 a, u32 b, u8 *c)
{
    if (func_0216D3CC(b) == 1) {
        if (*(u16 *)(c + 8) != 9) {
            u32 r = func_0216D5F8(b);
            if (*(u16 *)(c + 8) != r && *(u32 *)(c + 16) == 0) {
                return 3;
            }
            return func_021A4B98(a, b, (u32)c);
        }
        return 1;
    }
    return 0;
}
