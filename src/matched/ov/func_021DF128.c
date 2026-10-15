/*
 * function: BOX2_MAIN_HideSlots
 * address:  0x021DF128
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable  0x021EC000  thumb  ov170
 *
 * Seat the six 0x13 entries.
 */



extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
void BOX2_MAIN_HideSlots(int p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        BOX2_SEQ_SetActorDrawEnable((char *)p, i + 0x13, 0);
}
