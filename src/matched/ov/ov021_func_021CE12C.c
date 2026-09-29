/*
 * function: func_021CE12C
 * address:  0x021CE12C
 * packet:   pkt_ov021_021CE12C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CF220  0x021CF220  thumb  ov021
 *   func_021CF288  0x021CF288  thumb  ov021
 *   func_021CE1F4  0x021CE1F4  thumb  ov021
 *   func_021CF3FC  0x021CF3FC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 func_021CF220(u32 a, u32 flag, u32 c);
extern u32 func_021CF288(u32 a, u32 flag, u32 c);
extern u8 func_021CE1F4(u8 *p);
extern u32 func_021CF3FC(u32 a, u32 b, int c);

void func_021CE12C(u8 *p)
{
    u8 i;
    int bit;
    u8 n;

    for (i = 0; i < 4; i++) {
        bit = 1 << i;
        if (p[0x521] & bit) {
            if (func_021CF220(i, p[0x51B], (u32)(p + 0x30)) == 1)
                p[0x521] ^= (u8)bit;
        } else if (p[0x522] & bit) {
            if (func_021CF288(i, p[0x51B], (u32)(p + 0x30)) == 1)
                p[0x522] ^= (u8)bit;
        }
    }
    if (p[0x523] == 1 && p[0x525] == 0) {
        n = func_021CE1F4(p);
        if (n > 1) {
            if (func_021CF3FC((u32)(p + 0x494), n, p[0x51B]) == 1) {
                p[0x523] = 0;
                p[0x525] = 1;
            }
        }
    }
}
