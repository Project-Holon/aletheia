/*
 * function: func_021AE754
 * address:  0x021AE754
 * packet:   pkt_ov021_021AE754
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AE72C  0x021AE72C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_021AE72C(u32 a);
extern void func_020307B0(u32 a);

int func_021AE754(u32 a, u32 b, u32 *c)
{
    if (c[0] != 0) {
        if (func_021AE72C(c[0]) == 1) {
            func_020307B0(c[0]);
            c[0] = 0;
        }
    }
    if (c[1] != 0) {
        if (func_021AE72C(c[1]) == 1) {
            func_020307B0(c[1]);
            c[1] = 0;
        }
    }
    if (c[0] == 0 && c[1] == 0) {
        return 1;
    }
    return 0;
}
