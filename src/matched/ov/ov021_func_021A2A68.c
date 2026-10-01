/*
 * function: func_021A2A68
 * address:  0x021A2A68
 * packet:   pkt_ov021_021A2A68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A1680  0x021A1680  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void func_021A1680(int x);

void func_021A2A68(u8 *p, int i, int x)
{
    u32 *s = (u32 *)(p + 8);

    if (s[i] != 0) {
        func_021A1680(x);
        s[i] = 0;
    }
}
