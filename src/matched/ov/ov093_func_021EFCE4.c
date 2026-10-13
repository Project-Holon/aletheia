/*
 * function: BTL_FIELD_IsSlotInUse
 * address:  0x021EFCE4
 * packet:   pkt_021EFCE4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_FIELD_IsSlotInUse 0x021EFCE4 thumb
 */

typedef unsigned char u8;

void *BTL_FIELD_IsSlotInUse(char *arg0, int arg1)
{
    return *(void **)(arg0 + arg1 * 4 + 0x148);
}
