/*
 * function: func_021A74C0
 * address:  0x021A74C0
 * packet:   pkt_ov021_021A74C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A75BC  0x021A75BC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A75BC(u32 p, u32 t);

void func_021A74C0(u32 *s, u32 dt)
{
    u32 i;
    s[3] += dt;
    if (s[2] != 0) {
        for (i = 0; i < s[1]; i++)
            s[3] = func_021A75BC(s[0] + i * 12, s[3]);
    }
}
