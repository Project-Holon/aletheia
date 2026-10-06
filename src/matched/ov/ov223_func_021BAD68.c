/*
 * function: func_021BAD68
 * address:  0x021BAD68
 * packet:   pkt_021BAD68
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02041570  0x02041570  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
extern void func_02041570(int channel, u16 val);

void func_021BAD68(char *a0)
{
    func_02041570(2, 0xd000);
    func_02041570(6, 0);
}
