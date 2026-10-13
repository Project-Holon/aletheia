/*
 * function: FIELD_WFBC_DATA_LOCAL_AddValuePoints
 * address:  0x021869BC
 * packet:   pkt_ov020_021869BC
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned short u16;

void FIELD_WFBC_DATA_LOCAL_AddValuePoints(u16 *p)
{
    if (p[1] < 0x2710)
        p[1] += 10;
}
