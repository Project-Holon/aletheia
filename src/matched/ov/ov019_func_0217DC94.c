/*
 * function: func_0217DC94
 * address:  0x0217DC94
 * packet:   pkt_ov019_0217DC94
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02173614  0x02173614  thumb  ov012
 */

typedef unsigned char u8;

extern void func_02173614(u8 *self, const u8 *mac);

void func_0217DC94(u8 *base, int obj, int x)
{
    func_02173614(base + 0x2844, (const u8 *)x);
}
