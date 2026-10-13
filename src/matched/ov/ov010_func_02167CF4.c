/*
 * function: BSUBWAY_COMM_SetRecvMode
 * address:  0x02167CF4
 * packet:   pkt_ov010_02167CF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte setter at +0x725. bl from ov021 BSUBWAY_SCR_CmdTool at 0x021CB596.
 */

typedef unsigned char u8;

void BSUBWAY_COMM_SetRecvMode(u8 *w, u8 v)
{
    w[0x725] = v;
}
