/*
 * function: C_GEAR_ResetTabTimerCount
 * address: 0x021F0CF0
 * packet: pkt_ov029_021F0CF0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
void C_GEAR_ResetTabTimerCount(unsigned char *p, int i)
{
    if (p[8] != 0) ((unsigned short *)p)[i] = 0;
}
