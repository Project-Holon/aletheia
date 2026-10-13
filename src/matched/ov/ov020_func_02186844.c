/*
 * function: FIELD_WFBC_DATA_LOCAL_GetPositionPair
 * address:  0x02186844
 * packet:   pkt_ov020_02186844
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: address of the i-th two-byte pair of a table.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

u8 *FIELD_WFBC_DATA_LOCAL_GetPositionPair(u8 *t, int i)
{
    return t + i * 2;
}
