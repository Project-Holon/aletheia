/*
 * function: INTRUDE_COMM_GetPartnerRecord
 * address:  0x02176880
 * packet:   pkt_ov011_02176880
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: returns the address 0x82C bytes into the object.
 * Filed as the sole blocker of SYMBOL_MAP_GetSelection (ov010).
 *
 * symbols:
 */

typedef unsigned char u8;

u8 *INTRUDE_COMM_GetPartnerRecord(u8 *p)
{
    return p + 0x82C;
}
