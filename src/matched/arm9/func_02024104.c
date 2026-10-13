/*
 * function: PMSI_PARAM_SetWord
 * address: 0x02024104
 * packet: pkt_02024104
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;

void PMSI_PARAM_SetWord(u16 *p, u16 v)
{
    p[0xC] = v;
}
