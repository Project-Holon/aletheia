/*
 * function: func_021E496C
 * address: 0x021E496C
 * packet: pkt_ov119_021E496C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
void func_021E496C(int x, int y, unsigned short *out)
{
    out[0] = (x + 1) * 0x18;
    out[1] = y * 0x18 + 0x48;
}
