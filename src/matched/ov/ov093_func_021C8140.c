/*
 * function: BTL_SERVER_FLOW_GetSlotFlag
 * address:  0x021C8140
 * packet:   pkt_021C8140
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

unsigned char BTL_SERVER_FLOW_GetSlotFlag(char *p, int i)
{
    return *(unsigned char *)(p + i + 0x7d9);
}
