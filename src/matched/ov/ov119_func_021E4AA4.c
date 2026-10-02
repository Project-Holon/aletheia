/*
 * function: func_021E4AA4
 * address: 0x021E4AA4
 * packet: pkt_ov119_021E4AA4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E82A4 0x021E82A4 data
 */
extern const unsigned char d_021E82A4[];
int func_021E4AA4(int i, int x)
{
    if (x == d_021E82A4[i]) {
        return 1;
    }
    return 0;
}
