/*
 * function: PMSI_PARAM_SetSentence
 * address: 0x02024108
 * packet: pkt_02024108
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;

void PMSI_PARAM_SetSentence(u16 *dst, const u16 *src)
{
    dst[8] = src[0];
    dst[9] = src[1];
    dst[10] = src[2];
    dst[11] = src[3];
}
