/*
 * function: func_021C8F2C
 * address: 0x021C8F2C
 * packet: pkt_ov114_021C8F2C
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D4084 0x021D4084 data a4
 *   d_021D3EFC 0x021D3EFC data a4
 */
extern unsigned d_021D4084[];
extern unsigned d_021D3EFC;
void func_021C8F2C(unsigned a, unsigned b, unsigned c, unsigned mode)
{
    d_021D4084[0] = 1;
    d_021D4084[1] = 0;
    d_021D4084[2] = a;
    d_021D4084[3] = b;
    d_021D4084[4] = c;
    switch (mode) {
    case 0: d_021D3EFC = 0; break;
    case 1: d_021D3EFC = 1; break;
    case 2: d_021D3EFC = 2; break;
    default: d_021D3EFC = 1; break;
    }
}
