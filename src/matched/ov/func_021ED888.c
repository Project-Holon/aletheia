/*
 * function: BOX2_UI_ToggleSlotPair
 * address:  0x021ED888
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable  0x021EC000  thumb  ov170
 *
 * Release slots 0 and 1 of the 0x9E74 array.
 */


extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
void BOX2_UI_ToggleSlotPair(char *p, int a)
{
    BOX2_SEQ_SetActorDrawEnable(p, 0, a);
    BOX2_SEQ_SetActorDrawEnable(p, 1, a);
}
