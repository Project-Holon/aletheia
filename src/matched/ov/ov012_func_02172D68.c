/*
 * function: UNION_COMM_IsResetting
 * address:  0x02172D68
 * packet:   pkt_ov012_02172D68
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

int UNION_COMM_IsResetting(u8 *p)
{
    if (p[0x3561] != 0)
        return 1;
    return 0;
}
