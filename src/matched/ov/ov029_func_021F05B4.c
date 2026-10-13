/*
 * function: C_GEAR_IsCallTabActive
 * address: 0x021F05B4
 * packet: pkt_ov029_021F05B4
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
int C_GEAR_IsCallTabActive(unsigned char *p)
{
    if (p[0x464] == 1 && p[0x461] == 1) return 1;
    return 0;
}
