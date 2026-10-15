/*
 * function: STA_ACT_LIGHT_ElemOpE
 * address: 0x021F812C
 * packet: pkt_ov112_021F812C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: parent-coordinated blocker leaf for ov132 021FB258.
 */
int STA_ACT_LIGHT_ElemOpE(int unused, int *p, int flag)
{
    if (p[5] == 1) p[21] = 0;
    else p[21] = flag;
    p[1] = 1;
    return 1;
}
