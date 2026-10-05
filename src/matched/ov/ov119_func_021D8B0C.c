/*
 * function: func_021D8B0C
 * address: 0x021D8B0C
 * packet: pkt_ov119_021D8B0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0209C0A4 0x0209C0A4 arm
 */
int func_021D8B0C(int a, int b)
{
    if (a >= 2) {
        return (a - 2) % 6 + b * 6;
    }
    if (b < 3)
        return a + b * 2;
    return -1;
}
