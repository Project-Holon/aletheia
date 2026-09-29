/*
 * function: func_02183D4C
 * address:  0x02183D4C
 * packet:   pkt_ov022_02183D4C
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D1C0  0x0203D1C0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern int func_0203D1C0(int a);

void func_02183D4C(u8 *s)
{
    int i;
    u8 m;

    if (s[0x10] != 0xff) {
        if (func_0203D1C0(s[0x10]) != 0) {
            return;
        }
        s[0x10] = 0xff;
        s[0x11] = 0xff;
    }
    m = s[0xf];
    if (m != 0) {
        for (i = 0; i < 5; i++) {
            if (m & (1 << i)) {
                s[0x10] = i;
                s[0x11] = i;
                s[0xf] = s[0xf] ^ (u8)(1 << i);
                return;
            }
        }
    }
}
