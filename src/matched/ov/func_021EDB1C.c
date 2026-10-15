/*
 * function: BOX2_UI_DrawAllSlots
 * address:  0x021EDB1C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_UI_DrawSlot  0x021EDAB0  thumb  ov170
 *
 * Clear all 24 entries.
 */



extern void BOX2_UI_DrawSlot(char *p, int i);
void BOX2_UI_DrawAllSlots(int p)
{
    unsigned i;
    for (i = 0; i < 24; i++)
        BOX2_UI_DrawSlot((char *)p, i);
}
