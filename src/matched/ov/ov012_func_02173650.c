/*
 * function: func_02173650
 * address:  0x02173650
 * packet:   pkt_ov012_02173650
 * region:   ov012
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

void func_02173650(int a, u8 *b)
{
    func_02173614((u8 *)a, b + 0x64);
}
