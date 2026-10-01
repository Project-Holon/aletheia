/*
 * function: func_02197EB4
 * address:  0x02197EB4
 * packet:   pkt_ov021_02197EB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_0216D7D4  0x0216D7D4  thumb  ov010
 *   func_02197F20  0x02197F20  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_0216D7C4(u32);
extern u32 func_0216D7D4(u32);
extern int func_02197F20(u32, u32, u32);

void func_02197EB4(u32 a)
{
    u32 r;

    do {
        r = func_0216D7C4(a);
        if (r == 0xFF) {
            return;
        }
    } while (func_02197F20(a, r, func_0216D7D4(a)) != 0);
}
