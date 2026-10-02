/*
 * function: func_021E4A84
 * address: 0x021E4A84
 * packet: pkt_ov119_021E4A84
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E82A4 0x021E82A4 data
 */
extern const unsigned char d_021E82A4[];
int func_021E4A84(char *p, int i)
{
    int v = *(int *)(p + 0x800);
    if (v != 0 && v - 1 == d_021E82A4[i]) {
        return 1;
    }
    return 0;
}
