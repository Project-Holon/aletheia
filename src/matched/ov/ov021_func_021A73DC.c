/*
 * function: func_021A73DC
 * address:  0x021A73DC
 * packet:   pkt_ov021_021A73DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A74C0  0x021A74C0  thumb
 *   func_021A7654  0x021A7654  thumb
 */

typedef unsigned int u32;

extern void func_021A74C0(u32 *p, u32 v);
extern void func_021A7654(u32 *p, u32 v);

void func_021A73DC(u32 *s)
{
    u32 v;
    if (s[0] != 0) {
        v = s[1];
    } else {
        v = 0;
    }
    func_021A74C0(s + 2, v);
    func_021A7654(s + 6, v);
}
