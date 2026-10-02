/*
 * function: func_021F2DA8
 * address: 0x021F2DA8
 * packet: pkt_ov029_021F2DA8
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
int func_021F2DA8(u8 *p)
{
    if (p[0x45c] != 0)
        return 1;
    if (p[0x45d] != 0)
        return 1;
    return 0;
}
