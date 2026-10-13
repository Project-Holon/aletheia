/*
 * function: C_GEAR_LoadTargetPalette
 * address: 0x021F09B4
 * packet: pkt_ov029_021F09B4
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
void C_GEAR_LoadTargetPalette(unsigned char *p, unsigned char *q, int n)
{
    int i;
    for (i = 0; i < 5; i++) *(unsigned short *)(p + n * 10 + i * 2 + 0x272) = *(unsigned short *)(q + n * 32 + i * 2 + 0x16);
}
