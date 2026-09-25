/*
 * unit:     yes
 * function: func_021C4524, func_021C4530
 * address:  0x021C4524
 * packet:   pkt_021C4524
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two ternaries selecting between two constants.
 */

int func_021C4524(int x)
{
    return x == 0x14 ? 0x20 : 0x1C;
}

int func_021C4530(int x)
{
    return x == 0x14 ? 0x2A : 0x29;
}
