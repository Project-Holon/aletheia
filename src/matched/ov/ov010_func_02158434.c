/*
 * function: INTRUDE_COMM_GetReturnSlots
 * address:  0x02158434
 * packet:   pkt_ov010_02158434
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent.
 */

void *INTRUDE_COMM_GetReturnSlots(char *p)
{
    return p + 0x35C;
}
