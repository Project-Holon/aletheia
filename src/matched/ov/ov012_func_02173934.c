/*
 * function: UNION_MAIN_SetAppealNo
 * address:  0x02173934
 * packet:   pkt_ov012_02173934
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save) in the ov012 listing: stores the byte at
 * +0x2832. Callee of ov031 UNION_SUBDISP_Update (a blocker of its MATCH).
 */

typedef unsigned char u8;

void UNION_MAIN_SetAppealNo(u8 *p, int v)
{
    p[0x2832] = v;
}
