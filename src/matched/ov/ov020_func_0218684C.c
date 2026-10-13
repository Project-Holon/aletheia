/*
 * function: FIELD_WFBC_DATA_LOCAL_GetItemPositionPair
 * address:  0x0218684C
 * packet:   pkt_0218684C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

char *FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(char *p, int i)
{
    return p + (i + 0xa) * 2;
}
