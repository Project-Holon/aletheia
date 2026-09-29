/*
 * function: func_02183BE8
 * address:  0x02183BE8
 * packet:   pkt_ov022_02183BE8
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02080D24  0x02080D24  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_02080D24(u32 a);

int func_02183BE8(u8 *s, int i)
{
    u32 n;
    u32 c;

    if (s[9] == 1) {
        return 0;
    }
    n = func_02080D24(s[1]);
    if (s[9] == 2) {
        c = s[0xa];
        if (c + 1 > s[0xb]) {
            return 0;
        }
    }
    if (n + 1 <= s[0]) {
        s[4] = s[4] | (u8)(1 << i);
        if (s[9] == 2) {
            s[0xa] = s[0xa] + 1;
        }
        return 1;
    }
    return 0;
}
