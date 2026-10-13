/*
 * function: BTL_MAIN_GetSlotClientId
 * address:  0x021B8CFC
 * packet:   pkt_021B8CFC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

unsigned char BTL_MAIN_GetSlotClientId(char *p, int i)
{
    return *(unsigned char *)(p + i + 0x428);
}
