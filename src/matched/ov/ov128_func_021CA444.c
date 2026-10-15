/*
 * function: WF2DMAP_TOUCH_ClearSlotArray
 * address:  0x021CA444
 * packet:   pkt_021CA444
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

void WF2DMAP_TOUCH_ClearSlotArray(char *p)
{
    unsigned int i;

    for (i = 0; i < 0x40; i++)
        *(unsigned int *)(p + i * 4 + 0x38) = 0;
}
