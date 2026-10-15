/*
 * function: BOX2_SEQ_ShowHandSlots
 * address:  0x021ED2F4
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
 * Loop 8 entries forwarding (i+0x58, 1).
 */


extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
void BOX2_SEQ_ShowHandSlots(char *p)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        BOX2_SEQ_SetActorDrawEnable(p, i + 0x58, 1);
}
