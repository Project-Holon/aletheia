/*
 * function: UNION_COMM_RequestRestart
 * address:  0x02172D20
 * packet:   pkt_ov012_02172D20
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov019 UNION_ONESELF_ConnectChildMain.
 */

typedef unsigned char u8;

void UNION_COMM_RequestRestart(u8 *p)
{
    if (p[0x3561] == 0) {
        p[0x3561] = 1;
        p[0x3562] = 0;
    }
}
