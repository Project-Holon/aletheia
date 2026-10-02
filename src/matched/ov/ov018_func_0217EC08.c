/*
 * function: func_0217EC08
 * address: 0x0217EC08
 * packet: pkt_ov018_0217EC08
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: integer t initialized to 0x126 and incremented conditionally retains
 * the u16 assignment's shift pair; assigning either u16 constant removes it.
 */
typedef unsigned short u16;
int func_0217EC08(u16 a, u16 b, u16 c)
{
    int t;
    if (a == b || a == c) return 1;
    if ((u16)(a + 0xfeda) <= 1) {
        t = 0x126;
        if (a == t) t++;
        a = t;
        if (a == b || a == c) return 1;
    }
    return 0;
}
