/*
 * function: C_GEAR_IsTabTimerFull
 * address: 0x021F0CDC
 * packet: pkt_ov029_021F0CDC
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
int C_GEAR_IsTabTimerFull(unsigned short *p, int i)
{
    if (p[i] >= p[3]) return 1;
    return 0;
}
